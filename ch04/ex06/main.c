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

static int
	check_sum(int size_of_array, int w, int *num_array)
{
	if (size_of_array == 0)
		return (w == 0);
	if (check_sum(size_of_array - 1, w, num_array))
		return (1);
	if (check_sum(size_of_array - 1, w - num_array[size_of_array - 1], num_array))
		return (1);
	else
		return (0);
}

int
	main(int ac, char **av)
{
	int			*num_array;
	const int	w = atoi(av[ac - 1]);
	const int	size_of_array = ac - 2;

	if (size_of_array <= 0)
		return (1);
	num_array = (int *)malloc(sizeof(int) * size_of_array);
	if (!num_array)
		return (1);
	store_nums(num_array, size_of_array, ++av);
	if (check_sum(size_of_array, w, num_array))
		printf("true\n");
	else
		printf("false\n");
	free(num_array);
	num_array = NULL;
	return (0);
}
