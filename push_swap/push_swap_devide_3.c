#include "push_swap_devide.h"

void	decide_triangular(t_deque *dq_a, t_deque *dq_b, int depth, int amt, int dir)
{
		if (dir == 1)
			make_asc_2_b(dq_a, dq_b, amt);
		else
			make_desc_2_b(dq_a, dq_b, amt);
	depth = 0;
}

void	make_triangular(t_deque *dq_a, t_deque *dq_b)
{
	int	i;
	int	depth;
	int	dir;
	int	amt;

	if (dq_a->size == 0)
		return ;
	depth = calc_depth(dq_a->size - 1);
	dq_b->size = dq_a->size;
	i = 0;
	while (i < ft_pow(3, depth))
	{
		dir = calc_dir(depth, i);
		amt = calc_amt(depth, i, dq_a->size - 1);
		decide_triangular(dq_a, dq_b, depth, amt, dir);
		i++;
	}
}
