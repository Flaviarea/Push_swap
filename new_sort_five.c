void	sort_five(t_node **a, t_node **b)
{
	int		min;
	int		i;
	t_node	*curr;
	int		pos;

	i = 0;
	while (i < 2)
	{
		min = get_min(*a);
		pos = 0;
		curr = *a;
		while (curr->value != min)
		{
			curr = curr->next;
			pos++;
		}
		while ((*a)->value != min)
		{
			if (pos <= 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
		i++;
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
