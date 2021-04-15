#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculator.h"

#define MAXOP 1000 
#define NUMBER '0' 

//DEFINE THE VARIABLES
int type;
double cal2;
char s[MAXOP];

int main() {
	while ((type = getop(s)) != EOF) { //Check what im writting
		switch (type) {                //Choose the diffent case
			case NUMBER: push(atof(s));
			break;
			
			case '+': push(pop() + pop()); // Addition
			break;
			case '*': push(pop() * pop()); // Multiplication
			break;
			case '-': cal2 = pop(); //Substraction
			push(pop() - cal2);
			break;
			case '/': cal2 = pop(); // Division
				if (cal2 != 0.0) 
					push(pop() / cal2); 
				else
					printf("error: zero divisor\n");
			break;
					
			case '\n': printf("\t= %.8g\n", pop()); //END cases
			break;
			
			default: if(strlen(s) > 1 && (s[0] != 'a' && s[1] != 'n' && s[2] != 's'))
				printf("error: unknown command %s\n", s);
				break;
		}
	}
		return 0;
} 
//Credits by Rogelio Salinas