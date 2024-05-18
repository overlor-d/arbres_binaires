#include "bt_basics.h"
#include "queue.h"

#include <stdlib.h>
#include <stdio.h>

//include les lib de la file

bt_p *create_bt_p(int key, int elt_size, void *elt, bt_p *left_child, bt_p *right_child)
{
    bt_p *n = malloc(sizeof(bt_p));
    if (n == NULL)
    {
        return NULL;
    }

    n->key = key;
    n->elt_size = elt_size;
    n->elt = elt;
    n->lc = left_child;
    n->rc = right_child;

    return n;
}

// Fonction pour get des infos sur les noeuds de l'arbre

//------------------------

int get_key_bt_p(bt_p *node)
{
    if (node == NULL)
    {
        return -1;
    }
    return node->key; 
}

//------------------------

int get_elt_size_bt_p(bt_p *node)
{
    if (node == NULL)
    {
        return -1;
    }
    return node->elt_size;
}

//------------------------

void *get_elt_bt_p(bt_p *node) {
    if (node == NULL) {
        return NULL;
    }
    return node->elt;
}

// Fonction pour les calculs de tailles et de tous les autres trucs utiles pour les arbre basics

//------------------------

// On utilise une fonction annexe recurssive car cest mieux pour la recherche et en plus c'est plus simple
int annexe_deepness(bt_p *current, bt_p *c, int prof)
{
    if (current == NULL)
    {
        return -1;
    }
    if (current == c)
    {
        return prof;
    }
    int prof_g = annexe_deepness(current->lc, c, prof + 1);
    if (prof_g != -1)
    {
        return prof_g;
    }
    return annexe_deepness(current->rc, c, prof + 1);
}

int deepness_node_bt_p(bt_p *T, bt_p *node)
{
    if (T == NULL || node == NULL)
    {
        return -1;
    }
    return annexe_deepness(T, node, 0);
}

//------------------------

int size_bt_p(bt_p *T)
{
    if (T == NULL)
    {
        return 0;
    }
    return 1 + size_bt_p(T->lc) + size_bt_p(T->rc);
}

//------------------------

int height_bt_p(bt_p *T)
{
    if (T == NULL)
    {
        return -1;
    }
    int l_h = height_bt_p(T->lc);
    int r_h = height_bt_p(T->rc);

    if (l_h > r_h)
    {
        return l_h + 1;
    }
    return r_h + 1;
    
}

// Fonction d'affichage pour les dif mode de recherche vu et revu et rerevu en cours

//------------------------

void print_dfs_preorder_bt_p(bt_p *T)
{
    if (T == NULL)
    {
        return;
    }

    printf("%d\n", T->key);
    print_dfs_preorder_bt_p(T->lc);
    print_dfs_preorder_bt_p(T->rc);
}

//------------------------

void print_dfs_inorder_bt_p(bt_p *T)
{
    if (T == NULL) {
        return;
    }

    print_dfs_inorder_bt_p(T->lc);
    printf("%d\n", T->key);
    print_dfs_inorder_bt_p(T->rc);
}

//------------------------

void print_dfs_postorder_bt_p(bt_p *T)
{
    if (T == NULL)
    {
        return;
    }
    print_dfs_postorder_bt_p(T->lc);
    print_dfs_postorder_bt_p(T->rc);
    printf("%d\n", T->key);
}

// Pour afficher par niveau on utilise une pile module quil faudra importer avec le module quon avait fait au premier proj

//------------------------

// reprogrammation du module de queue vu quon peut meme pas utiliser celui quon a fait (vraiment super utile en tout cas)

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q)
    {
        q->front = q->rear = NULL;
    }
    return q;
}

void enqueue(Queue *q, bt_p *data)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode)
    {
        newNode->data = data;
        newNode->next = NULL;
        if (q->rear) q->rear->next = newNode;
        q->rear = newNode;
        if (q->front == NULL) q->front = newNode;
    }
}

bt_p *dequeue(Queue *q)
{
    if (q->front == NULL) return NULL;

    QueueNode *temp = q->front;
    bt_p *data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return data;
}

int isQueueEmpty(Queue *q)
{
    return q->front == NULL;
}

void clearQueue(Queue *q)
{
    while (!isQueueEmpty(q))
    {
        dequeue(q);
    }
    free(q);
}


void print_hierarchical_bt_p(bt_p *root)
{
    if (root == NULL) return;

    Queue *q = createQueue();
    enqueue(q, root);

    while (!isQueueEmpty(q))
    {
        bt_p *node = dequeue(q);
        printf("%d\n", node->key);

        if (node->lc != NULL) enqueue(q, node->lc);
        if (node->rc != NULL) enqueue(q, node->rc);
    }

    clearQueue(q);
}


//------------------------

int hierarchical_number_bt_p(bt_p *root, int key)
{
    if (root == NULL) return -1;

    int position = 1;
    Queue *q = createQueue();
    enqueue(q, root);

    while (!isQueueEmpty(q))
    {
        bt_p *node = dequeue(q);

        if (node->key == key)
        {
            clearQueue(q);
            return position;
        }

        if (node->lc != NULL) enqueue(q, node->lc);
        if (node->rc != NULL) enqueue(q, node->rc);

        position++;
    }

    clearQueue(q);
    return -1;
}


// liberation de larbre

int clearNode(bt_p *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int l_c = clearNode(node->lc);
    int r_c = clearNode(node->rc);
    
    free(node);
    
    return 1 + l_c + r_c;
}

int clear_bt_p(bt_p *T)
{
    int boissier = clearNode(T);
    return boissier;
}
