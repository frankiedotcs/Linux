#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//I REALLY hope I did this right. Cause it was sketchy there for a moment. 


int main(int argc, char * argv[]){

    printf("Liz (Frankie) Ruttenbur\n"); //MY NAME!

    int whatthefork; //from the Good Place

    if (argc < 3){
        
        return -1;
    }
    else{
        whatthefork = (int) strtol(argv[1], NULL, 10);
        
        if (whatthefork != 1 && whatthefork != 4){
            
            printf("Nope!: Dude, you can only pick 1 or 4. GET YOUR FORKING ACT TOGETHER!\n"); //helps them see the error of their ways... looking at you Sean!
            return -1;
        }
    }
    int forkingforks = whatthefork; //so you can tell that it's enough forks forking
    int cp[2]; 
    int pid;
    
    if (pipe(cp) < 0){
        printf("Gnarly wipe out! There were no pipes to ride!\n");
        return -1; //pipe was not established
    }

    pid = fork();

    if (pid == 0){
        
        forkingforks--; //decrements how many forks so you know now to do too many
        close(1);
        dup2(cp[1], 1);
        close(0);
        close(cp[0]);
    
        int i;
        for (i = forkingforks; i > 0; i--){

            pid = fork();
            if (pid == 0){
                forkingforks--;

            }
            else{
                break;
            }
        }

    char * childNum = (char *) malloc(sizeof(char));
    sprintf(childNum, "%d", whatthefork - 1 - forkingforks);
    execl("maxmin","maxmin", (whatthefork == 1)? "0" : "4", argv[2], childNum, (char *) NULL);
    free(childNum); //run away child! lol jk.
    }
    else{
        execl("maxmin", "maxmin", "1", argv[2], (char *) 0);
    }
    return 0;
}
