#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) {
  int datoMayor = arr[0];

  for (int i = 0; i < size; i++) {
    if (arr[i] > datoMayor) {
      datoMayor = arr[i];
    }
  }
  return datoMayor;
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
  int temp;
  for (int i = 0; i < size / 2; i++) {
    temp = arr[i];
    arr[i] = arr[size - i - 1];
    arr[size - i - 1] = temp;
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
void *filterEvenNumbers(int arr[], int size, int *newSize) {
  int nuevaTalla = 0;
  int *nuevoArr = malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0) {
      nuevoArr[nuevaTalla] = arr[i];
      nuevaTalla++;
    }
  }
  *newSize = nuevaTalla;
  return nuevoArr;
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,
                       int result[]) {
  int i = 0;
  int j = 0;
  int k = 0;

  while (i < size1 && j < size2) {
    if (arr1[i] < arr2[j]) {
      result[k] = arr1[i];
      i++;
      k++;
    } else {
      result[k] = arr2[j];
      j++;
      k++;
    }
  }
  while (i < size1) {
    result[k] = arr1[i];
    i++;
    k++;
  }
  while (j < size2) {
    result[k] = arr2[j];
    j++;
    k++;
  }
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) {
  int ordenAsc = 1;
  int ordenDesc = -1;

  for (int i = 0; i < size - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      ordenAsc = 0;
      break;
    }
  }

  for (int i = 0; i < size - 1; i++) {
    if (arr[i] < arr[i + 1]) {
      ordenDesc = 0;
      break;
    }
  }

  if (ordenDesc == -1)
    return -1;
  if (ordenAsc == 1)
    return 1;
  return 0;
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,
                      int anioNacimiento, int anioPublicacion) {
  strcpy(libro->titulo, titulo);
  strcpy(libro->autor.nombre, nombreAutor);
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion;
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) {
  Nodo *primero = NULL;
  Nodo *actual = NULL;

  for(int i = 0; i < size ; i++)
    {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->numero = arr[i];
    if (actual == NULL) {
      primero = nuevoNodo;
      actual = nuevoNodo;
    } else {
      actual->siguiente = nuevoNodo;
      actual = nuevoNodo;
    }
    nuevoNodo->siguiente = NULL;
    }
  return primero;
}
