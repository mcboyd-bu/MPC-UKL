# Compilation stages
# PREPROCESSING -> COMPILATION -> ASSEMBLING -> LINKING
# File types
# source.cpp -> preprocessed.i -> compiled.s -> assembled.o -> linked (executable)

# Special variables:
# $@ is target file
# $^ all the prereqs 

# Phony doesn't actually create a file 
.PHONY: clean all check

# Creates a file named after the target and populates it with the post processed data.
all: check

gpp_preprocessed.i: hello.cpp
	g++ -static -E $^ > $@

gpp_compiled.s: gpp_preprocessed.i
	g++ -static -S -o $@ $^

gpp_assembled.o: gpp_compiled.s
	g++ -static -c -o $@ $^

gpp_linked: gpp_assembled.o
	g++ -static -o $@ $^

# Here we go straight from the cpp file
gpp_one_shot_compiled.s: hello.cpp
	g++ -S -o $@ $^

gpp_one_shot_assembled.o: hello.cpp
	g++ -c -o $@ $^

gpp_one_shot_linked: hello.cpp
	g++ -static -o $@ $^
	
# Here we grab what gpp expands
long_form_preprocessed.i: hello.cpp
	/usr/lib/gcc/x86_64-linux-gnu/5/cc1plus -E -quiet -v -imultiarch x86_64-linux-gnu -D_GNU_SOURCE $^ -mtune=generic -march=x86-64 -fstack-protector-strong -Wformat -Wformat-security > $@

long_form_compiled.s: long_form_preprocessed.i
	/usr/lib/gcc/x86_64-linux-gnu/5/cc1plus -fpreprocessed $^ -quiet -dumpbase $^ -mtune=generic -march=x86-64 -auxbase-strip $@ -version -o $@ -fstack-protector-strong -Wformat -Wformat-security

long_form_assembled.o: long_form_compiled.s
	as -v --64 -o $@ $^

long_form_linked: long_form_assembled.o
	/usr/lib/gcc/x86_64-linux-gnu/5/collect2 -plugin /usr/lib/gcc/x86_64-linux-gnu/5/liblto_plugin.so -plugin-opt=/usr/lib/gcc/x86_64-linux-gnu/5/lto-wrapper -plugin-opt=-fresolution=/tmp/my_tmp_file.res -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_eh -plugin-opt=-pass-through=-lc --sysroot=/ --build-id -m elf_x86_64 --hash-style=gnu --as-needed -static -z relro -o $@ /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/5/crtbeginT.o -L/usr/lib/gcc/x86_64-linux-gnu/5 -L/usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu -L/usr/lib/gcc/x86_64-linux-gnu/5/../../../../lib -L/lib/x86_64-linux-gnu -L/lib/../lib -L/usr/lib/x86_64-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/x86_64-linux-gnu/5/../../.. $^ -lstdc++ -lm --start-group -lgcc -lgcc_eh -lc --end-group /usr/lib/gcc/x86_64-linux-gnu/5/crtend.o /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crtn.o

# This was the version for dynamic linking

#/usr/lib/gcc/x86_64-linux-gnu/5/collect2 -plugin /usr/lib/gcc/x86_64-linux-gnu/5/liblto_plugin.so -plugin-opt=/usr/lib/gcc/x86_64-linux-gnu/5/lto-wrapper -plugin-opt=-fresolution=/tmp/ccFuTRIR.res -plugin-opt=-pass-through=-lgcc_s -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lc -plugin-opt=-pass-through=-lgcc_s -plugin-opt=-pass-through=-lgcc --sysroot=/ --build-id --eh-frame-hdr -m elf_x86_64 --hash-style=gnu --as-needed -dynamic-linker /lib64/ld-linux-x86-64.so.2 -z relro -o $@ /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/5/crtbegin.o -L/usr/lib/gcc/x86_64-linux-gnu/5 -L/usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu -L/usr/lib/gcc/x86_64-linux-gnu/5/../../../../lib -L/lib/x86_64-linux-gnu -L/lib/../lib -L/usr/lib/x86_64-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/x86_64-linux-gnu/5/../../.. $^ -lstdc++ -lm -lgcc_s -lgcc -lc -lgcc_s -lgcc /usr/lib/gcc/x86_64-linux-gnu/5/crtend.o /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crtn.o

check: gpp_compiled.s gpp_assembled.o gpp_linked gpp_one_shot_compiled.s gpp_one_shot_assembled.o gpp_one_shot_linked long_form_preprocessed.i long_form_compiled.s long_form_assembled.o long_form_linked
	echo the preprocessed .i files
	md5sum gpp_preprocessed.i long_form_preprocessed.i
	echo the compiled .s files
	md5sum gpp_compiled.s gpp_one_shot_compiled.s long_form_compiled.s
	echo the assembled .o files
	md5sum gpp_assembled.o gpp_one_shot_assembled.o long_form_assembled.o
	echo the linked executable files
	md5sum gpp_linked gpp_one_shot_linked long_form_linked

clean:
	rm -rf gpp_* long_form_*
