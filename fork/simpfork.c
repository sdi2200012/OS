#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main(){
    printf("Pid: %d\n", getpid());
    int i = fork();
    printf("Fork: %d, Pid: %d, Ppid: %d\n", i, getpid(), getppid());
    
    return 0;
}