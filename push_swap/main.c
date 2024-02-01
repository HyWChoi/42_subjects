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

int main(int argc, char *argv[])
{
	t_deque dq_a;
	t_deque dq_b;
	int i;

	i = 0;
	init_dq_a_b(&dq_a, &dq_b, argc, argv);
	watch_dq_a_b_state(&dq_a, &dq_b, argc);
	i=is_sorted(&dq_a, argc);
	if (is_sorted(&dq_a, 4) == TRUE)
		ft_printf("sorted TRUE");
	else
		ft_printf("sorted FALSE");
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
