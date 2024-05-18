#include "bt_bst.h"

#include <stdio.h>
#include <stdlib.h>

// Fonction de recherche

bt_p *search_bt_p(bt_p *T, int key)
{
    if (T == NULL || T->key == key)
    {
       return T;
    }

    if (T->key < key)
    {
       return search_bt_p(T->rc, key);
    }

    return search_bt_p(T->lc, key);
}

bt_p *search_verbose_bt_p(bt_p *T, int key)
{
    if (T == NULL)
    {
        return NULL;
    }

    printf("%d\n", T->key);

    if (key == T->key)
    {
        return T;
    }
    else if (key < T->key)
    {
        return search_verbose_bt_p(T->lc, key);
    }
    else
    {
        return search_verbose_bt_p(T->rc, key);
    }
}


bt_p *insert_leaf_bt_p(bt_p *T, int key, int len_elt, void *elt)
{
    if (T == NULL)
    {
        bt_p *new_node = malloc(sizeof(bt_p));
        if (new_node == NULL)
        {
            return NULL;
        }
        
        new_node->key = key;
        new_node->elt_size = len_elt;
        new_node->elt = elt;
        new_node->lc = NULL;
        new_node->rc = NULL;
        
        return new_node;
    }
    
    if (key < T->key)
    {
        T->lc = insert_leaf_bt_p(T->lc, key, len_elt, elt);
    }
    else if (key > T->key)
    {
        T->rc = insert_leaf_bt_p(T->rc, key, len_elt, elt);
    }

    return T;
}

bt_p *t_max(bt_p *node)
{
    while (node->rc != NULL)
    {
        node = node->rc;
    }
    return node;
}

bt_p *remove_node_bt_p(bt_p *T, int key)
{
    if (T == NULL)
    {
        return NULL;
    }

    if (key < T->key)
    {
        T->lc = remove_node_bt_p(T->lc, key);
    }
    else if (key > T->key)
    {
        T->rc = remove_node_bt_p(T->rc, key);
    }
    else
    {
        if (T->lc == NULL)
        {
            bt_p *temp = T->rc;
            free(T);
            return temp;
        }
        else if (T->rc == NULL)
        {
            bt_p *temp = T->lc;
            free(T);
            return temp;
        }

        bt_p *temp = t_max(T->lc); 
        T->key = temp->key;
        T->elt = temp->elt;
        T->elt_size = temp->elt_size;
        T->lc = remove_node_bt_p(T->lc, temp->key);
    }
    return T;
}

void print_bt_t(struct bt_t *T_tab)
{
    if (T_tab == NULL)
    {
        return;
    }
    
    for (int i = 0; i < T_tab->tab_used; ++i)
    {
        printf("%d\n", T_tab->keys[i]);
    }
}

void fill_array(bt_p *node, bt_t *tree, int index)
{
    if (node == NULL || index >= tree->tab_len) return;
    tree->keys[index] = node->key;
    tree->elts_size[index] = node->elt_size;
    tree->elts[index] = node->elt;
    tree->tab_used = index + 1;
    fill_array(node->lc, tree, 2 * index + 1);
    fill_array(node->rc, tree, 2 * index + 2);
}

bt_t *convert_bt_p_to_tab(bt_p *root)
{
    int height = height_bt_p(root);
    int size = (1 << height) - 1;

    bt_t *tree = malloc(sizeof(bt_t));
    if (tree == NULL) return NULL;

    tree->tab_len = size;
    tree->tab_used = 0;
    tree->keys = calloc(size, sizeof(int));
    tree->elts_size = calloc(size, sizeof(int));
    tree->elts = calloc(size, sizeof(void*));

    if (tree->keys == NULL || tree->elts_size == NULL || tree->elts == NULL)
    {
        free(tree->keys);
        free(tree->elts_size);
        free(tree->elts);
        free(tree);
        return NULL;
    }

    fill_array(root, tree, 0);
    return tree;
}

bt_p *insert_root_rot_bt_p(bt_p *T, int key, int len_elt, void *elt)
{
    if (T == NULL)
    {
        T = malloc(sizeof(bt_p));
        if (T == NULL)
        {
            return NULL;
        }
        T->lc = T->rc = NULL;
        T->key = key;
        T->elt_size = len_elt;
        T->elt = elt;
        return T;
    }

    if (key <= T->key)
    {
        T->lc = insert_root_rot_bt_p(T->lc, key, len_elt, elt);
        bt_p *new_root = T->lc;
        T->lc = new_root->rc;
        new_root->rc = T;
        T = new_root;
    }
    else
    { 
        T->rc = insert_root_rot_bt_p(T->rc, key, len_elt, elt);
        bt_p *new_root = T->rc;
        T->rc = new_root->lc;
        new_root->lc = T;
        T = new_root;
    }
    return T;
}

void split_tree(bt_p *T, int key, bt_p **left, bt_p **right)
{
    if (T == NULL)
    {
        *left = NULL;
        *right = NULL;
    } else if (key < T->key)
    {
        split_tree(T->lc, key, left, &T->lc);
        *right = T;
    } 
    else
    {
        split_tree(T->rc, key, &T->rc, right);
        *left = T;
    }
}

bt_p *insert_root_cut_bt_p(bt_p *T, int key, int len_elt, void *elt)
{
    bt_p *newRoot = malloc(sizeof(bt_p));
    if (newRoot == NULL)
    {
        return NULL;
    }
    newRoot->key = key;
    newRoot->elt_size = len_elt;
    newRoot->elt = elt;
    newRoot->lc = newRoot->rc = NULL;

    split_tree(T, key, &newRoot->lc, &newRoot->rc);

    return newRoot;
}
