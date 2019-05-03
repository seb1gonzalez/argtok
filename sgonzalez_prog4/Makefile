bankClient:
	gcc -o bankClient bankClient.c
bankClient.o: bankClient.c banking.h
	gcc -c bankClient.c

clean:
	rm *.o; rm bankClient
