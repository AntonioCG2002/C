/*Para compilar agrega 3 archivos en el gcc compilador online con los siguientes nombres
main.c
function.c
header.h
y copia cada código del repo al archivo, no necesitas ningún archivo de texto ya que se crea 
automáticamente*/

#include "header.h"

int main(){
    FILE *flujo;
    int temppin, temptime, flag = 1, pin, option, bucle = 1, user;
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128], buffer[32];
    
    printf("Hoy es %2d/%2d/%d", tlocal->tm_mday,tlocal->tm_mon+1,tlocal->tm_year+1900); //Mostrar Fecha
    printf("\nSon las %d:%d:%2d",tlocal->tm_hour-5,tlocal->tm_min,tlocal->tm_sec); //Mostrar Hora
    printf("\nBuenas, eres usuario o administrador?\n1 para usuario, 2 si eres admi\n"); //Bienvenida
    scanf("%d", &option);
    if (option == 1){ //opciones de trabajador
        option = 0;
        printf("Bienvenido, intruduce tu pin: \n");
        scanf("%d", &pin);
        if (checkPines(pin) != 1){ //verificar si ese pin existe en el sistema
            printf("ese pin no existe, checa el registro de pines validos en system.tx o crea a ese usuario como administrador\n");
            printf("Hasta pronto!\n");
            exit(1);
        }
        printf("Persona #%d  ** Bienvenido al registro ** \nQue deseas hacer?\n", pin);
        printf("-Presiona 1 para marcar entrada-\n-Presiona 2 para marcar salida-\n");
        scanf("%d", &option);
        switch (option){
        case 1: //entrada
            flujo = fopen("log.txt", "a");
            printf("Se ha registrado tu entrada pin:%d hoy:%s %s\n", pin, output, buffer);
            fprintf(flujo, "e%d %lu %s %s\n", pin, (unsigned long)time(NULL), output, buffer);
            printf("Éxito en el trabajo");
            fflush(flujo);
            fclose(flujo);
            break;
        case 2: //salida
            flujo = fopen("times.txt", "r+");
            while (flag != 0){
                fscanf(flujo, "%d %d", &temppin, &temptime);
                if (temppin == pin){
                    temptime += verTiempoTrabajado(pin);
                    fseek(flujo, -3, SEEK_CUR);
                    fprintf(flujo, "%d %d", pin, temptime);
                    fflush(flujo);
                    fclose(flujo);
                    flag = 0;
                }
            }
            flujo = fopen("log.txt", "a");
            printf("Se ha registrado tu salida pin:%d hoy:%s %s\n", pin, output, buffer);
            fprintf(flujo, "s%d %lu %s %s %d\n", pin, (unsigned long)time(NULL), output, buffer, verTiempoTrabajado(pin));
            printf("\n Has trabajado por %d segundos \n Nos vemos pronto\n", verTiempoTrabajado(pin));
            fflush(flujo);
            fclose(flujo);
            fprintf(flujo, "%d %d\n", pin, verTiempoTrabajado(pin));
            break;
        }
    }
    
    else if (option == 2){ //opciones de admin
        option = 0;
        printf("Bienvenido, intruduce tu pin: \n");
        scanf("%d", &pin);
        if (pin != 000){
            printf("NO ERES ADMINISTRADOR\n");
            EOF;
        }
        else{
            while (bucle == 1){
                option = 0;
                printf("\nQue tal admi, en que te puedo servir ahora\n");
                printf("Marca 1 si quieres ver las asistencias de un usuario    \tMarca 2 si quieres agregar un nuevo trabajador\n");
                printf("Marca 3 si quiero ver las horas trabajadas de un usuario\tMarca 4 si quieres salir\n");
                fflush(stdin);
                scanf("%d", &option);
                switch (option){// acciones
                case 1: //Reporte de asistencias
                    printf("Escribe el pin del usuario para ver sus asistencias(asegurate de que sea valido): \n");
                    fflush(stdin);
                    scanf("%d", &pin);
                    if (checkPines(pin) != 1){ //verificar si ese pin existe en el sistema
                        printf("Ese pin no existe, checa el registro de pines validos en system.tx o crea a ese usuario \n");
                        printf("Hasta pronto!\n");
                        exit(1);
                    }
                    verAsistencias(pin);
                    break;
                case 2://creacion de usuario
                    crearRegistro();
                    break;
                case 3://reporte de  registros
                    printf("Escribe el pin del usuario para ver sus asistencias(asegurate de que sea valido): \n");
                    fflush(stdin);
                    scanf("%d", &pin);
                    if (checkPines(pin) != 1){ //verificar si ese pin existe en el sistema
                        printf("Ese pin no existe, checa el registro de pines validos en system.tx o crea a ese usuario \n");
                        printf("Lo siento pero nos tenemos que despedir, hasta pronto!\n");
                        exit(1);
                    }
                    printf("El usuario con el pin: %d,  ha trabajado por %d segundos \n", pin, calcHorasLaboradas(pin));
                    break;
                    case 4:
                        exit(1);
                        break;
                }
            }
        }
    }
    else{
        printf("Lamentamos no poder atenderte pero no escribiste una opcion valida. Presione enter para salir ...");
        exit(1);
    }
}
//*En colaboración con Abner*