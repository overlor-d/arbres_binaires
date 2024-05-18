#include <stdio.h>
#include "bt_basics.h"
#include "bt_bst.h"

int main()
{
    printf("=======================\n");
    printf("Search Function Tests\n");

    bt_p *root = create_bt_p(40, 0, NULL, NULL, NULL);
    root->lc = create_bt_p(20, 0, NULL, NULL, NULL);
    root->rc = create_bt_p(60, 0, NULL, NULL, NULL);
    root->lc->lc = create_bt_p(10, 0, NULL, NULL, NULL);
    root->lc->rc = create_bt_p(30, 0, NULL, NULL, NULL);
    root->rc->lc = create_bt_p(50, 0, NULL, NULL, NULL); 
    root->rc->rc = create_bt_p(70, 0, NULL, NULL, NULL); 

    int keysToSearch[] = {20, 40, 60, 10, 30, 50, 70, 80};
    int numKeys = sizeof(keysToSearch) / sizeof(keysToSearch[0]);

    for(int i = 0; i < numKeys; i++)
    {
        bt_p *result = search_bt_p(root, keysToSearch[i]);
        if (result != NULL)
        {
            printf("Key %d found in the tree.\n", keysToSearch[i]);
        } 
        else
        {
            printf("Key %d not found in the tree.\n", keysToSearch[i]);
        }
    }

    clear_bt_p(root);

    printf("=======================\n");
    printf("=======================\n");
    printf("Verbose Search Function Tests\n");

    bt_p *root2 = create_bt_p(40, 0, NULL, NULL, NULL);
    root2->lc = create_bt_p(20, 0, NULL, NULL, NULL);
    root2->rc = create_bt_p(60, 0, NULL, NULL, NULL);
    root2->lc->lc = create_bt_p(10, 0, NULL, NULL, NULL);
    root2->lc->rc = create_bt_p(30, 0, NULL, NULL, NULL); 
    root2->rc->lc = create_bt_p(50, 0, NULL, NULL, NULL);
    root2->rc->rc = create_bt_p(70, 0, NULL, NULL, NULL); 

    int keysToSearch2[] = {20, 40, 60, 10, 30, 50, 70, 80};
    int numKeys2 = sizeof(keysToSearch2) / sizeof(keysToSearch2[0]);

    for(int i = 0; i < numKeys2; i++)
    {
        printf("\nRecherche de la clé %d :\n", keysToSearch2[i]);
        bt_p *result = search_verbose_bt_p(root2, keysToSearch2[i]);
        if (result != NULL) 
        {
            printf("La clé %d a été trouvée dans l'arbre.\n", keysToSearch2[i]);
        }
        else
        {
            printf("La clé %d n'a pas été trouvée dans l'arbre.\n", keysToSearch2[i]);
        }
    }

    clear_bt_p(root2);

    printf("=======================\n");
    return 0;
    return 0;
}


