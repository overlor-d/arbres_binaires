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


    for (int i = 0; i < 10; i++)
    {
        int* element = malloc(sizeof(int));
        *element = i; 
        
        bt_p* node = create_bt_p(0, sizeof(int), element, NULL, NULL);
        char test_name[100];
        sprintf(test_name, "Test %d: get_elt_bt_p avec élément de valeur %d", i+1, i);
        run_test(get_elt_bt_p(node) == element, test_name);

        clear_bt_p(node); 
        free(element); 
    }

    printf("++++++++++++++++++++++\n");

    return 0;
}
