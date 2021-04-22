/*COPY AND PASTE THIS CODE IN ONLINE GDB IN 3 FILES 
AND RENAME EACH FILE AS
THE FIRST ONE: main.c 
THE SECOND: function.c
The THIRD: function.h*/

#include <stdio.h>   
#include <stdlib.h>  
#include <unistd.h>  
#include "function.h"

  char table[ROWS][COLUMNS], column;
  int Minas = 0,row;

int main() {
    printf("WELCOME TO THE MINESWEEPER GAME\n");
    printf("YOU NEED TO PUT A LETTER AND A NUMBER\n");
    printf("Example: A1, B2, C3, D4\n");
    printf("GOOD LUCK\n");
    printf("IF YOU WANT TO PLAY MORE HARD GO INTO function.h \n");
    printf("AND CHANGE HOW MANY MINES DO YOU WANT\n");
    srand(getpid());
    starttable(table);
    putminas(table);
    while (1) {
        writetable(table, Minas);
        if (Minas) 
            break;
    printf("WRITE A COLUMN AND A ROW: ");
    scanf(" %c", &column);
    scanf("%d", &row);
        printf("\n");
    int status = Openbox(column, row, table);
    if (nobox(table)) {
      printf("* YOU ARE A CRACK *\n");
      printf("YOU WON");
     Minas = 1;
    } else if (status == ALREADY_OPEN) {
      printf("YOU ALREADY OPEN THIS BOX\n");
    } else if (status == FIND_MINE) {
      printf("IM SORRY BUT YOU LOOSE :( \n");
      printf("TRY AGAIN\n");
      Minas = 1;
    }
  }
  return 0;
}
