#include <stdio.h>   
#include <stdlib.h>  
#include <ctype.h>   
#include <assert.h>  
#include "function.h"

#define MINA_ENCONTRADA 1
#define ESPACIO_YA_DESCUBIERTO 2
#define NINGUNO 3
#define COLUMNS 10
#define ROWS 10
#define ESPACIO_SIN_DESCUBRIR '#'
#define ESPACIO_DESCUBIERTO '*'
#define MINA 'X'
#define CANTIDAD_MINAS 5
#define DEBUG 0  // IF YOU PUT 1 YOU CAN SEE THE MINES

int obtenerMinasCercanas(int fila, int columna, char tablero[ROWS][COLUMNS]) {
  int conteo = 0, filaInicio, filaFin, columnaInicio, columnaFin;
  if (fila <= 0) {
    filaInicio = 0;
  } else {
    filaInicio = fila - 1;
  }
  if (fila + 1 >= ROWS) {
    filaFin = ROWS - 1;
  } else {
    filaFin = fila + 1;
  }
  if (columna <= 0) {
    columnaInicio = 0;
  } else {
    columnaInicio = columna - 1;
  }
  if (columna + 1 >= COLUMNS) {
    columnaFin = COLUMNS - 1;
  } else {
    columnaFin = columna + 1;
  }
  int m;
  for (m = filaInicio; m <= filaFin; m++) {
    int l;
    for (l = columnaInicio; l <= columnaFin; l++) {
      if (tablero[m][l] == MINA) 
        conteo++;
    }
  }
  return conteo;
}

int aleatorioEnRango(int minimo, int maximo) { //GIVE US A MINIMUM AND MAXIMUM NUMBER
  return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void iniciarTablero(char tablero[ROWS][COLUMNS]) {
  int l;
  for (l = 0; l < ROWS; l++) {
    int m;
    for (m = 0; m < COLUMNS; m++) 
      tablero[l][m] = ESPACIO_SIN_DESCUBRIR;
  }
}

void colocarMina(int fila, int columna, char tablero[ROWS][COLUMNS]) { //PUT THE MINE IN THE SPECIFIC COORDINATE
  tablero[fila][columna] = MINA;
}

void colocarMinasAleatoriamente(char tablero[ROWS][COLUMNS]) { //PUT THE MINE IN THE RANDOM COORDINATE
  int l;
  for (l = 0; l < CANTIDAD_MINAS; l++) {
    int fila = aleatorioEnRango(0, ROWS - 1);
    int columna = aleatorioEnRango(0, COLUMNS - 1);
    colocarMina(fila, columna, tablero);
  }
}

void imprimirEncabezado() {
  printf("      ");
  char letra = 'A';
  int l;
  for (l = 0; l < COLUMNS; l++) {
    printf(" %c ", letra);
    letra++;
  }
  printf("\n");
}

char enteroACaracter(int numero) { //CHANGE THE INT INTO CHAR
  return numero + '0';
}

void imprimirTablero(char tablero[ROWS][COLUMNS], int deberiaMostrarMinas) {
  imprimirEncabezado();
  int numero = 1, l, m;
  for (l = 0; l < ROWS; l++) {
    printf(" %2d   ", numero);
    numero++;
    char letra = 'A';
    for (m = 0; m < COLUMNS; m++) {
      char verdaderonum = ESPACIO_SIN_DESCUBRIR;
      char numeroActual = tablero[l][m];
      if (numeroActual == MINA) {
        verdaderonum = ESPACIO_SIN_DESCUBRIR;
      } else if (numeroActual == ESPACIO_DESCUBIERTO) {
        int minasCercanas = obtenerMinasCercanas(l, m, tablero);
        verdaderonum = enteroACaracter(minasCercanas);
      }
      if (numeroActual == MINA && (DEBUG || deberiaMostrarMinas)) 
        verdaderonum = MINA;
    printf(" %c ", verdaderonum);
    }
    printf("\n");
  }
}

int abrirCasilla(char columnaLetra, int fila, char tablero[ROWS][COLUMNS]) {
    int m, l;
  columnaLetra = toupper(columnaLetra);
  fila--;
  int columna = columnaLetra - 'A';
  assert(columna < COLUMNS && columna >= 0);
  assert(fila < ROWS && fila >= 0);
  if (tablero[fila][columna] == MINA) 
        return MINA_ENCONTRADA;
  if (tablero[fila][columna] == ESPACIO_DESCUBIERTO) 
        return ESPACIO_YA_DESCUBIERTO;
  tablero[fila][columna] = ESPACIO_DESCUBIERTO;
        return NINGUNO;
}

int noHayCasillasSinAbrir(char tablero[ROWS][COLUMNS]) { //CHECK IF THE PLAYER WIN THE GAME
  int l,m;
  for (l = 0; l < ROWS; l++) {
    for (m = 0; m < COLUMNS; m++) {
      char actual = tablero[m][l];
      if (actual == ESPACIO_SIN_DESCUBRIR) 
        return 0;
        }
  }
  return 1;
}
