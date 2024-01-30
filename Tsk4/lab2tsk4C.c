#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack* previous;
} STK; 

STK* push(STK* top, int data) 
{
    STK* elem = malloc(sizeof(STK));
    elem->data = data;
    elem->previous = top; 
    printf("Добавлен элемент %d\n \n", elem->data);
    return elem;
}

STK* pop(STK* top)
{
    if (top == NULL) {
        printf("Нет элементов в стеке\n \n");
        return top;
    }

    printf("Извлечен объект %d\n \n", top->data);
    STK* elem_ntop = top->previous;
    free(top);
    return elem_ntop;
}

int main(void) 
{
    int n, i, c, choice;
    STK* top = NULL;

    do {

        printf("Выберите вариант действия:\n \n");
        printf("1 - добавить элемент(ы);\n");
        printf("2 - снять элемент(ы);\n");
        printf("3 - посмотреть верхушку;\n");
        printf("4 - выход\n \n");
        scanf(" %d", &choice);

        switch(choice) {
            case 1:
                printf("Сколько элементов необходимо добавить в стэк:\n");
                scanf("%d", &n);
                printf("\n");
                for (i = 1; i <= n; i++) {
                    top = push(top,i);
                }
                break;

            case 2:
                printf("Сколько элементов хотите извлечь? \n");
                scanf("%d", &n);
                printf("\n");
                for (i = 1; i <= n; i++) {
                    top = pop(top);
                }
                break;

            case 3:
                printf("\n");
                if (top == NULL){
                    printf("Объектов нет\n");
                    return 0;
                }
                printf("Объект %d \n", top->data);
                break;

            case 4:
                printf("\n");
                printf("Завершение программы\n");
                break;

            default:
                printf("\n");
                printf("Некорректиный выбор, попробуйте еще раз");
        }
    } while(choice != 4);
    
    return 0;
}