all: startup_dynamic startup_static

startup_dynamic: startup.c
	gcc $^ -ggdb -O0 -o startup_dynamic

startup_static: startup.c
	gcc $^ -static -ggdb -O0 -o startup_static

run_dynamic: startup_dynamic
	env -i ENV_1=1 ENV_2=2 ENV_3=3 ./$^ arg1 arg2 arg3

run_static: startup_static
	env -i ENV_1=1 ENV_2=2 ENV_3=3 ./$^ arg1 arg2 arg3


clean:
	rm -rf startup_static startup_dynamic
