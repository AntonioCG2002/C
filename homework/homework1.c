#include <stdio.h> // Input and Output
#include <string.h> // strstr
#include <ctype.h>
#define MAX 100 //Number of spaces in the char[]
void nosign(char line[MAX], char noline[MAX]);
/* Function that eliminate < > (input, output) */
void nospace(char line [MAX], char noline[MAX]);
/* Function that change the \t and ' '  by _ (input, output)  */
void strong(char line [MAX], char nomarks[MAX]);
/*Function that search <strong> and <\strong> to change the \t and ' '  by _ (input, output) */
char line[MAX], noline[MAX];
/*line completa, salida)*/
int saca(); // Function that give us the line

int main() {
  extern char line[];
  char noline[MAX], nomarks[MAX], nostrong[MAX];
  int ignore = 0, ignoretable = 0, ignoreimg = 0, ignoreforms =0, spaces = 0, l = 0;

    while ((l = saca()) == 0) {
        if (strstr(line, "<form") != NULL) 
            ignoreforms = 1;
    // if we found  "<Form" ignore
    if (strstr(line, "<table") != NULL) 
            ignoretable = 1;
    // if we found  "<table" ignore
    if (strstr(line, "<script") != NULL) 
            ignore = 1;
    // if we found  "<script" ignore
    if (strstr(line, "<img") != NULL) 
            ignoreimg = 1;
    // if we found  "<img" ignore
    if (strstr(line, "<div") != NULL) 
            ignore = 1;
    // if we found  "<div" ignore
    if (!ignoretable&&!ignoreforms&&!ignoreimg && !ignore && strstr(line, "<html>") == NULL && strstr(line, "<body>") == NULL && strstr(line, "</html>") == NULL && strstr(line, "</body>") == NULL) {

    if (strstr(line, "<h1") != NULL || strstr(line, "<h2") != NULL || strstr(line, "<h3") != NULL ||  strstr(line, "<h4") != NULL || strstr(line, "<h5") != NULL  || strstr(line, "<h6") != NULL  ) {
        nospace(line,noline);
        nosign(noline, nomarks);
            printf("%s\n", nomarks);
}
    else if (strstr(line, "<strong>") != NULL) {
        strong(line, nostrong);
        nosign(nostrong,nomarks);
            printf("%s\n", nomarks);
    }
    else{
        nosign(line,nomarks);
            printf("%s\n", nomarks);
    }
    }
    if (strstr(line, "</script>") != NULL)  // if we found  "</script>" stop ignoring
        ignore = 0;
    if (strstr(line, "</div>") != NULL) // if we found  "</div>" stop ignoring
        ignore = 0;
    if (strstr(line, ">") != NULL) // if we found  ">" stop ignoring 
        ignoreimg = 0;
    if (strstr(line, "</form>") != NULL) // if we found  "</form>" stop ignoring
        ignoreforms = 0;
    if (strstr(line, "</table>") != NULL) // if we found  "</table>" stop ignoring
        ignoretable = 0;
  }
  return 0;
}

// Function that give us the line
int saca() { 
    extern char line[];
        int c, i = 0;
    for (; i < MAX - 1 && (c = getchar()) != EOF && c != '\n';) 
        line[i++] = c;
        line[i] = '\0'; // caracter end of string
    return c == EOF;
    }
    
/* Function that change the \t and ' '  by "_"
When we have cadena to input we use that formula to have a cadenasin in output*/
void nospace(char cadena [MAX], char cadenasin[MAX]) {
    int a;
        for (a=0;a<MAX;a++){ /*Read  the string, one by one */
        if (cadena[a] != ' '&& cadena[a] != '\t')
            cadenasin[a] = cadena[a];
        else
            cadenasin[a]= '_';
}
}
/* Function that eliminate <...> (input, output) */
void nosign(char cadena[MAX], char cadenasin[MAX]){
    int a,b=0,c=0;
        for (a=0;a<MAX;a++){
        if (cadena[a]=='<')
            c++;
        if (cadena[a]=='>')
            c--;
        if (cadena[a]!='>'&&cadena[a]!='<'&&c!=1){
            cadenasin[b]=cadena[a];
            b++;
    }
}
}

/*Function that search <strong> and <\strong> to change the \t and ' '  by _ (input, output) */
void strong(char cadena[MAX], char cadenasin[MAX]){
    int a,c=0;
    for (a=0;a<MAX;a++){
        if (cadena[a]=='<'&&cadena[a+1]=='s'&&cadena[a+2]=='t'&&cadena[a+3]=='r'&&cadena[a+4]=='o'&&cadena[a+5]=='n'&&cadena[a+6]=='g'&&cadena[a+7]=='>')
            c = 1;
        if (cadena[a]=='<'&&cadena[a+1]=='\\'&&cadena[a+2]=='s'&&cadena[a+3]=='t'&&cadena[a+4]=='r'&&cadena[a+5]=='o'&&cadena[a+6]=='n'&&cadena[a+7]=='g'&&cadena[a+7]=='>')
            c = 0;
        if (c==1){
        if (cadena[a] != ' '&& cadena[a] != '\t')
            cadenasin[a] = cadena[a];
        else
            cadenasin[a]= '_';
        }
        if (c==0)
            cadenasin[a]=cadena[a];
}
}
/* References:
Teacher: Elisa 
Angel Raul Chavez (rulgamer07)
Maria José 
Angel David Soria Gonzalez(AuthenticDavid)
Daniela Rodriguez
Héctor Martínez */
