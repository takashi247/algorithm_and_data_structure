#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

long long
	get_tribo(int n)
{
	static long long	memo[MAX_LEN];

	if (n == 0)
		return (0);
	else if (n == 1)
		return (0);
	else if (n == 2)
		return (1);
	else
	{
		if (memo[n] == 0)
			memo[n] = get_tribo(n - 1) + get_tribo(n - 2) + get_tribo(n - 3);
		return (memo[n]);
	}
}

int
	main(int ac, char **av)
{
	int	n;

	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	printf("result: %lld\n", get_tribo(n));
	return (0);
}
