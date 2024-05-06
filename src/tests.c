#include <stdio.h>

#include "ds/list.h"
#include "ds/linkedlist.h"

int test_sorting() {
    int n;
    while (scanf("%d", &n) && n) {
        list *l = list_int_new();
        list *l2 = list_int_new();
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            list_append_int(l, x);
        }

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            list_append_int(l2, x);
        }

        list_sort(l, list_cmp_int);

        bool falhou = false;
        for (int i = 0; i < n && !falhou; i++) {
            if (list_get_int(l, i) != list_get_int(l2, i)) {
                printf("FALHOU\n");
                for (int j = 0; j < n; j++) {
                    printf("%d ", list_get_int(l, j));
                }
                printf("\n");
                falhou = true;
                break;
            }
        }
        
        if (!falhou) {
            printf("DEU CERTO\n");
        }
    }

    return 0;
}

int test_linkedlist() {
    linkedlist *ll = linkedlist_new(sizeof(int));

    int x = 13;
    printf("s %d\n", linkedlist_append(ll, &x));
    x = 2; printf("s %d\n", linkedlist_append(ll, &x));
    x = 8; printf("s %d\n", linkedlist_prepend(ll, &x));
    x = -9; printf("s %d\n", linkedlist_append(ll, &x));
    x = 17; printf("s %d\n", linkedlist_prepend(ll, &x));

    

    printf("d %d\n", ll->size);
    
    for (int i = 0; i < ll->size; i++) {
        llnode *n = linkedlist_get(ll, i);
        printf("%d ", *((int*)n->data));
    }
    printf("\n\n");

    printf("r %d\n", linkedlist_remove(ll, linkedlist_get(ll, 2)));
    printf("d %d\n", ll->size);

    for (int i = 0; i < ll->size; i++) {
        llnode *n = linkedlist_get(ll, i);
        printf("%d ", *((int*)n->data));
    }
    printf("\n");
}

int main() {
    //test_sorting();
    test_linkedlist();
}