#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct elems {
    int digit;
    struct elems *previous;
} ELEM;

void push(ELEM** topn, int datat)
{
    ELEM* elems = malloc(sizeof(ELEM));
    elems->digit = datat;
    elems->previous = *topn;
    *topn = elems;
}

int pop(ELEM** topn)
{
    if (*topn == NULL){
        printf("\nThere are no elemets to pop\n");
        return -1;
    }
    int num = (*topn)->digit;
    *topn = (*topn)->previous;
    return num;
}

void show(const ELEM* topn)
{
    const ELEM* current = topn;
    while (current != NULL) {
        printf("\n %d", current->digit);
        current = current->previous;
    }
    
}

int main(int argc, char *argv[]) 
{
    ELEM* top = NULL;
    FILE *file;
    char *path = argv[1];
    file = fopen(path, "r");
    
    int chr;
    while ((chr = fgetc(file)) != EOF) {
        if (isdigit(chr)) {
            push(&top, chr - '0');
        }
        else if (chr == '+' || chr == '-' || chr == '*' || chr == '/') {
            
            if (top == NULL) {
                printf("\n Операторы не введены\n");
                return 1;
            }

            show(top);
            printf("\n");

            int oper1 = pop(&top);
            int oper2 = 0;
            if (top != NULL) oper2 = pop(&top);
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
            push(&top, res);
            }
            else if (chr != ' ' && chr != '\n') {
                printf("\n Файл содержит некорректный тип символа: %c \n", chr);
                continue;
        }
    }
    fclose(file);
    
    if (top != NULL) printf("\n Ответ (убил): %d \n", pop(&top));
    else printf("\n Значений не было найдено\n");

    return 0;
}