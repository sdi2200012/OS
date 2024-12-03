#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <sys/stat.h>
#define M 5
#define SEM_PERMS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)
#define INITIAL_VALUE 1
#define SHM_SIZE 1024




int main(int argc, char* argv[]){
    //Checking if main has the right amount of arguments 
    if (argc < 2){
        perror("Not enough arguments!");
        return -1;
    }
    //The first two arguments are the file names needed 
    char file1[100], file2[100];
    strcpy(file1, argv[1]);
    strcpy(file2, argv[2]);
    printf("%s\n", file1);
    printf("%s\n", file2);
    //The third argument is the amount of childer we have that are active (M)
    int children = atoi(argv[3]);
    sem_t semaphores[children];
    
    FILE* cf = fopen(file1, "r");
    FILE* tf = fopen(file2, "r");
    if (tf == NULL){
        perror("Error in openning the file!");
        return -1;  
    }
    if (cf == NULL) {
        perror("Error in opening the file!");
        return -1;    
    }
    char line[100];
    int num;
    char process[3];
    char status;
    while(fgets(line, sizeof(line), cf) != NULL){
        sscanf(line, "%d %s %c", &num, process, &status);
        
    }


    
    fclose(cf);
    fclose(tf);
    
    
    return 0;
}