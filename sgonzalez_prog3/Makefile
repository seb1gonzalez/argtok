# Complete this rule
sgonzalez_prog3: sgonzalez_prime.o sgonzalez_prog3.c
	gcc -pthread -o sgonzalez_prog3 sgonzalez_prog3.c sgonzalez_prime.o

# Replace with correct file names
sgonzalez_prime.o: sgonzalez_prime.c sgonzalez_prime.h
	gcc -c sgonzalez_prime.c

clean:
	rm *.o; rm sgonzalez_prog3 primest primes1 primes2
