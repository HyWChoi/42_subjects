#include "push_swap_calcs.h"

int ft_pow(int base, int exp)
{
	int result;

	result = 1;
	if (exp == 0)
		return (1);
	while (exp > 1)
	{
		if (exp % 2 == 0)
		{
			base *= base;
			exp /= 2;
		}
		else
		{
			result *= base;
			exp--;
		}
	}
	return (result * base);
}

int	calc_depth(int i)
{
	int depth = 1;
	int count = 0;
	while (ft_pow(3, depth) <= i)
	{
		depth++;
		count++;
	}
	if (depth == 2)
		return (1);
	return (count - 1);
}

int	calc_dir(int depth, int i)
{
	if (depth == 0)
		return (1);
	if (i < ft_pow(3, depth - 1))
		return (calc_dir(depth - 1, i));
	if (i < ft_pow(3, depth - 1) * 2)
		return (!calc_dir(depth - 1, ft_pow(3, depth - 1) * 2 - 1 - i));
	else
		return (!calc_dir(depth - 1, ft_pow(3, depth - 1) * 3 - 1 - i));
}

int	calc_amt(int depth, int i, int n)
{
	if (depth == 0)
		return (n);
	else if (i < ft_pow(3, depth - 1))
		return (calc_amt(depth - 1, i, n) / 3);
	else if (i < ft_pow(3, depth - 1) * 2)
		return (calc_amt(depth - 1, (2 * ft_pow(3, depth - 1)) - 1 - i, n) / 3 + calc_amt(depth - 1, (2 * ft_pow(3, depth - 1)) - 1 - i, n) % 3);
	else
		return (calc_amt(depth - 1, (3 * ft_pow(3, depth - 1)) - 1 - i, n) / 3);
}
