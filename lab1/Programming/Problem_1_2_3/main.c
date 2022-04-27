#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readline/readline.h"
#include "factorial/factorial.h"


#define max_line_length 50
int main(int argc, char* argv[]){
   char line[max_line_length] = {0};
   char EXIT[] = "exit()";
   printf("The program will loop forver util hitting exit() !!!!\n");
   printf("Enter an input: ");
   while(scanf("%s", line)){
      if(strcmp(line, EXIT) == 0) break;
      read_line(line) ? printf("%d\n", factorial(atoi(line))) : printf("%d\n", -1);;
      printf("Enter an input: ");
   };
};
