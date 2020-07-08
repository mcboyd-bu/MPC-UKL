#include <stdio.h>
#include <stdint.h>

void foo(){}
void bar(){}
void baz(){}

void main(){
	foo();
	bar();

	register uint64_t src = 1;
	register uint64_t dst;   

	asm ("mov %1, %0\n\t"
	    "add $1, %0"
	    : "=r" (dst) 
	    : "r" (src));

	printf("%d\n", dst);

	baz();	


}
