#include <stdlib.h>
#include <stdio.h>

int
	main(int ac, char **av)
{
	int	k;
	int	n;
	int	y;
	int	z;
	int	count;

	if (ac != 3)
		return (1);
	k = atoi(av[1]);
	n = atoi(av[2]);
	z = 0;
	count = 0;
	while (z <= k && z <= n)
	{
		y = 0;
		while (y <= k && y <= n - z)
		{
			if (n - y - z <= k)
				count++;
			y++;
		}
		z++;
	}
	printf("number of combination (x, y, z): %d\n", count);
	return (0);
}
