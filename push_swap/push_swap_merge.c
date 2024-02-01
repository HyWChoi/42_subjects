#include "push_swap_merge.h"
// divide from asc
// divide from desc
// merge from asc
// merge from desc

void	make_desc_dq_a(t_deque *start, t_deque *dest, size_t size)
{
	//size = 3
	int i;

	i = 0;
	if (is_first_bigger_second(start, size))
		sa(start, size);
	if (is_sorted(start, size))
		while (i < size)
			pb(start, dest, size);
}

// void	divide_triple_dq(t_deque *target, size_t size)
// {
// 	size_t	pivot;
// 	int		i;

// 	i = 0;
// 	pivot = size / 3;
// 	if (size < 9)
// 		return ;
// 	else
// 	{
// 		divide_triple_dq(target, pivot);
// 		divide_triple_dq(target, pivot + size % 3);
// 		divide_triple_dq(target, pivot);
// 		while (i < )
// 	}
// }
