#include <stdio.h>
#include "bt_basics.h"

void run_test(int condition, char* test_name)
{
    printf("%s -> %s\n", test_name, condition ? "\033[0;32mOK\033[0m" : "\033[0;31mFAILED\033[0m");
}

int main()
{

    bt_p *root = create_bt_p(1, 0, NULL, NULL, NULL);
    root->lc = create_bt_p(2, 0, NULL, NULL, NULL);
    root->rc = create_bt_p(3, 0, NULL, NULL, NULL);
    root->lc->lc = create_bt_p(4, 0, NULL, NULL, NULL);
    root->lc->rc = create_bt_p(5, 0, NULL, NULL, NULL);

    run_test(size_bt_p(root) == 5, "Test 1: Taille avec 5 nœuds");
    run_test(size_bt_p(root->lc) == 3, "Test 2: Taille du sous-arbre gauche avec 3 nœuds");
    run_test(size_bt_p(root->rc) == 1, "Test 3: Taille du sous-arbre droit avec 1 nœud");
    run_test(size_bt_p(NULL) == 0, "Test 4: Taille d'un arbre NULL");

    clear_bt_p(root);

    return 0;
}
