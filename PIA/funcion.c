/*
Hello classmate or teacher it's a pleasure to present my project to us. 
I'm going to tell you how to compile:
1.- You need to open https://www.onlinegdb.com/online_c_compiler
2.- Then put the Language into C
3.- Copy each file with the same name 
   a) main.c
   b) funcion.c
   c) funcion.h
4.- Run the program and enjoy the project
5.- When you finish the calculus and exit in the menu,
they are gonna create and .txt file for us
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int panelesparauso;
int nojala= 0;

void logos(){
printf(" #####  ####### #          #    ######     #     # ### ####### #     #     #####  \n");
printf("#     # #     # #         # #   #     #    #  #  #  #     #    #     #    #     # \n");
printf("#       #     # #        #   #  #     #    #  #  #  #     #    #     #    #       \n");
printf(" #####  #     # #       #     # ######     #  #  #  #     #    #######    #       \n");
printf("      # #     # #       ####### #   #      #  #  #  #     #    #     #    #       \n");
printf("#     # #     # #       #     # #    #     #  #  #  #     #    #     #    #     # \n");
printf(" #####  ####### ####### #     # #     #     ## ##  ###    #    #     #     #####  \n\n");
printf("\t\t ____   ___  ____   ___   ____ ___  ____ _____   \n");
printf("\t\t|  _ \\ / _ \\| __ ) / _ \\ / ___/ _ \\|  _ \\_   _|\n");
printf("\t\t| |_) | | | |  _ \\| | | | |  | | | | |_) || |  \n");
printf("\t\t|  _ <| |_| | |_) | |_| | |__| |_| |  _ < | |  \n");
printf("\t\t|_| \\_\\\\___/|____/ \\___/ \\____\\___/|_| \\_\\|_|  \n\n");
}
 
void calculosinterconect(){
   float promedioluz, reduccion,kwuso,panelelegido,panel1 = .300,panel2 = .335,panel3 =.350,avld,num,den;
   int tipopanel,menuinicio,panelausar;
   printf("\tWrite your bimester average use of light in your last year: ");
   scanf("%f", &promedioluz);
   printf("\t\tThe energy tolerance is: %.2f \n",(promedioluz*1.1));
   printf("\t\tThe average daily use is: %.2f \n",(promedioluz*1.1)/60);
      avld=(promedioluz*1.1)/60;
   printf("\t\tWrite the percentage to reduce (0-100): ");
   scanf("%f", &reduccion);
      reduccion= reduccion/100;
      num=avld*reduccion*1.25;
      den=num/6;
   printf("\t\tThe KW to reduce are: %.2f\n",den);
      kwuso=den;
   printf("\t\tWhich type of panel do you want:\n");
   printf("\t\t1. 300 W  2. 335 W   3. 350 W\n");
   scanf("%i", &tipopanel);
   
      if(tipopanel==1){
         panelelegido=panel1;
      }
      if(tipopanel==2){
         panelelegido=panel2;
      }
      if(tipopanel==3){
         panelelegido=panel3;
      }
   
   printf("\t\tHow many panels we need : %.0f",(kwuso/panelelegido));
      panelausar=(kwuso/panelelegido)+1;
      panelesparauso=panelausar;
   //area casa
      float largo,ancho,area;
   printf("\n\t\tWrite the size of one side of the roof of your house ");
   scanf("%f", &largo);
   printf("\t\tWrite the other ");
   scanf("%f", &ancho);
      area=largo*ancho;
   printf("\t\tThe area of your house is: %.4f\n",area);
   //area panel
      float areapanel;
      areapanel=(1.690*.998);
   printf("\t\tThe panels area is: %.2f\n",areapanel*panelausar); 
   
   if(area>areapanel){
      printf("\t\tYou can put %i panels in your house\n",panelausar);
   }
   if(area<areapanel){
      printf("\t\tYou can't put %i panels in your house\n",panelausar);
      nojala ++;
   }
}
   
void horaactual(){
   time_t tiempo = time(0);
   struct tm *tlocal = localtime(&tiempo);
   printf("\t\t\t\tToday is %2d/%2d/%d", tlocal->tm_mday,tlocal->tm_mon+1,tlocal->tm_year+1900); //Mostrar Fecha
   printf("\n\t\t\t\t   Time: %d:%d:%2d\n",tlocal->tm_hour-5,tlocal->tm_min,tlocal->tm_sec); //Mostrar Hora

}

void seorpa(){
      int sorp,temcheck;
      float vsnom,vsmax,vsmin,vpnom,vpmax,vpmin,vp=44.3,temmin,temmax;
    printf("\t\tDo you know the max and min value of °C\n");
    printf("\t\t            1. Yes  2. No \n");
    scanf("%i", &temcheck);
    
     if(temcheck == 1){
        printf("\t\tWrite the min temperature: ");
        scanf("%f", &temmin);
        printf("\t\tWrite the max temperature: ");
        scanf("%f", &temmax);
     }
     
     if(temcheck == 2){
         temmin= -12;
         temmax= 41;
         printf("\t\tWe are gonna use %.0f °C min %.0f °C max\n",temmin,temmax);
     }
    
    printf("\t\tSERIE %is-1p                     PARALEL %is-2p\n",panelesparauso,panelesparauso/2);
      vsnom=panelesparauso*vp;
      vpnom=(panelesparauso/2)*vp;
    printf("\t\t%.2f °C Vnominal\t\t",vsnom);
    printf("%.2f °C Vnominal\n",vpnom);
      vsmax= ((((((25-(temmin))*.29)/100)+1)*vp)*panelesparauso);
      vpmax= ((((((25-(temmin))*.29)/100)+1)*vp)*(panelesparauso/2));
    printf("\t\t%.2f °C Vmax\t\t\t",vsmax);
    printf("%.2f °C Vmax\n",vpmax); 
      vsmin= ((((((temmax-25)*-.29)/100)*44.3)+vp)*panelesparauso);
      vpmin= ((((((temmax-25)*-.29)/100)*44.3)+vp)*(panelesparauso/2));
    printf("\t\t%.2f °C Vmin\t\t\t",vsmin);
    printf("%.2f °C Vmin\n",vpmin);

   printf("\t\tDo you want to use in serie or paralel\n");
   printf("\t\t   Serie = 1       Paralel = 2\n");
   scanf("%i",&sorp);
   
   if(sorp==1){
      printf("\t\tCheck the file.txt at the end of the program");
         
         FILE*final = fopen("file.txt", "a+");
      fprintf(final,"\tReport\n");
      fprintf(final,"\tYou will use interconnected to the network\n");
      fprintf(final,"\tYou are going to use %i panels in serie (%is-1p)\n",panelesparauso,panelesparauso);
      fprintf(final,"\tWith an inverter UNO-8.6-TL-OUTD-S-US-A BY ABB STRING INVERTERS OF SOLAR INVERTERS\n");
      fprintf(final,"\tWith a current of 9.6 because is the panel's ISC, we need a fuse of 15A\n");
      fprintf(final,"\tWith a wire gauge solar 14\n\n");
      fclose(final);
      
   }    
   
   if(sorp==2){
      printf("\t\tCheck the file.txt at the end of the program");
      
         FILE*final = fopen("file.txt", "a+");
      fprintf(final,"\tReport\n");
      fprintf(final,"\tYou will use interconnected to the network\n");
      fprintf(final,"\tYou are going to use %i panels in serie and 2 in paralel(%is-2p)\n",panelesparauso/2,panelesparauso/2);
      fprintf(final,"\tWith an inverter GW2000-XS BY XS SERIES OF GOOD WE\n");
      fprintf(final,"\tWith a current of 19.2 because is the panel's ISC multiplied by 2, we need a fuse of 25A\n");
      fprintf(final,"\tWith a wire gauge solar 12\n\n");
      fclose(final);
      
   } 
   
}