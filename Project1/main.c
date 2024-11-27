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
    sem_t sem[M];
    FILE* cf = fopen("config_3_100.txt", "r");
    FILE* tf = fopen("mobydick.txt", "r");
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
        printf("%d, %s, %c\n", num, process, status);
    }


    
    fclose(cf);
    fclose(tf);
    
    
    return 0;
}