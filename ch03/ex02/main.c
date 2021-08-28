#include <stdlib.h>
#include <stdio.h>

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
	const int	value = atoi(av[ac - 1]);
	const int	size_of_array = ac - 2;
	int			i;
	int			count;

	if (size_of_array <= 0)
		return (1);
	num_array = (int *)malloc(sizeof(int) * size_of_array);
	if (!num_array)
		return (1);
	store_nums(num_array, size_of_array, ++av);
	i = 0;
	count = 0;
	while (i < size_of_array)
	{
		if (num_array[i] == value)
			count++;
		i++;
	}
	printf("%d\n", count);
	return (0);
}
