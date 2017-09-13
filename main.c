#include <stdlib.h>
#include <stdio.h>

void convert(double value, char type){
  if(type == 'C'){
    if(value <= -273.15){
      printf("Celsius: Temperature value is below(equal to) absolute zero");
    } else {
      double ck = value + 273.15;
      double cf = (value * 9 / 5) + 32;
      
      printf("%.2f C:\n", value);
      printf("%.2f K\n", ck);
      printf("%.2f F\n", cf);
    }
  } else if(type == 'F'){
    if(value <= -459.67){
      printf("Fahrenheit: Temperature value is below(equal to) absolute zero");
    } else {
      double fc = (value - 32) * 5 / 9;
      double fk = (value + 459.67) * 5 / 9;
      
      printf("%.2f F:\n", value);
      printf("%.2f C\n", fc);
      printf("%.2f K\n", fk);
    }
  } else if(type == 'K'){
    if(value <= 0){
      printf("Kelvin: Temperature value is below(equal to) absolute zero");
    } else {
      double kc = value - 273.15;
      double kf = (value / 5 * 9) - 459.67;
      
      printf("%.2f K:\n", value);
      printf("%.2f C\n", kc);
      printf("%.2f F\n", kf);
    }
  } else {
    printf("Type must be K, F or C");
  }
}

int main(int argc, char* argv[]){
  /* Accept at least 1 argument */
  if(argc < 2 || argc > 3){
    printf("usage: tconvert degrees [type]");
  } else if(argc == 2){
    /* If only one argument passed, convert to all possible types */
    double value = atof(argv[1]);
    convert(value, 'C');
    printf("\n");
    convert(value, 'F');
    printf("\n");
    convert(value, 'K');
  } else if(argc == 3){
    /* If both arguments are passed, convert to needed type */
    double value = atof(argv[1]);
    convert(value, *argv[2]);
  }
  
  return 0;
}