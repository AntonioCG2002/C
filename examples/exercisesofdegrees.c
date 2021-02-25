#include <stdio.h>
#define INICIO 0
#define FINAL 100
#define PASO 25

int main ()
{
  float fahr, celsius;
  int y = 6; 
/*You need to put a number here in "y" (0,2,4,6)
For 0 it's a table from F° to C° when F° it's first
For 2 it's a table from F° to C° when C° it's first
For 4 it's a table from C° to F° when C° it's first
For 6 it's a table from C° to F° when F° it's first
Enjoy it*/
  while (y == 0)
    {
      printf ("Fahrenheit\tCelsius\n");
      fahr = INICIO;
      while (fahr <= FINAL)
	{
	  celsius = 5.0 * (fahr - 32) / 9.0;
	  printf ("%3.0f \t\t %3.3f \n", fahr, celsius);
	  fahr += PASO;
	  y++;
	}
    }


  while (y == 2)
    {
      printf ("Celsius\t\tFahrenheit\n");
      fahr = INICIO;
      while (fahr <= FINAL)
	{
	  celsius = 5.0 * (fahr - 32) / 9.0;
	  printf ("%3.2f \t\t %3.0f \n", celsius, fahr);
	  fahr += PASO;
	  y++;
	}
    }

  while (y == 4)
    {
      printf ("Celsius\t\tFahrenheit\n");
      celsius = INICIO;
      while (celsius <= FINAL)
	{
	  fahr = ((1.8 * celsius) + 32);
	  printf ("%3.0f \t\t %3.3f \n", celsius, fahr);
	  celsius += PASO;
	  y++;
	}
    }

  while (y == 6)
    {
      printf ("Fahrenheit\tCelsius\n");
      celsius = INICIO;
      while (celsius <= FINAL)
	{
	  fahr = ((1.8 * celsius) + 32);
	  printf ("%3.0f \t\t %3.0f \n", fahr, celsius);
	  celsius += PASO;
	  y++;
	}
    }
  return 0;
}
