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
	find_second_min(int *num_array, const int size_of_array)
{
	int	min;
	int	second_min;
	int	i;

	i = 0;
	min = num_array[i];
	second_min = num_array[i];
	while (i < size_of_array)
	{
		if (num_array[i] < min)
		{
			second_min = min;
			min = num_array[i];
		}
		else if (num_array[i] < second_min || min == second_min)
			second_min = num_array[i];
		i++;
	}
	return (second_min);
}

int
	main(int ac, char **av)
{
	int			second_min;
	int			*num_array;
	const int	size_of_array = ac - 1;

	if (size_of_array <= 1)
		return (1);
	num_array = (int *)malloc(sizeof(int) * size_of_array);
	if (!num_array)
		return (1);
	store_nums(num_array, size_of_array, ++av);
	second_min = find_second_min(num_array, size_of_array);
	printf("second minimum number: %d\n", second_min);
	free(num_array);
	num_array = NULL;
	return (0);
}