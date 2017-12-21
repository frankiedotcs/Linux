#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

//this is the MIN and MAX file to calculate the min and max of a binary 
//access file. Is it working? WHO KNOWS really for sure. Right?

 int main(int argc, char * argv[])
 {
   clock_t start, end;//the clock struct
   
   
   if(argc < 3){
    exit(1);
   }
   //converts to a base 10
   int numberOfProcesses = (int) strtol(argv[1], NULL, 10);
   const char * filename="test.txt";
   int current; //keeps track of what process is what
   if (argc >= 4){
     current = (int) strtol(argv[3], NULL, 10);
   }
   else{
     current = 0;
   }

   int out;
   if( numberOfProcesses == 1){
       out = 1;
   }
   else {
       out = 2;
   }
   
   //READS THE FILE
   FILE * ft= fopen(filename, "rb") ;

  if (ft) {
    start = clock();
    int pid = getpid();
    fseek (ft,0,SEEK_END); //go to end of file
    long size = ftell(ft); //what byte in file am I at?
    fseek (ft,0,SEEK_SET); //go to beginning of file
    int num = (int)size / (int)sizeof(int);
   
    
   int i;
   int max, min;
   max = 0;
   min = INT_MAX;
   int temp;
   int increment;
   int numbersRead = current;   
    //checks for the MIN AND MAX
    for(i = 0; i<size; i++){
        fread(&temp,sizeof(int),1,ft);
        if (temp < min){
             min = temp;
        }

        if(temp > max){
            max = temp;
        }
           
        if(numberOfProcesses >= 2){
             increment = 3;
        }
        else{
             increment = 0;
             numbersRead += increment;
        }
        if(numbersRead < size){
            fseek(ft, sizeof(int)*increment, SEEK_CUR); //seeks out the current
        }
    }
    fclose( ft );
     end = clock(); //time ends and it calculates the difference between start and end
    double difference = ((double)(end - start)) / CLOCKS_PER_SEC;
    if(out% 2){
        dprintf(out, "Min: %d \t Max: %d \n", min, max);
        dprintf(out, "It took %lf seconds to process the file \n", difference); //indicates the time it took to process the forking fork program
    }
    else{
       write(1, &min, sizeof(int));
       write(1, &max, sizeof(int));
    }
    return 0;
 }
 else{
    printf("Error Will Robinson! -- File didn't open correctly"); 
    exit(1);//exits the program
 }
}//ends main



