#include <stdio.h>
#include "bt_basics.h"

int main()
{
    printf("=======================\n");
    printf("DFS Print Functions Test\n");

    bt_p *root = create_bt_p(1, 0, NULL, NULL, NULL);
    root->lc = create_bt_p(2, 0, NULL, NULL, NULL);
    root->rc = create_bt_p(3, 0, NULL, NULL, NULL);
    root->lc->lc = create_bt_p(4, 0, NULL, NULL, NULL);
    root->lc->rc = create_bt_p(5, 0, NULL, NULL, NULL);
    root->rc->lc = create_bt_p(6, 0, NULL, NULL, NULL);
    root->rc->rc = create_bt_p(7, 0, NULL, NULL, NULL);

    printf("\nPreorder Print Test:\n");
    print_dfs_preorder_bt_p(root);

    printf("\nInorder Print Test:\n");
    print_dfs_inorder_bt_p(root);

    printf("\nPostorder Print Test:\n");
    print_dfs_postorder_bt_p(root);

    clear_bt_p(root);

    printf("=======================\n");

    printf("=======================\n");
    printf("Hierarchical Functions Test\n\n");

    bt_p *root2 = create_bt_p(1, 0, NULL, NULL, NULL);
    root2->lc = create_bt_p(2, 0, NULL, NULL, NULL);
    root2->rc = create_bt_p(3, 0, NULL, NULL, NULL);
    root2->lc->lc = create_bt_p(4, 0, NULL, NULL, NULL);
    root2->lc->rc = create_bt_p(5, 0, NULL, NULL, NULL);
    root2->rc->lc = create_bt_p(6, 0, NULL, NULL, NULL);
    root2->rc->rc = create_bt_p(7, 0, NULL, NULL, NULL);

    printf("Hierarchical Print Test:\n");
    print_hierarchical_bt_p(root2);

    printf("\nHierarchical Number Tests:\n");
    for(int i = 1; i <= 7; i++)
    {
        printf("Hierarchical number for node with key %d: %d\n", i, hierarchical_number_bt_p(root2, i));
    }

    clear_bt_p(root2);

    printf("=======================\n");
    return 0;
}
