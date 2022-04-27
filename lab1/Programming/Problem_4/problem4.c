#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> // defines fork() and pid_t
#include <sys/wait.h>

#define max_line_length 50
#define max_array_length 100 
int divideByNum(int arr[], int num, int n)
{
   int count = 0;
   for (int i = 0; i < n; ++i) {
      if (arr[i] % num == 0) {
         count ++;
      }
   }
   return count;
}

int storeArr(int* arr, int argc, char** argv){
   char* path;
   char line[max_line_length] = {0};
   int lineCount = 0;
   if(argc < 1);
   path = argv[1];

   FILE *file = fopen(path, "r");

   if(!file){
      printf("Please enter a path!!\n");
      perror(path);
   }

   while (fgets(line, max_line_length, file)) {
      arr[lineCount] = atoi(line);
      lineCount++;
   }

   if(fclose(file)){
      perror(path);
   }

   return lineCount;
}

int main(int argc, char* argv[]){
   int arr[max_array_length] = {0};
   int lineCount = storeArr(arr, argc, argv);
   pid_t child_pid;
   child_pid = fork();

   if(child_pid == -1){
      perror("fork");
      exit(1);
   }

   if(child_pid == 0){
      /* The child process */
      printf("%d\n", divideByNum(arr, 3, lineCount));
      fflush(stdout);
   }
   else {
      /* The parent process */
      wait(NULL); // wait the child exit
      printf("%d\n", divideByNum(arr, 2, lineCount));
      fflush(stdout);
   }
   return 0;
};
