#include "push_swap.h"

void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
void	sort_three(t_node **a);
void	ra(t_node **a);

void	rr(t_node **a, t_node **b)
{
	rotate_stack(a);
	rotate_stack(b);
	write (1, "rr\n", 3);
}

void	ra(t_node **a)
{
	t_node	*tmp;
	t_node	*last;
	
	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		last = *a;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
		write(1, "ra\n", 3);
	}
}

void	sort_three(t_node **a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_four(t_node **a, t_node **b)
{
	int	min;

	min = get_min(*a);
	while ((*a)->value != min)
		ra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_node **a, t_node **b)
{
	int	min;
	int	i;

	i = 0;
	while (i < 2)
	{
		min = get_min(*a);
		while ((*a)->value != min)
			ra(a);
		pb(a, b);
		i++;
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
