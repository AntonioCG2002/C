/* Made by Antonio Cortés */
#include<stdio.h> 
#include<ctype.h>
int main () {  
int a,b,c,all,skip,numb;
a=b=5;
	while ((c = getchar()) != EOF) {
	//pairs of sign
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
    //remove punctuation and prints
    if (c == ',' || c == '.' || c == '-'|| c == ':' || c == ';' || c == '?' || c == '!' || c == '_') //remove punctuation
			skip = 0;
		else 
			skip = 1;	
			if ((all % 2) != 0 && skip == 1)
			putchar (c);
	//changes the numbers to X
	if ((all % 2) == 0) { 
			if (isdigit(c))
				skip = a;
			if (!isdigit(c) && numb == b)
				numb = 1;
			if (skip == 1)
				putchar (c);
			else if (skip == a && numb != b) {
				putchar ('X');
				numb = b;
			}
		}
		} 
} 
/*Credits by colaboration with Rogelio Salinas*/
