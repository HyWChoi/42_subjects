#include "push_swap_merge.h"
#include <stdio.h>

void	init_dq_a_b(t_deque *dq_a, t_deque *dq_b, int argc, char *argv[])
{
	int i;

	i = 1;
	init_deque(dq_a, argc); //큐의 가장 앞은 항상 검사를 위해 비어있어야 함
	init_deque(dq_b, argc);
	while (i < argc)
	{
		if (ft_is_number(*(argv + i)) == ERROR)
			error_exit(dq_a, dq_b);
		push_rear(dq_a, ft_atoi_push_swap(*(argv + i++), dq_a, dq_b), argc);
		printf("dq_a->data[dq_a->rear]: %d\n", dq_a->data[dq_a->rear]);
	}
}

int	ft_pow(int base, int exp)
{
	int result = 1;

	while (exp > 0)
	{
		result *= base;
		exp--;
	}
	return (result);
}

int	calc_depth(size_t i)
{
	int depth = 1;

	while (ft_pow(3, depth) <= i)
		depth++;
	return (depth - 1);
}

int	calc_dir(int depth, size_t i)
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

size_t	calc_amt(int depth, size_t i, size_t n)
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
int main(int argc, char *argv[])
{
	t_deque dq_a;
	t_deque dq_b;
	int i;

	i = 0;
	init_dq_a_b(&dq_a, &dq_b, argc, argv);
	watch_dq_a_b_state(&dq_a, &dq_b, argc);
	int depth = 0;
	// while (depth < 3)
	// {
	// 	i = 0;
	// 	while (i < ft_pow(3, depth))
	// 	{
	// 		ft_printf("depth: %d, i: %d, calc_dir: %d\n", depth, i, calc_dir(depth, i));
	// 		i++;
	// 	}
	// 	depth++;
	// }
	// depth = 0;
	size_t amt = 1000;
	ft_printf("calc_depth: %d\n", calc_depth(amt));
	while (depth < calc_depth(amt))
	{
		i = 0;
		while (i < ft_pow(3, depth))
		{
			ft_printf("depth: %d, i: %d, calc_amt: %d\n", depth, i, calc_amt(depth, i, amt));
			i++;
		}
		depth++;
	}
	//ft_printf("\n%d\n", find_max(&dq_a, argc));
	//ft_printf("dq_a.front: %d\n", dq_a.front);
	//ft_printf("dq_a.rear: %d\n", dq_a.data[dq_a.rear - 1 % argc]);
	//printf("is_first_bigger_second: %d\n", is_first_bigger_second(&dq_a, argc));
	//printf("is_first_bigger_last: %d\n", is_first_bigger_last(&dq_a, argc));
	//printf("is_first_bigger_second: %d\n", is_first_bigger_second(&dq_b, argc));
	//printf("is_first_bigger_last: %d\n", is_first_bigger_last(&dq_b, argc));
	//push_asc_a2b(&dq_a, &dq_b, argc, 6); //정해진 개수만큼 오름차순으로 push하는 함수 완성!!
	//push_asc_a2b(&dq_a, &dq_b, argc, 3);
	//watch_dq_a_b_state(&dq_a, &dq_b, argc);
	//push_desc_a2b(&dq_a, &dq_b, argc, 3);
	//watch_dq_a_b_state(&dq_a, &dq_b, argc);
	//push_desc_a2b(&dq_a, &dq_b, argc, 3);
	//watch_dq_a_b_state(&dq_a, &dq_b, argc);
	//push_desc_b2a(&dq_a, &dq_b, argc, 7); //정해진 개수만큼 내림차순으로 push하는 함수 완성!!
	//watch_dq_a_b_state(&dq_a, &dq_b, argc);
	//push_desc_a2b(&dq_a, &dq_b, argc, 7); //정해진 개수만큼 내림차순으로 push하는 함수 완성!!
	//watch_dq_a_b_state(&dq_a, &dq_b, argc);
	//push_asc_b2a(&dq_a, &dq_b, argc, 7); //정해진 개수만큼 오름차순으로 push하는 함수 완성!!
	//watch_dq_a_b_state(&dq_a, &dq_b, argc);
	//make_triangles_a2b(&dq_a, &dq_b, argc - 1); //정해진 개수만큼 오름차순으로 push하는 함수 완성!!
	//watch_dq_a_b_state(&dq_a, &dq_b, argc);
	//make_triangles_b2a(&dq_a, &dq_b, argc); //정해진 개수만큼 오름차순으로 push하는 함수 완성!!
	//watch_dq_a_b_state(&dq_a, &dq_b, argc);
	//divide_triangle(&dq_a, &dq_b, argc, 0); //정해진 개수만큼 오름차순으로 push하는 함수 완성!!
	//watch_dq_a_b_state(&dq_a, &dq_b, argc);
	return (0);
}
