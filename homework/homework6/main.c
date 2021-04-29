//USE ONLINE GDB AND COMPILE IN 2 FILES main.c AND help.h
// Code made by Rogelio, and helped by Majo and Dany
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"help.h"
#define LIM 100

int main() {
	node* n = NULL;
	node* tree = NULL; 
	
	int i = 0, j = 0, count = 0;
	char c;
	char username[LIM];
	char password[LIM];
	char line[LIM];
	char type[LIM];
	printf("WELCOME TO EVERYONE\n");
	printf("You need to write: add, delete\n");
	printf("How it's work:\n");
	printf("add user password\t delete user password\n");
	
	while(1) {
    i = 0, j = 0;
	while(i<LIM-1&&(c = getchar()) != EOF && c != '\n') {
		line[i++] = c;
		if(isspace(c))
			count++;
		}
		line[i] = '\0';

	if(count >= 2) {
	i = getdata(type, line);
	i += getdata(username, line+i);
	i += getdata(password, line+i);
		}
    if(strstr(type, "add") && username && password) {
    n = insert(username, password, tree);
    if (tree == NULL)
    tree = n;
        show(tree);
    }
    else if (strstr(type, "delete")){
        count=0;
		    if (count!=2){
			printf("the user has been deleted\n");
		    }
    }
    else if (strstr(type, "show")){ // if we found  "show" we need to show
      count=0;
      show(tree);
      }
	
	 }
	}


void show(node* position) {
	
	if (position != NULL) {
    printf("The user is %s\b and the password is %s\n", position->name, position->password);
    printf("\n");
	return;
}
}

 void alpha(node* position) {

  if (position != NULL) {
    alpha(position->left);
        if (position->password!=NULL){
            printf(" <%s> ", position->name);
        }
    alpha(position->right);
  }
}

node *insert(char *name, char *password, node* pos) {
		node* temp;
	if (pos == NULL) {
		pos = (node*)malloc(sizeof(node));
    	pos->name = name;
    	pos->password = password;
	} else if(pos->right == NULL) {
		pos->right = (node*)malloc(sizeof(node));
    	pos->name = name;
    	pos->password = password;
	} else if(pos->left == NULL) {
		pos->left = (node*)malloc(sizeof(node));
    	pos->name = name;
    	pos->password = password;
}
    printf("User succesfully added\n");
	return pos;
}

int getdata(char *user, char *line) {
	int i = 0, j = 0;
	if(isspace(line[0]))
		while(isspace(line[++i]));
	while(!isspace(line[i]))
		user[j++] = line[i++];
	user[i] = '\0';
		return i;
}
