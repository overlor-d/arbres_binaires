#include <stdio.h>
#include "bt_basics.h"

void run_test(int condition, char* test_name) {
    printf("%s -> %s\n", test_name, condition ? "\033[0;32mOK\033[0m" : "\033[0;31mFAILED\033[0m");
}

int main() {
    printf("++++++++++++++++++++++\n");

    int keys[10] = {1, 5, -1, 100, 50, 0, 999, -999, 123456, -123456};
    for (int i = 0; i < 10; i++) {
        bt_p* node = create_bt_p(keys[i], 0, NULL, NULL, NULL);
        char test_name[100];
        sprintf(test_name, "Test %d: get_key_bt_p avec clé %d", i+1, keys[i]);
        run_test(get_key_bt_p(node) == keys[i], test_name);

        clear_bt_p(node);
    }

    printf("++++++++++++++++++++++\n");
    return 0;
}
