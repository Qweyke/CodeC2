#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b)
{   
    if (*(double*)a == *(double*)b) return 0;
    return (*(double*)a > *(double*)b) ? 1 : -1;

}

void write_file(int n, double arr[], const char *path) 
{
    FILE *file;
    file = fopen(path, "w");

    if (file == NULL) {
        printf("Ошибка чтения файла"); 
        return;
    }
    qsort(arr, n, sizeof(double), compare);
    for (int i = 0; i < n; i++) 
        fprintf(file, "%.3lf ", arr[i]);
    fclose(file);
}

int main(int argc, char *argv[]) 
{
    if (argc <= 1) {
        printf("Не указан путь к файлу");
        return 1;
    }

    int i, n;
    double *arr;
    srand(time(NULL));
    printf("Введите размерность массива\n");
    scanf("%d", &n);
    arr = malloc(n * sizeof(double));
    
    if (arr == NULL) {
        printf("Ошибка выделения памяти массива");
        return 1;
    }
    printf("Ваш массив:");
    for (i = 0; i < n; i++) {
        arr[i] = (double)rand()/ (double)RAND_MAX;
        printf("%.3lf ", arr[i]);
    }
    printf("\n");
    write_file(n, arr, argv[1]);
    
    free(arr);

    return 0;
}