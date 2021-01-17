gcc -o saturn src/plugin.c src/file.c src/main.c src/conf.c -Wall -Wextra \
	-O2 -lcjson -lpthread -ldl
gcc -o plugin1/lib.o -fpic -c plugin1/lib.c -Wall -Wextra -O2
gcc -shared -o plugin1/lib.so plugin1/lib.o -O2