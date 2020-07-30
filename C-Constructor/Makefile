all: cons consLongBuild

cons: cons.c
	gcc -static $^ -o $@ -g

cons.o: cons.c
	gcc $^ -c -o $@ -mcmodel=kernel -g

consLongBuild: cons.o
	# gcc -static $^ -o $@ -Wl,-Map=map.txt -Wl,--verbose
	ld -r $^ -o $@ -Map=map.txt --verbose

consExec: consLongBuild
	gcc -o $@ $< 

init_array.bin: consLongBuild
	objcopy -O binary --only-section=.init_array $< $@

# LIBGCC_PATH=/home/tommyu/localInstall/gcc-build-large/x86_64-pc-linux-gnu/libgcc
LIBGCC_PATH=helpers/
#GLIBC_CRT_PATH=/root/localGlibc/glibc-build/csu/
GLIBC_CRT_PATH=helpers/
link: cons.o
	ld  -static -z relro -o $@ \
		$(GLIBC_CRT_PATH)/crt1.o $(GLIBC_CRT_PATH)/crti.o $(LIBGCC_PATH)/crtbeginT.o \
		cons.o \
		--start-group $(LIBGCC_PATH)/libgcc.a $(LIBGCC_PATH)/libgcc_eh.a $(GLIBC_CRT_PATH)/libc.a --end-group \
		$(LIBGCC_PATH)/crtend.o $(GLIBC_CRT_PATH)/crtn.o

link-partial.o: cons.o
	ld -r -static -o $@ \
		$(GLIBC_CRT_PATH)/crt1.o $(GLIBC_CRT_PATH)/crti.o $(LIBGCC_PATH)/crtbegin.o \
		cons.o \
		--start-group $(LIBGCC_PATH)/libgcc.a $(LIBGCC_PATH)/libgcc_eh.a $(GLIBC_CRT_PATH)/libc.a --end-group \
		$(LIBGCC_PATH)/crtend.o $(GLIBC_CRT_PATH)/crtn.o

link-final: link-partial.o
	ld $< -o $@ #-Map=map.txt

clean:
	rm -rf cons cons.o consLongBuild listing.txt consExec map.txt link-partial.o link
