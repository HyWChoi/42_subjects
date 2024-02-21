#include "push_swap_merge.h"

static void	init_dq_a_b(t_deque *dq_a, t_deque *dq_b, int argc, char *argv[])
{
	int i;
	int k;
	size_t count_split;
	char **split;

	i = 1;
	k = 0;
	count_split = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		while (split[k++])
			count_split++;
		i++;
		k = 0;
		while (split[k])
			free(split[k++]);
		free(split);
		k=0;
	}
	init_deque(dq_a, count_split + 1);
	init_deque(dq_b, count_split + 1);
}

static void	fill_dq_a(t_deque *dq_a, t_deque *dq_b, int argc, char *argv[])
{
	int i;
	int k;
	char **split;

	i = 1;
	k = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		while (split[k])
			push_rear(dq_a, ft_atoi_push_swap(split[k++], dq_a, dq_b), dq_a->size);
		i++;
		k = 0;
		while (split[k])
			free(split[k++]);
		free(split);
		k=0;
	}
}


int main(int argc, char *argv[])
{
	t_deque dq_a;
	t_deque dq_b;
	size_t i;
	int depth;

	i = 0;
	init_dq_a_b(&dq_a, &dq_b, argc, argv);
	fill_dq_a(&dq_a, &dq_b, argc, argv);
	if (count_dq(&dq_a, dq_a.size) == 2)
	{
		if (is_sorted_asc1(&dq_a, dq_a.size))
			return (0);
		else
			sa(&dq_a, dq_a.size);
	}
	depth = calc_depth((&dq_a)->size - 1);
	make_triangular(&dq_a, &dq_b);
	merge_triangle(&dq_a, &dq_b, depth);
	if (depth % 2 == 0)
		while (i++ < dq_a.size - 1)
			pa(&dq_a, &dq_b, dq_a.size);
	return (0);
}
