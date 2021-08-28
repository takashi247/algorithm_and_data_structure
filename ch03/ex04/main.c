#include <stdio.h>
#include <stdlib.h>

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
	find_min(int *num_array, const int size_of_array)
{
	int	min;
	int	i;

	i = 0;
	min = num_array[i];
	while (i < size_of_array)
	{
		if (num_array[i] < min)
			min = num_array[i];
		i++;
	}
	return (min);
}

static int
	find_max(int *num_array, const int size_of_array)
{
	int	max;
	int	i;

	i = 0;
	max = num_array[i];
	while (i < size_of_array)
	{
		if (max < num_array[i])
			max = num_array[i];
		i++;
	}
	return (max);
}

int
	main(int ac, char **av)
{
	int			min;
	int			max;
	int			*num_array;
	const int	size_of_array = ac - 1;

	if (size_of_array <= 1)
		return (1);
	num_array = (int *)malloc(sizeof(int) * size_of_array);
	if (!num_array)
		return (1);
	store_nums(num_array, size_of_array, ++av);
	min = find_min(num_array, size_of_array);
	max = find_max(num_array, size_of_array);
	printf("maximum difference: %d\n", max - min);
	free(num_array);
	num_array = NULL;
	return (0);
}
