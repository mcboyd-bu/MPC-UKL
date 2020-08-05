





#include <stdio.h>
int foo(){};

extern int __attribute__((weak)) TU_PATH;
int main(){
  printf("TU_PATH IS %d\n", &TU_PATH);
  printf("foo lives at %p\n", &foo);

  if(! &TU_PATH){
    printf("this is the true path\n");
  }else{
    printf("this is the false path\n");
  }
  return 0;
}
