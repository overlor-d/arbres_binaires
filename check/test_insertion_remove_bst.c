#include <stdio.h>
#include "bt_basics.h"
#include "bt_bst.h"

void print_inorder(bt_p *node)
{
    if (node == NULL)
    {
        return;
    }
    print_inorder(node->lc);
    printf("%d ", node->key);
    print_inorder(node->rc);
}

int main()
{
    printf("=======================\n");
    printf("Insert and Remove Functions Test\n");

    bt_p *root = NULL;

    printf("\nTest d'insertion :\n");
    int keysToInsert[] = {40, 20, 60, 10, 30, 50, 70};
    int numKeysToInsert = sizeof(keysToInsert) / sizeof(keysToInsert[0]);
    for(int i = 0; i < numKeysToInsert; i++)
    {
        printf("Insertion de la clé %d\n", keysToInsert[i]);
        root = insert_leaf_bt_p(root, keysToInsert[i], 0, NULL);
        print_inorder(root);
        printf("\n");
    }

    printf("\nTest de suppression :\n");
    int keysToRemove[] = {20, 60};
    int numKeysToRemove = sizeof(keysToRemove) / sizeof(keysToRemove[0]);
    for(int i = 0; i < numKeysToRemove; i++)
    {
        printf("Suppression de la clé %d\n", keysToRemove[i]);
        root = remove_node_bt_p(root, keysToRemove[i]);
        print_inorder(root);
        printf("\n");
    }

    clear_bt_p(root);

    printf("=======================\n");
    return 0;
}
