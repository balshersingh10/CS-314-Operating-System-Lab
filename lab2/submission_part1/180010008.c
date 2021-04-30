#include <stdio.h> 
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h> 
#include <unistd.h> 
int main()
{
    char a[] = "Hello World";
    int k;
    int n;
    int pid = 0;
    for(k = 0; k<=10; k = k+1)
    {
        if(pid == 0)
        {
            printf("%c pid %d\n",a[k], getpid());
            n = (rand()%4) + 1;
            sleep(n);
            if(k != 10)
            {
            	pid = fork();
            }
        }
    }
    wait(NULL);
    return 0;
}