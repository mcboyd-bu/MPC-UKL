#include <stdio.h>
//#define printf printk

void __attribute__ ((constructor)) a_constructor() {
  printf("%s\n", __FUNCTION__);
}
void __attribute__ ((constructor)) b_constructor() {
  printf("%s\n", __FUNCTION__);
}

int main()
{
  printf("%s\n",__FUNCTION__);
  while(1);
  return 0;
}

/* #0  0x0000000000401bd9 in a_constructor () */
/* #1  0x0000000000402b9c in __libc_csu_init () */
/* #2  0x00000000004023ae in __libc_start_main () */
/* #3  0x0000000000401ade in _start () */
