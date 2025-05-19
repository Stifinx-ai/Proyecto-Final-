#include <stdio.h>
#include <stdlib.h>

#define BEBIDAS 8

void mostrarMenuBebidas() {
    printf("=== Menú de Bebidas ===\n");
    printf("0 - Agua natural\n");
    printf("1 - Refresco\n");
    printf("2 - Vino\n");
    printf("3 - Cerveza\n");
    printf("4 - Whisky\n");
    printf("5 - Licores\n");
    printf("6 - Energéticos\n");
    printf("7 - Combinados\n");
    printf("-1 - Terminar entrada para este pueblo\n");
}

void llenarMatriz(int **arr, int pueblos) 
{
    int bebida, litros;
    for (int i = 0; i < pueblos; i++)
    {
        printf("\n--- Pueblo #%d ---\n", i + 1);
        mostrarMenuBebidas();
        printf("Elige una bebida: ");
        scanf("%d", &bebida);
        while (bebida != -1) 
        {
            if (bebida >= 0 && bebida < BEBIDAS) 
            {
                printf("¿Cuántos litros consumieron?: ");
                scanf("%d", &litros);
                arr[i][bebida] += litros;
            } else {
                printf("Opción inválida.\n");
            }
            printf("Elige otra bebida o -1 para terminar: ");
            scanf("%d", &bebida);
        }
    }
}
void bebidaMasPopular(int **arr, int pueblos) 
{
    int total[BEBIDAS] = {0};
    for (int i = 0; i < pueblos; i++) 
    {
        for (int j = 0; j < BEBIDAS; j++) 
        {
            total[j] += arr[i][j];
        }
    }

    int max = 0, bebida = 0;
    for (int i = 0; i < BEBIDAS; i++) 
    {
        if (total[i] > max) 
        {
            max = total[i];
            bebida = i;
        }
    }

    printf("\nLa bebida más popular es la #%d con %d litros.\n", bebida, max);
}
void puebloBorracho(int **arr, int pueblos) 
{
    int maxLitros = 0, puebloBorracho = 0;
    for (int i = 0; i < pueblos; i++) 
    {
        int suma = 0;
        for (int j = 2; j <= 7; j++) 
        { 
            suma += arr[i][j];
        }
        if (suma > maxLitros) 
        {
            maxLitros = suma;
            puebloBorracho = i;
        }
    }

    printf("El pueblo más borracho es el #%d con %d litros de alcohol.\n",
           puebloBorracho + 1, maxLitros);
}

int main() 
{
    int pueblos;

    printf("¿Cuántos pueblos quieres analizar?: ");
    scanf("%d", &pueblos);

    int **arr = (int **)malloc(pueblos * sizeof(int *));
    for (int i = 0; i < pueblos; i++) 
    {
        arr[i] = (int *)calloc(BEBIDAS, sizeof(int));
    }

    llenarMatriz(arr, pueblos);
    bebidaMasPopular(arr, pueblos);
    puebloBorracho(arr, pueblos);
  
    for (int i = 0; i < pueblos; i++) 
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
