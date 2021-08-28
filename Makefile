all:
	gcc main.c -I. -o main -lm

clean:
	rm main