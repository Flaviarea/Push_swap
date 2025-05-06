#include "push_swap.h"

void	rrb(t_node **b);
void	reverse_rotate_stack(t_node **stack);
void	rrr(t_node **a, t_node **b);

void	rra(t_node **a)
{
	t_node	*prev;
	t_node	*last;

	if (*a && (*a)->next)
	{
		prev = NULL;
		last = *a;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *a;
		*a = last;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_node **b)
{
	t_node	*prev;
	t_node	*last;

	if (*b && (*b)->next)
	{
		prev = NULL;
		last = *b;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *b;
		*b = last;
		write(1, "rrb\n", 4);
	}
}

void	reverse_rotate_stack(t_node **stack)
{
	t_node *prev = NULL;
	t_node *last = *stack;

	if (*stack && (*stack)->next)
	{
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	write(1, "rrr\n", 4);
}
