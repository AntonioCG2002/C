#define COLUMNS 10
#define ROWS 10
#define FIND_MINE 1
#define ALREADY_OPEN 2
#define ANY 3
#define SPACE_NOTOPEN '#'
#define SPACE_OPEN '*'
#define MINA 'X'
#define CANTIDAD_MINAS 15
#define DEBUG 0  // IF YOU PUT 1 YOU CAN SEE THE MINES


int minesnearby(int fila, int columna, char table[ROWS][COLUMNS]);
int randomnumber(int minimo, int maximo);
void starttable(char table[ROWS][COLUMNS]);
void putmina(int fila, int columna, char table[ROWS][COLUMNS]);
void putminas(char table[ROWS][COLUMNS]);
void imprimirEncabezado();
char intchar(int numero);
void writetable(char table[ROWS][COLUMNS], int showmine);
int Openbox(char filaLetra, int columna, char table[ROWS][COLUMNS]);
int nobox(char table[ROWS][COLUMNS]);
