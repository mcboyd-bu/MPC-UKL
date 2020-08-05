#include <stdio.h>
int main(){
#ifdef MY_DEF
  printf("This runs when MY_DEF is defined\n");
#else
  printf("This runs when MY_DEF is NOT defined\n");
#endif

  return 0;
}
