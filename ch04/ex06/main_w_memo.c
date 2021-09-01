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
	check_sum(int current_len, int size_of_array, int w, int *num_array, int *memo)
{
	if (current_len == 0)
		return (memo[w * size_of_array + current_len] = (w == 0));
	if (memo[w * size_of_array + current_len] != -1)
		return (memo[w * size_of_array + current_len]);
	if (check_sum(current_len - 1, size_of_array, w, num_array, memo))
		return (memo[w * size_of_array + current_len - 1] = 1);
	if ((0 <= w - num_array[current_len - 1])
		&& check_sum(current_len - 1, size_of_array, w - num_array[current_len - 1], num_array, memo))
		return (memo[(w - num_array[current_len - 1]) * size_of_array + current_len - 1] = 1);
	else
		return (0);
}

int
	main(int ac, char **av)
{
	int			*num_array;
	const int	w = atoi(av[ac - 1]);
	const int	size_of_array = ac - 2;
	int			*memo;
	int			current_len;

	if (size_of_array <= 0)
		return (1);
	num_array = (int *)malloc(sizeof(int) * size_of_array);
	memo = (int *)malloc(sizeof(int) * (w + 1) * (size_of_array + 1));
	if (!num_array || !memo)
		return (1);
	memset(memo, -1, sizeof(int) * (w + 1) * (size_of_array + 1));
	store_nums(num_array, size_of_array, ++av);
	current_len = size_of_array;
	if (check_sum(current_len, size_of_array, w, num_array, memo))
		printf("true\n");
	else
		printf("false\n");
	free(num_array);
	num_array = NULL;
	free(memo);
	memo = NULL;
	return (0);
}
