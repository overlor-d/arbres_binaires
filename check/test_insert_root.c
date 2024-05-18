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
    printf("Root Insertion with Rotation Test\n");

    bt_p *root = NULL;

    int keysToInsert[] = {50, 40, 60, 30, 45, 55, 70};
    int numKeys = sizeof(keysToInsert) / sizeof(keysToInsert[0]);

    for(int i = 0; i < numKeys; i++)
    {
        printf("Insertion de la clé %d comme nouvelle racine\n", keysToInsert[i]);
        root = insert_root_rot_bt_p(root, keysToInsert[i], 0, NULL); 
        print_inorder(root); 
        printf("\n");
    }

    clear_bt_p(root);

    printf("=======================\n");
    return 0;
}
