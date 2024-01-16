#include "push_swap_merge.h"

/**
 * void    push_asc_a2b(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size);
 * void    push_desc_a2b(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size);
 * void    push_asc_b2a(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size);
 * void    push_desc_b2a(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size);
*/

int	divide_triangle(t_deque *start, t_deque *dest, size_t size)
{
	int target_size;
    int i;

    target_size = size / 3;
    i = 0;
    if (i++ % 2 == 0)
    {
        push_asc_a2b(start, dest, size, target_size);
        push_asc_a2b(start, dest, size, target_size + size % 3);
        push_desc_a2b(start, dest, size, target_size);
    }
    else
    {
        push_asc_b2a(start, dest, size, target_size);
        push_asc_b2a(start, dest, size, target_size + size % 3);
        push_desc_b2a(start, dest, size, target_size);
    }
}

void	push_asc_a2b(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size)
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
				sb(dq_b, size);
		}
		pa(dq_a, dq_b, size);
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
			if (is_first_bigger_second(dq_b, size) == FALSE)
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
