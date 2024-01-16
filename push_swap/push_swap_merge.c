#include "push_swap_merge.h"

/**
 * void    push_asc_a2b(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size);
 * void    push_desc_a2b(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size);
 * void    push_asc_b2a(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size);
 * void    push_desc_b2a(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size);
*/

void	divide_triangle(t_deque *start, t_deque *dest, size_t size, int depth)
{
    if (size > 6)
    {
        if (depth % 2 == 0)
        {
            make_triangles_a2b(start, dest, size);
            ft_printf("\ndepth: %d\n", depth);
            watch_dq_a_b_state(start, dest, size);
            divide_triangle(start, dest, size / 3, depth + 1);
        }
        else
        {
            make_triangles_b2a(start, dest, size);
            ft_printf("\ndepth: %d\n", depth);
            watch_dq_a_b_state(start, dest, size);
            divide_triangle(start, dest, size / 3, depth + 1);
        }
    }
}

void    make_triangles_a2b(t_deque *dq_a, t_deque *dq_b, size_t size)
{
    int target_size;

    target_size = size / 3;
    push_desc_a2b(dq_a, dq_b, size, target_size);
    push_asc_a2b(dq_a, dq_b, size, target_size + size % 3);
    push_asc_a2b(dq_a, dq_b, size, target_size);
}

void    make_triangles_b2a(t_deque *dq_a, t_deque *dq_b, size_t size)
{
    int target_size;

    target_size = size / 3;
    push_desc_b2a(dq_a, dq_b, size, target_size);
    push_asc_b2a(dq_a, dq_b, size, target_size + size % 3);
    push_asc_b2a(dq_a, dq_b, size, target_size);
}

void	push_asc_a2b(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size)
{
	size_t i;

	i = 0;
	while (i++ < target_size)
	{
		if (is_first_bigger_second(dq_a, size) == TRUE)
		{
			if (is_first_bigger_second(dq_b, size) == FALSE)
				ss(dq_a, dq_b, size);
			else
				sa(dq_a, size);
		}
        else if(is_first_bigger_second(dq_b, size) == FALSE)
            sb(dq_b, size);
		pb(dq_a, dq_b, size);
        watch_dq_a_b_state(dq_a, dq_b, size);
	}
}

void	push_asc_b2a(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size)
{
	size_t i;

	i = 0;
	while (i++ < target_size)
	{
		if (is_first_bigger_second(dq_b, size) == TRUE)
		{
			if (is_first_bigger_second(dq_a, size) == FALSE)
				ss(dq_a, dq_b, size);
			else
				sa(dq_a, size);
		}
        else if(is_first_bigger_second(dq_a, size) == FALSE)
			sb(dq_b, size);
        pa(dq_a, dq_b, size);
        watch_dq_a_b_state(dq_a, dq_b, size);
	}
}

void	push_desc_a2b(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size)
{
	size_t i;

	i = 0;
	while (i++ < target_size)
	{
		if (is_first_bigger_second(dq_a, size) == FALSE)
		{
			if (is_first_bigger_second(dq_b, size) == TRUE)
				ss(dq_a, dq_b, size);
			else
				sa(dq_a, size);
		}
		pb(dq_a, dq_b, size);
	}
}

void	push_desc_b2a(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size)
{
	size_t i;

	i = 0;
	while (i++ < target_size)
	{
		if (is_first_bigger_second(dq_b, size) == TRUE)
		{
			if (is_first_bigger_second(dq_a, size) == FALSE)
				ss(dq_a, dq_b, size);
			else
				sa(dq_a, size);
		}
		pa(dq_a, dq_b, size);
	}
}
