CFLAGS=$CFLAGS
def: def.c
	gcc -o $@ $< $(CFLAGS)

run: def
	./def

clean:
	rm -rf def
