#include <unistd.h>

void	recursive(int num, int n, int start, int end)
{
	if (end == 10)
	{
	}
	else
	{
		if ()
		write(1, end + '0', 1);
		n--;
		if (n == 0)
		{
			write(1, ", ", 2);
		}
		else
		{
			recursive(num, n, start, end + 1);
			n = num;
			end = start;
			recursive(num, n, start, end);
		}
	}
}

void	ft_print_combn(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		recursive(n, i, i + 1);
		i++;
	}
}

int	main(void)
{
	ft_print_combn(3);
	return (0);
}
