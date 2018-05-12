#include <stdio.h>
#include <stdlib.h>
#include "headers/abb.h"
#include "headers/avl.h"

FILE* open_file(char* path, char* mode);
void quick_sort(int *v, int size);

int main () {

    FILE* abbValues = open_file("abb.txt", "w");
    FILE* avlValues = open_file("avl.txt", "w");
    FILE* searchValue = open_file("search.txt", "w");

    struct binary_tree_avl* AVL = create_empty_binary_tree_avl();
    struct binary_tree* ABB = create_empty_binary_tree();

    int i;
    int quantValuesToAdd, intervalToSearch;

    printf("Adicionar quantos valores: ");
    scanf("%d", &quantValuesToAdd);

    for (i = 0; i <= quantValuesToAdd; ++i) {
        printf("Adicionando < %d >\n", i);
        ABB = add(ABB, i);
        AVL = add_avl(AVL, i);
    }

    printf("\nIntervalo da busca: ");
    scanf("%d", &intervalToSearch);

    int comparisons, j;

    int arrSize = quantValuesToAdd/intervalToSearch;
    int avlArray[arrSize];

    for (i = 0, j = 0; i < quantValuesToAdd; i += intervalToSearch, ++j) {
        printf("Buscando < %d >\n", i);

        fprintf(searchValue, "%d\n", i);

        comparisons = 0;
        search(ABB, i, &comparisons);

        fprintf(abbValues, "%d\n", comparisons);

        comparisons = 0;
        search_avl(AVL, i, &comparisons);
        avlArray[j] = comparisons;
    }

    quick_sort(avlArray, arrSize);

    for (i = 0; i < arrSize; ++i) {
        fprintf(avlValues, "%d\n", avlArray[i]);
    }

    printf("\n");

    printf("\nArquivos Gerados... OK\n");
    printf("Finalizado......... OK\n");

    fclose(abbValues);
    fclose(avlValues);
    fclose(searchValue);

    free(abbValues);
    free(avlValues);
    free(searchValue);

    system("pause");
    return 0;
}

FILE* open_file(char* path, char* mode) {

    FILE *f = fopen(path, mode);

    if (f == NULL) {
        printf("Error opening file %s.\n", path);
        exit(1);
    }

    return f;
}

void quick_sort(int *v, int size) {

    if (size <= 1) {
        return;
    } else {
        int pivot = v[size / 2];
        int a = 0;
        int b = size - 1;
        while (a < b) {
            while (v[a] < pivot) a++;
            while (v[b] > pivot) b--;
            if (a < b) {
                int aux = v[a];
                v[a] = v[b];
                v[b] = aux;
                ++a;
            }
        }
        quick_sort(v, b);
        quick_sort(v+a, size - a);
    }
}