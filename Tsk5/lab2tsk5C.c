#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stack {
    int digit;
    struct stack *previous;
} STK;

STK* push(STK* top, int digit) 
{
    STK* elem = malloc(sizeof(STK));
    elem->previous = top;
    elem->digit = digit;
    return elem;
}

STK* pop(STK* top) 
{
    if (top == NULL) return top;
    STK* elem_now = top->previous;
    free(top);
    return elem_now;
}

STK* show(const STK* top)
{
    const STK* current = top;
    while (current != NULL) {
    printf("%d ", current->digit);
    current = current->previous;
    }
    
}

int main(int argc, char *argv[]) 
{
    STK* top = NULL;
    FILE *file;
    char *path = argv[1];
    file = fopen(path, "r");
    
    int chr;
    while ((chr = fgetc(file)) != EOF) {
        if (isdigit(chr)) {
            top = push(top, chr - '0');
        }
        else if (chr == '+' || chr == '-' || chr == '*' || chr == '/') {
            
            if (top == NULL) {
                printf("Операторы не введены\n");
                return 1;
            }

            show(top);
            printf("\n");

            int oper1 = top->digit;
            int oper2 = 0;
            top = pop(top);
            if (top != NULL) oper2 = top->digit;
            top = pop(top);
            int res;

            switch (chr) {
                case '+':
                res = oper1 + oper2;
                break;
                case '-':
                res = oper2 - oper1;
                break;
                case '*':
                res = oper1 * oper2;
                break;
                case '/':
                res = oper2 / oper1;
                break;
            }
            top = push(top, res);
            }
            else if (chr != ' ' && chr != '\n') {
                printf("Файл содержит некорректный тип символа: %c \n", chr);
                continue;
        }
    }
    fclose(file);
    
    if (top != NULL) printf("Ответ (убил): %d ", top->digit);
    else printf("Значений не было найдено");

    return 0;
}