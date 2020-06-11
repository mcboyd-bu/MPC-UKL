#include <pthread.h>
#include <iostream>

using namespace std;

void* lmain(void* arg) {
  cout<<"\n\nHello World,\nWelcome to my C ++ program on Linux\n\n"<<endl;
  
}

int kmain(void){
    pthread_t thk;
    int ret = (int)pthread_create (&thk, NULL, &lmain, NULL);
    if (ret != 0)
    {
            printf("cpptest main create failed");
            return 1;
    }

    // lmain();

    return 0;
}

int main(void) {
    kmain();
    while(1);
    return 0;
}