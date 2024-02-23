#include <stdlib.h>
#include <stdio.h>

typedef struct elem
{
    int data;
    struct elem * previous;
} ELEM;

void push(ELEM** topn, int datat)
{
    ELEM* elems = malloc(sizeof(ELEM));
    elems->data = datat;
    elems->previous = *topn;
    *topn = elems;
    printf("An element %d has been aded\n", elems->data);
}

int pop(ELEM** topn)
{
    if (*topn == NULL){
        printf("\nThere are no elemets to pop\n");
        return -1;
    }
    printf("An element %d has been popped\n", (*topn)->data);
    int num = (*topn)->data;
    *topn = (*topn)->previous;
    return num;
}

void show(ELEM* topn)
{
    if (topn != NULL){
        printf("\nElement on top is %d", topn->data);
    }
    else printf("\nThere are no elements in stack right now\n");    
}


int main(void)
{
    ELEM* top = NULL;

    int choice, qnty, i;

    do{
        printf("\n1 - push; 2 - pop; 3 - show; 4 - stop.\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:           
            printf("\nInput desired quantity of elements to push\n");
            scanf("%d", &qnty);
            for (i = 1; i<=qnty; i++){
                push(&top, i);
            }
            break;

        case 2:           
            printf("\nInput desired quantity of elements to pop\n");
            scanf("%d", &qnty);
            for (i = 1; i<=qnty; i++){
                int value = pop(&top);
                if ( value != -1){
                    printf("Element %d has been popped\n", value);
                }             
            }
            break;
        
        case 3:           
            show(top);
            break;
        
        case 4:
            printf("\nExiting prog\n");
            while (top != NULL){
                pop(&top);
            }
            return 0;

        default:
            printf("\nIncorrect input, try again\n");
            break;
        }
    } while (choice != 4);
}
