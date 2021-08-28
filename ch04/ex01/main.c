#include <stdlib.h>
#include <stdio.h>

int
	get_tribo(int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (0);
	else if (n == 2)
		return (1);
	else
		return (get_tribo(n - 1) + get_tribo(n - 2) + get_tribo(n - 3));
}

int
	main(int ac, char **av)
{
	int	n;

	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	printf("result: %d\n", get_tribo(n));
	return (0);
}
