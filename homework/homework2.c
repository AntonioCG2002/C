// CREATED BY ANTONIO CORTÉS
#include <stdio.h>
#define K  10   //How many numbers we want to put (CHANGE)
#define MAX 512 //Choose a number of bits that we want to put
/* 
How many bits we want
01 bit = 1	02 bits = 2		03 bits = 4		04 bits = 8 	05 bits = 16
06 bits = 32	07 bits = 64	08 bits = 128	09 bits = 256 	10 bits = 512
11 bits = 1024	12 bits = 2048	13 bits =4096	14 bits = 8192	15 bits = 16384
*/
int main (){   //obtain the prime numbers 'K'
	long a, i,count = 0,state = 0;
    unsigned long bits = MAX;
    printf(K <= 1 ? "The first prime number is:\n\n" :"The first %d prime numbers are\n\n", K);
	for(i = 2 ; count < K ;i++){
        state = 0;
		for(a = 2 ; a <= i ;a++){
		if(i % a == 0)
            state++;
	}
        if(state == 1){
		printf("\t%02d = ",i); 
        count++;
		state = 0 ;
      for(bits = MAX; bits > 0; bits >>= 1){
        if (bits & i)
            printf("1");
        else
            printf("0");
      }
      printf("\n");
    }
  }
}
/* References:
 Angellsd
 YouTube https://www.youtube.com/watch?v=s7QDOwakOLc
 YouTube https://www.youtube.com/watch?v=ykowfOF3gWw&t 
 */
