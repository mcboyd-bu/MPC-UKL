all: cons consLongBuild

cons: cons.c
	gcc -static $^ -o $@ -g

cons.o: cons.c
	gcc $^ -c -o $@ -Wa,-adhln > listing.txt 

consLongBuild: cons.o
	# gcc -static $^ -o $@ -Wl,-Map=map.txt -Wl,--verbose
	ld -r $^ -o $@ -Map=map.txt --verbose

init_array.bin: consLongBuild
	objcopy -O binary --only-section=.init_array $< $@
# LIBGCC_PATH=/home/tommyu/localInstall/gcc-build-large/x86_64-pc-linux-gnu/libgcc
LIBGCC_PATH=helpers/
link:
	ld  -static -z relro -o cons \
		/usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crti.o $(LIBGCC_PATH)/crtbeginT.o \
		cons.o \
		--start-group $(LIBGCC_PATH)/libgcc.a $(LIBGCC_PATH)/libgcc_eh.a -lc --end-group \
		$(LIBGCC_PATH)/crtend.o /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crtn.o

clean:
	rm cons cons.o consLongBuild listing.txt
