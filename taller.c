#include <stdio.h>

// Definición de la estructura Estudiante
struct Estudiante {
    int codigo;
    float nota;
};

// Prototipos de funciones
float buscarNotaMaxima(struct Estudiante estudiantes[], int n);
float calcularPromedio(struct Estudiante estudiantes[], int n);
void selectionSortRecursivo(struct Estudiante estudiantes[], int n, int i);
void imprimirEstudiantes(struct Estudiante estudiantes[], int n);

// Función principal
int main() {
    // Lista de estudiantes predefinida
    struct Estudiante estudiantes[] = {
        {2024101, 4.5},
        {2024102, 3.2},
        {2024103, 3.8},
        {2024104, 4.0},
        {2024105, 2.9},
    };
    int n = sizeof(estudiantes) / sizeof(estudiantes[0]);
    
    int opcion;

    do {
        printf("\n=== Menu de Gestion Academica ===\n");
        printf("1. Buscar la Nota Maxima\n");
        printf("2. Calcular el Promedio del Curso\n");
        printf("3. Ordenar Codigos de Estudiantes\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                float notaMaxima = buscarNotaMaxima(estudiantes, n);
                printf("La nota maxima es: %.2f\n", notaMaxima);
                break;
            }
            case 2: {
                float promedio = calcularPromedio(estudiantes, n);
                printf("El promedio del curso es: %.2f\n", promedio);
                break;
            }
            case 3: {
                selectionSortRecursivo(estudiantes, n, 0);
                printf("Estudiantes ordenados por codigo:\n");
                imprimirEstudiantes(estudiantes, n);
                break;
            }
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}

// Función para buscar la nota máxima
float buscarNotaMaxima(struct Estudiante estudiantes[], int n) {
    if (n == 1) {
        return estudiantes[0].nota;
    }
    float maxNota = buscarNotaMaxima(estudiantes, n - 1);
    return (estudiantes[n - 1].nota > maxNota) ? estudiantes[n - 1].nota : maxNota;
}

// Función para calcular el promedio
float calcularPromedio(struct Estudiante estudiantes[], int n) {
    if (n == 0) {
        return 0;
    }
    return (estudiantes[n - 1].nota + (n - 1) * calcularPromedio(estudiantes, n - 1)) / n;
}

// Función recursiva para ordenar usando Selection Sort
void selectionSortRecursivo(struct Estudiante estudiantes[], int n, int i) {
    if (i >= n - 1) {
        return; // Caso base
    }

    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
        if (estudiantes[j].codigo < estudiantes[minIndex].codigo) {
            minIndex = j;
        }
    }

    // Intercambiar el estudiante actual con el mínimo encontrado
    struct Estudiante temp = estudiantes[i];
    estudiantes[i] = estudiantes[minIndex];
    estudiantes[minIndex] = temp;

    // Llamada recursiva para el siguiente índice
    selectionSortRecursivo(estudiantes, n, i + 1);
}

// Función para imprimir la lista de estudiantes
void imprimirEstudiantes(struct Estudiante estudiantes[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Codigo: %d, Nota: %.2f\n", estudiantes[i].codigo, estudiantes[i].nota);
    }
}