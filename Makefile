build:
	gcc -Wall -std=c99 main.c src/*.c -o main -lm
run:
	./main
debug:
	gcc -g -std=c99 main.c src/*.c -lm
clean:
	rm main
tests:
	gcc -Wall -std=c99 tests.c src/*.c -o tests -lm
clean_tests:
	rm tests