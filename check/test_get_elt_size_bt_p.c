#include <stdio.h>
#include <stdlib.h> 
#include "bt_basics.h"

void run_test(int condition, char* test_name)
{
    printf("%s -> %s\n", test_name, condition ? "\033[0;32mOK\033[0m" : "\033[0;31mFAILED\033[0m");
}

int main()
{
    printf("++++++++++++++++++++++\n");

    int sizes[10] = {1, 5, 10, 15, 20, 25, 30, 35, 40, 45};
    for (int i = 0; i < 10; i++)
    {
        void* element = malloc(sizes[i]);
        
        bt_p* node = create_bt_p(0, sizes[i], element, NULL, NULL);
        char test_name[100];
        sprintf(test_name, "Test %d: get_elt_size_bt_p avec taille %d", i+1, sizes[i]);
        run_test(get_elt_size_bt_p(node) == sizes[i], test_name);

        clear_bt_p(node);
        free(element);
    }
    printf("++++++++++++++++++++++\n");

    return 0;
}
