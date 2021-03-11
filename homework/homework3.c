/* Made by Antonio Cortés */
#include<stdio.h> 
#include<ctype.h>
int main () {  
int a,b,c,all,skip=1,numb=0;
a=b=5;
	while ((c = getchar()) != EOF) {
	//pairs of sign
		if (c == '<') {                                //start CASE <...>
			all = 1;
			numb=1;
		}
		else if ((c == '>' || c == '\n') &&all == 1){ //end CASE <...>
			all = 2;
			numb=0;
		}
		if (c == '('){                              //start CASE (...)
			all = 3;
			numb=1;
		}
		else if ((c == ')' || c == '\n') && all == 3){ //end CASE (...)
			all = 4;
			numb=0;
		}
		if (c == '{'){                             //start CASE {...}
			all = 5;
			numb=1;
		}
		else if ((c == '}' || c == '\n') && all == 5){ //end CASE {...}
			all = 6;
			numb=0;
		}
		if (c == '[')  {                               //start CASE [...]
			all = 7;
			numb=1;
		}
		else if ((c == ']' || c == '\n') && all == 7){ //end CASE [...]
			all = 8;
			numb=0;
		}
		if (c == '"' && all<9) {                                //start CASE <...>
			all = 9;
			numb=1;
			}
		else if ((c == '"' || c == '\n') && all == 9){ //end CASE <...>
			all = 10;
			numb=0;
		}
		if (c == '\'' && all<11) {                              //start CASE <...>
			all = 11;
			numb=1;
		}
		else if ((c == '\'' || c == '\n') &&all == 11){ //end CASE <...>
			all = 12;
			numb=0;
		}
    //remove punctuation and prints
    if (c == ',' || c == '.' || c == '-'|| c == ':' || c == ';' || c == '?' || c == '!' || c == '_') 
			skip = 0;
		else 
			skip = 1;	
			if ((all % 2) != 0 && skip == 1)
			putchar (c);
	//changes the numbers to X
		if (c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0'&&(all%2)!=0){
			numb==1 ? :putchar('X');
			numb=1;
		}
			else if(skip==1&&(all%2)==0){
			putchar(c);
			numb=0;
			}
		} 
} 
/*Credits by colaboration with Rogelio Salinas and Autentic David*/
