#include <stdio.h>   
#include <stdlib.h>  
#include <ctype.h>   
#include <assert.h>  
#include "function.h"

int minesnearby(int fila, int columna, char table[ROWS][COLUMNS]) {
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
      if (table[m][l] == MINA) 
        conteo++;
    }
  }
  return conteo;
}

int randomnumber(int minimo, int maximo) { //GIVE US A MINIMUM AND MAXIMUM NUMBER
  return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void starttable(char table[ROWS][COLUMNS]) {
  int l;
  for (l = 0; l < ROWS; l++) {
    int m;
    for (m = 0; m < COLUMNS; m++) 
      table[l][m] = SPACE_NOTOPEN;
  }
}

void putmina(int fila, int columna, char table[ROWS][COLUMNS]) { //PUT THE MINE IN THE SPECIFIC COORDINATE
  table[fila][columna] = MINA;
}

void putminas(char table[ROWS][COLUMNS]) { //PUT THE MINE IN THE RANDOM COORDINATE
  int l;
  for (l = 0; l < CANTIDAD_MINAS; l++) {
    int fila = randomnumber(0, ROWS - 1);
    int columna = randomnumber(0, COLUMNS - 1);
    putmina(fila, columna, table);
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

char intchar(int numero) { //CHANGE THE INT INTO CHAR
  return numero + '0';
}

void writetable(char table[ROWS][COLUMNS], int showmine) {
  imprimirEncabezado();
  int numero = 1, l, m;
  for (l = 0; l < ROWS; l++) {
    printf(" %2d   ", numero);
    numero++;
    char letra = 'A';
    for (m = 0; m < COLUMNS; m++) {
      char verdaderonum = SPACE_NOTOPEN;
      char numeroActual = table[l][m];
      if (numeroActual == MINA) {
        verdaderonum = SPACE_NOTOPEN;
      } else if (numeroActual == SPACE_OPEN) {
        int minasCercanas = minesnearby(l, m, table);
        verdaderonum = intchar(minasCercanas);
      }
      if (numeroActual == MINA && (DEBUG || showmine)) 
        verdaderonum = MINA;
    printf(" %c ", verdaderonum);
    }
    printf("\n");
  }
}

int Openbox(char columnaLetra, int fila, char table[ROWS][COLUMNS]) {
    int m, l;
  columnaLetra = toupper(columnaLetra);
  fila--;
  int columna = columnaLetra - 'A';
  assert(columna < COLUMNS && columna >= 0);
  assert(fila < ROWS && fila >= 0);
  if (table[fila][columna] == MINA) 
        return FIND_MINE;
  if (table[fila][columna] == SPACE_OPEN) 
        return ALREADY_OPEN;
  table[fila][columna] = SPACE_OPEN;
        return ANY;
}

int nobox(char table[ROWS][COLUMNS]) { //CHECK IF THE PLAYER WIN THE GAME
  int l,m;
  for (l = 0; l < ROWS; l++) {
    for (m = 0; m < COLUMNS; m++) {
      char actual = table[m][l];
      if (actual == SPACE_NOTOPEN) 
        return 0;
        }
  }
  return 1;
}
