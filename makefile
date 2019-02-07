compile:
	gcc sgonzalez_argtok.c sgonzalez_argtok.h main.c -o main
run:
	./main
run-argtok:
	gcc sgonzalez_argtok.c sgonzalez_argtok.h -o argtok
	./argtok
