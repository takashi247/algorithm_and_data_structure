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
	count_operation(int min)
{
	int				num_operation;

	num_operation = 0;
	while (min % 2 == 0)
	{
		min /= 2;
		num_operation++;
	}
	return (num_operation);
}

int
	main(int ac, char **av)
{
	int			min;
	int			*num_array;
	const int	size_of_array = ac - 1;
	int			i;

	if (size_of_array <= 0)
		return (1);
	num_array = (int *)malloc(sizeof(int) * size_of_array);
	if (!num_array)
		return (1);
	store_nums(num_array, size_of_array, ++av);
	i = 0;
	while (i < size_of_array)
	{
		num_array[i] = count_operation(num_array[i]);
		i++;
	}
	min = find_min(num_array, size_of_array);
	printf("number of divisions by 2: %d\n", min);
	free(num_array);
	num_array = NULL;
	return (0);
}
