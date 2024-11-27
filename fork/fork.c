#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int data = 472;


int main(int argc, char* argv[]){
    int pid, status;
    printf("Process id: %d. Parent's process id: %d\n", getpid(), getppid());
    printf("Before the fork the data is: %d\n", data);
    pid = fork();
    printf("Fork returned %d\n", pid);
    if (pid != 0) {
        printf("I am the parent. Data is %d\n", data);
        sleep(1);
        data = 0;
        printf("I am the parent again . Data is %d\n", data);

    }
    else {
        printf("I am the child. Data is %d\n", data);
        sleep(2);
        printf("I am the child again . Data is %d\n", data);
        sleep(2);
        data = 444;
        printf("I am the child again . Data is %d\n", data);



    }
    wait(&status);
    printf("Hello OS\n");


    return 0;
}               
 