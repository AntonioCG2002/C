#include <stdio.h>

int main () {
  int caracter;
  int x=7; 
  
    while(x==5){
  //Choose 5 and it's going to do ex.1-5 
    //Ex.1-5
     while((caracter =getchar ()) !=EOF){
     putchar(caracter);
     }
    }
    
    while(x==7){
  //Choose 7 and it's going to do ex.1-6 and 1-7
    //Ex.1-6, 1-7
     while((caracter =getchar ()) !=EOF){
   printf("Valor de la expresion: %d\n",caracter!=EOF);
   }
   printf("Valor de la expresion: %d\n",caracter!=EOF);
    printf("EOF es %d",caracter);
    }
  return 0;
}