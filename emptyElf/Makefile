empty: empty.s
	gcc -Wl,--build-id=none -Wl,-Map=empty.map -Wl,--verbose -nostartfiles -nodefaultlibs --static empty.s -o empty

hello: hello.c
	gcc --static hello.c -o hello

clean:
	-rm empty hello empty.map
