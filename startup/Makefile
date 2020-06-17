


build: startup.c
	gcc $^ -static -o program
run: program
	env -i ENV_1=1 ENV_2=2 ENV_3=3 ./$^ arg1 arg2 arg3
clean:
	rm -rf program
