#include <string.h>

int read_line(char *str){
   for (int i = 0; i < strlen(str); i++) {
      if(!(str[i] >= '0' && str[i] <= '9')) return 0;
   }
   return 1;
};
