#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void write_file(int n, int arr[], const char *path) 
{
    FILE* file;
    file = fopen(path,"w");
    
    if (file == NULL){
        printf("Ошибка чтения файла\n");
        return;
    }

    for(int i = n-1; i >= 0; i--) 
        fprintf(file, "%d ", arr[i]);
    fclose(file);

}

int main(int argc, char* argv[])   
{
    if (argc <= 1) {
        printf("Путь к файлу не указан, программа завершила действие");
        return 1;
    }

    int n, *arr;
    srand(time(NULL));
    printf("Введите размерность желаемого массива\n");
    scanf("%d", &n);  
    
    arr = malloc(n * sizeof(n));

    if (arr == NULL) {
            printf("Ошибка при выделении памяти\n");
            return 1;
    }

    printf("Ваш массив:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() %100;
        printf("%d ", arr[i]);
    }

    write_file(n, arr, argv[1]);
    free (arr);

    return 0;
}