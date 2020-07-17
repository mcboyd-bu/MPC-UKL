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

clean:
	rm cons cons.o consLongBuild listing.txt
