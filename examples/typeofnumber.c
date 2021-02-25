#include <stdio.h>
int main(){
float N;
printf("Write a Number and I will tell you if there is Positive, Negative or Neutral: ");
scanf("%f",&N);
    if(N>0) {
        puts("POSITIVE");
    }
    if(N<0){
        puts("NEGATIVE");
    }
    if(N==0){
        puts("NEUTRAL");
    }
    return 0;
}
