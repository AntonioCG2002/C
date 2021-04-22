#include <stdio.h>   
#include <stdlib.h>  
#include <unistd.h>  
#include "function.h"

#define MINA_ENCONTRADA 1
#define ESPACIO_YA_DESCUBIERTO 2
#define NINGUNO 3
#define COLUMNS 10              //CHANGE THE NUMBER OF COLUMNS
#define ROWS 10                 //CHANGE THE NUMBER OF ROWS
#define ESPACIO_SIN_DESCUBRIR '#'
#define ESPACIO_DESCUBIERTO '*'
#define MINA 'X'
#define CANTIDAD_MINAS 5

int main() {
    printf("WELCOME TO THE MINESWEEPER GAME\n");
    printf("YOU NEED TO PUT A LETTER AND A NUMBER\n");
    printf("Example: A1, B2, C3, D4\n");
    printf("GOOD LUCK\n");
  char tablero[ROWS][COLUMNS];
  int deberiaMostrarMinas = 0;
  srand(getpid());
  iniciarTablero(tablero);
  colocarMinasAleatoriamente(tablero);
  while (1) {
    imprimirTablero(tablero, deberiaMostrarMinas);
    if (deberiaMostrarMinas) {
      break;
    }
    char columna;
    int fila;
    printf("WRITE A COLUMN AND A ROW: ");
    scanf(" %c", &columna);
    scanf("%d", &fila);
            printf("\n");
    int status = abrirCasilla(columna, fila, tablero);
    if (noHayCasillasSinAbrir(tablero)) {
      printf("* YOU ARE A CRACK *\n");
      printf("YOU WON");
      deberiaMostrarMinas = 1;
    } else if (status == ESPACIO_YA_DESCUBIERTO) {
      printf("YOU ALREADY OPEN THIS BOX\n");
    } else if (status == MINA_ENCONTRADA) {
      printf("IM SORRY BUT YOU LOOSE :( \n");
      printf("TRY AGAIN");
      deberiaMostrarMinas = 1;
    }
  }
  return 0;
}
