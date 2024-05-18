#include <stdio.h>
#include "bt_basics.h"

void run_test(int condition, char* test_name) {
    printf("%s -> %s\n", test_name, condition ? "\033[0;32mOK\033[0m" : "\033[0;31mFAILED\033[0m");
}

int main() {
    printf("=======================\n");
    printf("Partie 4 : deepness_node_bt_p\n");

    bt_p *root = create_bt_p(1, 0, NULL, NULL, NULL);
    bt_p *leftChild = create_bt_p(2, 0, NULL, NULL, NULL);
    bt_p *rightChild = create_bt_p(3, 0, NULL, NULL, NULL);
    root->lc = leftChild;
    root->rc = rightChild;
    bt_p *leftLeftChild = create_bt_p(4, 0, NULL, NULL, NULL);
    leftChild->lc = leftLeftChild;

    run_test(deepness_node_bt_p(root, root) == 0, "Test 1: Profondeur de la racine");

    run_test(deepness_node_bt_p(root, leftChild) == 1, "Test 2: Profondeur d'un enfant direct");

    run_test(deepness_node_bt_p(root, leftLeftChild) == 2, "Test 3: Profondeur d'un enfant au deuxième niveau");


    clear_bt_p(root);

    printf("=======================\n");
    return 0;
}
