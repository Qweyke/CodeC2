#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define NAME_LENGHT 30

struct goods {
        char name[NAME_LENGHT];
        double price;
    };


int compare(const void *a, const void *b)
{
     double diff = ((struct goods *)a)->price - ((struct goods *)b)->price;

    if (diff > DBL_EPSILON) {
        return 1;
    } else if (diff < -DBL_EPSILON) {
        return -1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) 
{   
    if (argc < 2) {
        if (argc = 1){
            printf("Путь к файлам не указан");
            return 1;
        }
        printf("Путь к файлу 2 не указан");
        return 1; 
    }

    FILE *file_in, *file_out;
    char *path1 = argv[1];
    char *path2 = argv[2];
    file_in = fopen(path1, "r");
    
    if (file_in == NULL){
        printf("Ошибка чтения файла\n");
        return 1;
    }

    int n, cnt, previous = '\n';
    while ((n = fgetc(file_in)) != EOF) {
        if (previous == '\n') cnt++;
        previous = n;
    }

    rewind(file_in);
    
    struct goods *goods_l = ((struct goods*) malloc(cnt *sizeof(struct goods)));
    
    int i = 0;
    while (fscanf(file_in, "%s %lf", goods_l[i].name, &(goods_l[i].price)) != EOF) {
        printf("%s %.2lf\n", goods_l[i].name,goods_l[i].price);
        i++;
    }
    
    fclose(file_in);

    file_out = fopen(path2,"w");
    if (file_out == NULL) {
        printf("Ошибка чтения файла 2");
        return 0;
    }

    printf("\n");

    qsort(goods_l, cnt, sizeof(struct goods), compare);
    for (int j = 0; j < cnt; j++) {
        fprintf(file_out, "%s %.2lf\n", goods_l[j].name,goods_l[j].price);   
    }

    free(goods_l);
    fclose(file_out);
    printf("Файл успешно отсортирован\n");

    return 0;
}