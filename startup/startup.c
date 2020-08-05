#include<stdio.h>
int main(int argc, char *argv[], char * envp[])
{
#if 0
    int i;

    printf("argc: %d\n\n",argc);

    for(i=0; i<argc; i++) 
        printf("argc[%d]=%s\n",i,argv[i]);

    printf("\nenvp: \n");
    for (i = 0; envp[i] != NULL; i++) 
        printf("envp[%d]=%s\n",i, envp[i]); 

#endif
    return 0;
}
