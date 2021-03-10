/* Made by Antonio Cortés */
#include<stdio.h> 
#include<ctype.h>
int main () {  
double c, all;
	while ((c = getchar()) != EOF) {
		if (c == '<')                                 //start CASE <...>
			all = 1;
		else if ((c == '>' || c == '\n') &&all == 1) //end CASE <...>
			all = 2;
		if (c == '(')                                 //start CASE (...)
			all = 3;
		else if ((c == ')' || c == '\n') && all == 3) //end CASE (...)
			all = 4;
		if (c == '{')                                 //start CASE {...}
			all = 5;
		else if ((c == '}' || c == '\n') && all == 5) //end CASE {...}
			all = 6;
		if (c == '[')                                 //start CASE [...]
			all = 7;
		else if ((c == ']' || c == '\n') && all == 7) //end CASE [...]
			all = 8;
		if (c == '"')                                 //start CASE <...>
			all = 9;
		else if ((c == '"' || c == '\n') && all == 9) //end CASE <...>
			all = 10;
		if (c == '\'')                                 //start CASE <...>
			all = 11;
		else if ((c == '\'' || c == '\n') &&all == 11) //end CASE <...>
			all = 12;
	if (ispunct(c)) //remove punctuation and prints
		putchar (c);	
	if (isdigit(c)) //chages the digits to X
		putchar ('X');		
	} 
} 
/*Credits by colaboration with Rogelio Salinas*/
