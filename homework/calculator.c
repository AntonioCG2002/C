#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculator.h"

#define NUMBER '0' 
#define MAXVAL 100 
#define BUFSIZE 100

int rd = 0,bufp = 0; 
int var, ops, op1, op3;
char buf[BUFSIZE]; 
double val[MAXVAL]; 
double variables[1000];

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void push(double f) {
	if (rd < MAXVAL)
		val[rd++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
	if(op1 && var != 0) {
		if(variables[var] == 0 || op3 == 1) 
			variables[var] = f;
		else {
			printf("[Warning] There is already a value in the variable: %c\n", var);
			printf("Are you sure you want to change its value? 0.- NO 1.- YES\n");
			scanf("%i", &ops);
			if(ops)
				 variables[var] = f;
		}
	}		
}

double pop(void) {
	variables['$'] = val[rd - 1];
	if (rd > 0)
		return val[--rd];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
} 

int getop(char s[]) {
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
	if (isalpha(c)) {  //define the variables
		options(c, s);
	}
	
	if (c == ':') {
		c = getch();
		op3 = 1;
	}
	if (c == '=') {
		c = getch();
		op1 = 1;
	}
	if (c == '\n') {
		op1 = 0;
		op3 = 0;
	}
	
	if (!isdigit(c) && c != '.') //Obtain the number
		return c; 
	i = 0;
	if (isdigit(c)) 
		while (isdigit(s[++i] = c = getch()));
	if (c == '.') 
		while (isdigit(s[++i] = c = getch()));
			s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

int options(int c, char chars[]) {
	int i = 0, o;
	double op2, n = 0;
	chars[i] = c;
	while (isalpha(chars[++i] = c = getch()));
	chars[i] = '\0';
	ungetch(c);
	if(i == 1) 
		var = tolower(chars[0]);
	else 
		var = 0;
	if(i == 1 && variables[var] != 0 && var == chars[0])
		push(variables[var]);
	if(chars[0] == 'a' && chars[1] == 'n' && chars[2] == 's') {
		push(variables['$']);
		var = '$';
	}
	return chars[0];
}
//Credits by Rogelio Salinas