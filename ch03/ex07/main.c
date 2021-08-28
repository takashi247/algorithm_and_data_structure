#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int
	is_valid_input(char *s)
{
	while (*s)
	{
		if (!('1' <= *s && *s <= '9'))
			return (0);
		s++;
	}
	return (1);
}

static char
	*substr(char *s, int start, size_t len)
{
	size_t	len_s;
	size_t	len_sub;
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	len_s = strlen(s);
	if (len_s <= (size_t)start)
		return (strdup("\0"));
	if (len_s - (size_t)start < len)
		len_sub = len_s - (size_t)start;
	else
		len_sub = len;
	substr = (char *)malloc(sizeof(char) * (len_sub + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len_sub)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

static long long
	compute_num(char *s, int bit, int num_of_slots)
{
	int			i;
	long long	sum;
	int			start;
	char		*num_str;

	sum = 0;
	i = 0;
	while (i <= num_of_slots)
	{
		start = i;
		while (i < num_of_slots && !(bit & (1 << (num_of_slots - i - 1))))
			i++;
		num_str = substr(s, start, i - start + 1);
		if (!num_str)
			return (-1);
		sum += (long long)atoi(num_str);
		free(num_str);
		num_str = NULL;
		i++;
	}
	return (sum);
}

int
	main(int ac, char **av)
{
	int			n;
	char		*s;
	long long	sum;
	int			bit;

	if (ac != 2 && !is_valid_input(av[1]))
		return (1);
	s = av[1];
	n = strlen(s);
	sum = 0;
	bit = 0;
	while (bit < (1 << (n - 1)))
	{
		sum += compute_num(s, bit, n - 1);
		bit++;
	}
	printf("sum: %lld\n", sum);
	return (0);
}
