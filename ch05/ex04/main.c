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

static int
	chmin(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

static void
	print_dp(int *dp, int w, int size_of_array)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size_of_array)
	{
		j = 0;
		while (j <= w)
		{
			printf("%d ", dp[i * (w + 1) + j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int
	main(int ac, char **av)
{
	int			*num_array;
	const int	w = atoi(av[ac - 1]);
	const int	k = atoi(av[ac - 2]);
	const int	size_of_array = ac - 3;
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
	memset(dp, -1, sizeof(int) * (w + 1) * (size_of_array + 1));
	store_nums(num_array, size_of_array, ++av);
	current_len = size_of_array;
	dp[0] = 0;
	i = 0;
	while (i <= size_of_array)
	{
		j = 0;
		while (j <= w)
		{
			if (dp[i * (w + 1) + j] >= 0)
			{
				if (dp[(i + 1) * (w + 1) + j] == -1)
					dp[(i + 1) * (w + 1) + j] = dp[i * (w + 1) + j];
				else
					dp[(i + 1) * (w + 1) + j] = chmin(dp[(i + 1) * (w + 1) + j], dp[i * (w + 1) + j]);
			}
			if (j >= num_array[i] && dp[i * (w + 1) + j - num_array[i]] >= 0)
			{
				if (dp[(i + 1) * (w + 1) + j] == -1)
					dp[(i + 1) * (w + 1) + j] = dp[i * (w + 1) + j - num_array[i]] + 1;
				else
					dp[(i + 1) * (w + 1) + j] = chmin(dp[(i + 1) * (w + 1) + j], dp[i * (w + 1) + j - num_array[i]] + 1);
			}
			j++;
		}
		i++;
	}
	print_dp(dp, w, size_of_array);
	if (dp[(w + 1) * (size_of_array + 1) - 1] <= k && 0 <= dp[(w + 1) * (size_of_array + 1) - 1])
		printf("Yes, %d\n", dp[(w + 1) * (size_of_array + 1) - 1]);
	else
		printf("No\n");
	free(num_array);
	num_array = NULL;
	free(dp);
	dp = NULL;
	return (0);
}
