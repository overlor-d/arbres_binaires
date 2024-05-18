#include <stdio.h>
#include "bt_basics.h"
#include "bt_bst.h"


int main()
{
    printf("=======================\n");
    printf("Convert and Print Functions Test\n");

    bt_p *root = create_bt_p(40, 0, NULL, NULL, NULL);
    root->lc = create_bt_p(20, 0, NULL, NULL, NULL);
    root->rc = create_bt_p(60, 0, NULL, NULL, NULL);
    root->lc->lc = create_bt_p(10, 0, NULL, NULL, NULL);
    root->lc->rc = create_bt_p(30, 0, NULL, NULL, NULL);
    root->rc->lc = create_bt_p(50, 0, NULL, NULL, NULL);
    root->rc->rc = create_bt_p(70, 0, NULL, NULL, NULL);

    printf("Arbre BST avant la conversion :\n");
    print_hierarchical_bt_p(root);

    bt_t *converted_tree = convert_bt_p_to_tab(root);
    if (converted_tree == NULL)
    {
        printf("Échec de la conversion de l'arbre.\n");
        return 1;
    }

    printf("\nArbre après la conversion en format tableau :\n");
    print_bt_t(converted_tree);

    clear_bt_p(root);

    printf("=======================\n");
    return 0;
}
