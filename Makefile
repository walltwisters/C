CC=gcc
all: make.out

make.out: src/make.c
	 $(CC) -o out/make.out src/make.c

clean:
	 rm out/make.out
watch:
	while true; do make --silent; sleep 1; done