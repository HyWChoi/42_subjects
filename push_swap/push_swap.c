#include "push_swap.h"

void	sa(int *lst)
{
	int temp;

	if (!*lst || !*(lst + 1))
		return ;
	temp = *lst;
	*lst = *(lst + 1);
	*(lst + 1) = *lst;
}
void	sb(int *lst)
{
	int temp;

	if (!*lst || !*(lst + 1))
		return ;
	temp = *lst;
	*lst = *(lst + 1);
	*(lst + 1) = *lst;
}
void	ss(int *lst_a, int *lst_b)
{
	sa(*lst_a);
	sb(*lst_b);
}
void	pa(int *lst_a, int *lst_b)
{
	int	i;

	i = 0;
	while (!*lst_b)
		i++;
}
void	pb()
{}
void	ra()
{}
void	rb()
{}
void	rr()
{}
void	rra()
{}
void	rrb()
{}
void	rrr()
{}
