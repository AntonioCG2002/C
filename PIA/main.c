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

#include "funcion.h"
#define TRUE 1

int panelesparauso;
int nojala;

int main(){
   //Variables
   int menu=0;
   int salir;
   logos();
   horaactual();
   //MAIN MENU
   while(menu==0){
      
      printf("\n\t\t\t\t\tMenu\n\t\t\t  1 Calculus   2 Info    3 Exit\n");
      scanf("%i",&salir);
      
      //MAIN MENU (1)
      if(salir==1){
         calculosinterconect();
         
         while(nojala==0){
            seorpa();
            nojala++;
         }
      }
      
      //MAIN MENU (2)
      if(salir==2){
         int info,menuinfo=0;
         //INFO MENU
         while(menuinfo==0){
            printf("\n\t\tINFO MENU\n");
            printf("\t\tWrite: 1 Importance to use solar energy\n");
            printf("\t\tWrite: 2 Advantages to use solar panels\n");
            printf("\t\tWrite: 3 What is interconect to the network (on-grid)\n");
            printf("\t\tWrite: 4 Return to the Main menu\n");
            scanf("%i",&info);            

            //INFO MENU(1)
            if(info==1){
               printf("\t\t1 Importance to use solar energy\n");
               printf("\tElectricity in Mexico, unlike in the countries is very expensive, this makes installing a solar\n");
               printf("\tpanel system a well worth it investment. By installing a solar power generating system you will\n");   
               printf("\tfreeze the cost of electricity and become immune to the common energy rate increases.\n\n");
            }

            //INFO MENU(2)
            if(info==2){
               printf("\t\t2 Advantages to use solar panels\n");
               printf("\tPay the lowest price per kWh of energy\n");
               printf("\tProduce your own energy instead of buying it from CFE\n");
               printf("\tLong term savings during the lifetime of the solar power system (30 years) \n");
            }            

            //INFO MENU(3)
            if(info==3){
               printf("\t\t3 What is interconect to the network (on-grid)\n");
               printf("\tWith grid-tied systems, you can draw power from the power grid when your\n");
               printf("\tsolar panel system isn’t producing electricity. Additionally, you can supplement\n");
               printf("\tyour energy needs with electricity from the grid when the sun is shining if you’re\n");
               printf("\tusing more electricity than your solar panels are producing. When your solar panels\n");
               printf("\tgenerate more electricity than you are using, the excess kilowatt-hours (kWh) are\n");
               printf("\texported to the grid. If you are a customer of a utility that offers net metering,\n");
               printf("\tyou will receive credits for this electricity that you can apply towards a future electric bill.\n");
            }            

            //INFO MENU(4)
            if(info==4){
               menuinfo ++;
            }
            
            //INFO MENU(INCORRECT)
            if(info>=5|salir<=0){
            printf("\t\t\t\t  CHECK YOUR INPUT\n");
            }
            
         }
         
      }
      
      //MAIN MENU (3)
      if(salir==3){
         printf("\t\tThanks for use Solar for C by Antonio Cortes\n");
         menu++;
         EOF;
      }
      
      //MAIN MENU (INCORRECT)
      if(salir>=4|salir<=0){
         printf("\t\t\t\t  CHECK YOUR INPUT\n");
      }
   
      }

   }
   