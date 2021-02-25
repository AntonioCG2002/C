#include <stdio.h> // Input and Output
#include <string.h> // strstr
#define MAX 100 //Number of spaces in the char[]
void quitaparentesis(char linea[MAX], char lineasin[MAX]);
/* Function that eliminate < > (input, output) */
void quitaespacios(char linea [MAX], char lineasin[MAX]);
/* Function that change the \t and ' '  by _ (input, output)  */
void strong(char linea [MAX], char lineasinetiquetas[MAX]);
/*Function that search <strong> and <\strong> to change the \t and ' '  by _ (input, output) */
char linea[MAX], lineasin[MAX];
/*linea completa, salida)*/
int saca(); // Function that give us the line

int main() {
  extern char linea[];
  char lineasin[MAX], lineasinetiquetas[MAX], lineasinespacios[MAX], lineasinstrong[MAX];
  int ignore = 0, ignoretable = 0, ignoreimg = 0, ignoreforms =0, spaces = 0, l = 0;

    while ((l = saca()) == 0) {
        if (strstr(linea, "<form") != NULL) 
            ignoreforms = 1;
    // if we found  "<Form" ignore
    if (strstr(linea, "<table") != NULL) 
            ignoretable = 1;
    // if we found  "<table" ignore
    if (strstr(linea, "<script") != NULL) 
            ignore = 1;
    // if we found  "<script" ignore
    if (strstr(linea, "<img") != NULL) 
            ignoreimg = 1;
    // if we found  "<img" ignore
    if (strstr(linea, "<div") != NULL) 
            ignore = 1;
    // if we found  "<div" ignore
    if (!ignoretable&&!ignoreforms&&!ignoreimg && !ignore && strstr(linea, "<html>") == NULL && strstr(linea, "<body>") == NULL && strstr(linea, "</html>") == NULL && strstr(linea, "</body>") == NULL) {

    if (strstr(linea, "<h1") != NULL || strstr(linea, "<h2") != NULL || strstr(linea, "<h3") != NULL ||  strstr(linea, "<h4") != NULL || strstr(linea, "<h5") != NULL  || strstr(linea, "<h6") != NULL  ) {
        quitaespacios(linea,lineasin);
        quitaparentesis(lineasin, lineasinetiquetas);
            printf("%s\n", lineasinetiquetas);
}
    else if (strstr(linea, "<strong>") != NULL) {
        strong(linea, lineasinstrong);
        quitaparentesis(lineasinstrong,lineasinetiquetas);
            printf("%s\n", lineasinetiquetas);
    }
    else{
        quitaparentesis(linea,lineasinetiquetas);
            printf("%s\n", lineasinetiquetas);
    }
    }
    if (strstr(linea, "</script>") != NULL)  // if we found  "</script>" stop ignoring
        ignore = 0;
    if (strstr(linea, "</div>") != NULL) // if we found  "</div>" stop ignoring
        ignore = 0;
    if (strstr(linea, ">") != NULL) // if we found  ">" stop ignoring 
        ignoreimg = 0;
    if (strstr(linea, "</form>") != NULL) // if we found  "</form>" stop ignoring
        ignoreforms = 0;
    if (strstr(linea, "</table>") != NULL) // if we found  "</table>" stop ignoring
        ignoretable = 0;
  }
  return 0;
}

/* Function that give us the line, modification of a 
SATU ELISA SCHAEFFER  code Longest2.c nocomment.c*/
int saca() { 
    extern char linea[];
        int c, i = 0;
    for (; i < MAX - 1 && (c = getchar()) != EOF && c != '\n';) 
        linea[i++] = c;
        linea[i] = '\0'; // caracter end of string
    return c == EOF;
    }
    
/* Function that change the \t and ' '  by "_"
When we have cadena to input we use that formula to have a cadenasin in output*/
void quitaespacios(char cadena [MAX], char cadenasin[MAX]) {
    int a;
        for (a=0;a<MAX;a++){ /*Read  the string, one by one */
        if (cadena[a] != ' '&& cadena[a] != '\t')
            cadenasin[a] = cadena[a];
        else
            cadenasin[a]= '_';
}
}
/* Function that eliminate <...> (input, output) */
void quitaparentesis(char cadena[MAX], char cadenasin[MAX]){
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