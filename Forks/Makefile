all: build stuff

build: HW3.c
	gcc -o HW3 HW3.c

stuff: maxmin.c
	gcc -o maxmin maxmin.c

testing1: all
	./HW3 1 test.txt

testing4: all
	./HW3 4 test.txt

file: write.c
	gcc -o write write.c
	./write

clean:
	if [ -f HW3 ]; then \
		rm HW3; \
	fi
	if [ -f maxmin ]; then \
		rm maxmin; \
	fi
