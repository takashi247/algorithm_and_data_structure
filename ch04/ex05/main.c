#include <stdio.h>
#include <stdlib.h>

static void
	count_seven_five_three(int k, int num, int flag, long long *count)
{
	if (num <= k)
	{
		if (flag == 0b111)
			(*count)++;
		count_seven_five_three(k, num * 10 + 3, flag | 0b001, count);
		count_seven_five_three(k, num * 10 + 5, flag | 0b010, count);
		count_seven_five_three(k, num * 10 + 7, flag | 0b100, count);
	}
}

int
	main(int ac, char **av)
{
	int			k;
	long long	count;

	if (ac != 2)
		return (1);
	k = atoi(av[1]);
	count = 0;
	count_seven_five_three(k, 0, 0, &count);
	printf("count: %lld\n", count);
	return (0);
}
