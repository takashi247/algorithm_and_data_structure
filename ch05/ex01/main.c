#include <stdio.h>

static int
	chmax(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int
	main(void)
{
	int	i;
	int	a[5] = {1, 3, 5, 8, 3};
	int	b[5] = {2, 4, 3, 6, 8};
	int	c[5] = {4, 2, 3, 9, 7};
	int u[3 * 5];

	i = 0;
	while (i < 5)
	{
		if (i == 0)
		{
			u[0] = a[0];
			u[1] = b[0];
			u[2] = c[0];
		}
		else
		{
			u[3 * i + 0] = chmax(u[3 * (i - 1) + 1] + a[i], u[3 * (i - 1) + 2] + a[i]);
			u[3 * i + 1] = chmax(u[3 * (i - 1) + 0] + b[i], u[3 * (i - 1) + 2] + b[i]);
			u[3 * i + 2] = chmax(u[3 * (i - 1) + 0] + c[i], u[3 * (i - 1) + 1] + c[i]);
		}
		i++;
	}
	printf("maximum utility: %d\n", chmax(chmax(u[3 * (5 - 1) + 0], u[3 * (5 - 1) + 1]), u[3 * (5 - 1) + 2]));
	return (0);
}
