glavni: polinomi_main.o polinomi.o
	gcc polinomi_main.o polinomi.o -o glavni -Wall -Wextra
polinomi.o: polinomi.c polinomi.h
	gcc -c polinomi.c -Wall -Wextra
polinomi_main.o: polinomi_main.c polinomi.h
	gcc -c polinomi_main.c -Wall -Wextra
.PHONY: clean

clean:
	rm -rf *.o *~ glavni
