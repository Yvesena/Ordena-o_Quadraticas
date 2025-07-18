#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Troca arr[i] com arr[min_idx]
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Move elementos maiores que key para a direita
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <arquivo.txt> <selection|insertion>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int arr[MAX];
    int n = 0;

    // Ler números do arquivo
    while (fscanf(file, "%d", &arr[n]) == 1) {
        n++;
        if (n >= MAX) break;
    }
    fclose(file);

    clock_t start = clock();

    if (strcmp(argv[2], "selection") == 0) {
        selectionSort(arr, n);
    } else if (strcmp(argv[2], "insertion") == 0) {
        insertionSort(arr, n);
    } else {
        printf("Algoritmo inválido. Use 'selection' ou 'insertion'.\n");
        return 1;
    }

    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Imprime array ordenado
   /* printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }*/
    printf("\n");

    // Imprime tempo de ordenação
    printf("Tempo de ordenacao: %.6f segundos\n", time_taken);

    return 0;
}


