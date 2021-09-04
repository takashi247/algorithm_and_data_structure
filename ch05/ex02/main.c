#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void
	store_nums(int *num_array, const int size_of_array, char **av)
{
	int	i;

	i = 0;
	while (i < size_of_array)
	{
		num_array[i] = atoi(av[i]);
		i++;
	}
}

int
	main(int ac, char **av)
{
	int			*num_array;
	const int	w = atoi(av[ac - 1]);
	const int	size_of_array = ac - 2;
	int			*dp;
	int			current_len;
	int			i;
	int			j;

	if (size_of_array <= 0)
		return (1);
	num_array = (int *)malloc(sizeof(int) * size_of_array);
	dp = (int *)malloc(sizeof(int) * (w + 1) * (size_of_array + 1));
	if (!num_array || !dp)
		return (1);
	memset(dp, 0, sizeof(int) * (w + 1) * (size_of_array + 1));
	store_nums(num_array, size_of_array, ++av);
	current_len = size_of_array;
	dp[0] = 1;
	i = 0;
	while (i < size_of_array)
	{
		j = 0;
		while (j <= w)
		{
			if (dp[i * (w + 1) + j])
				dp[(i + 1) * (w + 1) + j] = 1;
			else if (j >= num_array[i] && dp[i * (w + 1) + j - num_array[i]])
				dp[(i + 1) * (w + 1) + j] = 1;
			j++;
		}
		i++;
	}
	if (dp[(w + 1) * (size_of_array + 1) - 1])
		printf("Yes\n");
	else
		printf("No\n");
	free(num_array);
	num_array = NULL;
	free(dp);
	dp = NULL;
	return (0);
}