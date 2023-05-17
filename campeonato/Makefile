all:
	gcc -g -Wall -o main *.c 
clean:
	rm main 
run:
	./main < in_1.txt
valgrind:
	valgrind --track-origins=yes --leak-check=full ./main < entrada_1
	