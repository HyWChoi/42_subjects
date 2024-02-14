void	merge_desc_2_b(t_deque *dq_a, t_deque *dq_b,int depth, int amt, int *amt_lst, int i)
{
	int k;
	element dq_b_rear;
	element dq_a_front;
	element dq_a_rear;
	k = 0;
	dq_b_rear = amt_lst[0 + i];
	dq_a_front = amt_lst[ft_pow(3, depth - 1) + i + 1];
	dq_a_rear = amt_lst[ft_pow(3, depth) - i - 1];
	// ft_printf("dq_b_rear: %d, dq_a_front: %d, dq_a_rear: %d\n", dq_b_rear, dq_a_front, dq_a_rear);
	while (k++ < amt)
	{
		// ft_printf("dq_b_rear: %d, dq_a_front: %d, dq_a_rear: %d\n", dq_b_rear, dq_a_front, dq_a_rear);
		if (dq_b_rear > 0 && dq_a_front > 0 && dq_a_rear > 0)
		{
			if (!is_rear_bigger_opposite_front(dq_b, dq_a))
			{
				if (!is_rear_bigger_opposite_rear(dq_b, dq_a))
				{
					rrb(dq_b, dq_b->size);
					dq_b_rear--;
				}
				else
				{
					rra(dq_a, dq_a->size);
					pb(dq_a, dq_b, dq_a->size);
					dq_a_rear--;
				}
			}
			else
			{
				if (!is_first_bigger_last(dq_a, dq_a->size))
				{
					pb(dq_a, dq_b, dq_a->size);
					dq_a_front--;
				}
				else
				{
					rra(dq_a, dq_a->size);
					pb(dq_a, dq_b, dq_a->size);
					dq_a_rear--;
				}
			}
		}
		else if (dq_b_rear <= 0 && dq_a_front > 0 && dq_a_rear > 0)
		{
			if (!is_first_bigger_last(dq_a, dq_a->size))
			{
				pb(dq_a, dq_b, dq_a->size);
				dq_a_front--;
			}
			else
			{
				rra(dq_a, dq_a->size);
				pb(dq_a, dq_b, dq_a->size);
				dq_a_rear--;
			}
		}
		else if (dq_b_rear > 0 && dq_a_front <= 0 && dq_a_rear > 0)
		{
			if (!is_rear_bigger_opposite_rear(dq_b, dq_a))
			{
				rrb(dq_b, dq_a->size);
				dq_b_rear--;
			}
			else
			{
				rra(dq_a, dq_a->size);
				pb(dq_a, dq_b, dq_a->size);
				dq_a_rear--;
			}
		}
		else if (dq_b_rear > 0 && dq_a_front > 0 && dq_a_rear <= 0)
		{
			if (!is_rear_bigger_opposite_front(dq_a, dq_b))
			{
				rra(dq_a, dq_a->size);
				dq_b_rear--;
			}
			else
			{
				pa(dq_a, dq_b, dq_a->size);
				dq_a_front--;
			}
		}
		else if (dq_b_rear <= 0 && dq_a_front <= 0 && dq_a_rear > 0)
		{
			rra(dq_a, dq_a->size);
			pb(dq_a, dq_b, dq_a->size);
			dq_a_rear--;
		}
		else if (dq_b_rear <= 0 && dq_a_front > 0 && dq_a_rear <= 0)
		{
			pb(dq_a, dq_b, dq_a->size);
			dq_a_front--;
		}
		else if (dq_b_rear > 0 && dq_a_front <= 0 && dq_a_rear <= 0)
		{
			rrb(dq_b, dq_b->size);
			dq_b_rear--;
		}
	}
}
