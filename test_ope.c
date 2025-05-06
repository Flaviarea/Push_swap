#include "push_swap.h"
#include <string.h> // per strcmp

void prepare_stack(t_node **a, t_node **b)
{
    *a = NULL;
    *b = NULL;
    add_node(a, 3);
    add_node(a, 2);
    add_node(a, 1);
    add_node(b, 6);
    add_node(b, 5);
    add_node(b, 4);
}

void print_both(t_node *a, t_node *b)
{
    printf("Stack A: ");
    print_stack(a);
    printf("Stack B: ");
    print_stack(b);
}

int main(int argc, char **argv)
{
    t_node *a;
    t_node *b;

    if (argc != 2)
    {
        printf("Usage: %s <operation>\n", argv[0]);
        return (1);
    }

    prepare_stack(&a, &b);
    printf("Before %s:\n", argv[1]);
    print_both(a, b);

    if (strcmp(argv[1], "sa") == 0)
        sa(&a);
    else if (strcmp(argv[1], "sb") == 0)
        sb(&b);
    else if (strcmp(argv[1], "ss") == 0)
        ss(&a, &b);
    else if (strcmp(argv[1], "pa") == 0)
        pa(&a, &b);
    else if (strcmp(argv[1], "pb") == 0)
        pb(&a, &b);
    /*else if (strcmp(argv[1], "ra") == 0)
        ra(&a);
    else if (strcmp(argv[1], "rb") == 0)
        rb(&b);
    else if (strcmp(argv[1], "rr") == 0)
        rr(&a, &b);
    else if (strcmp(argv[1], "rra") == 0)
        rra(&a);
    else if (strcmp(argv[1], "rrb") == 0)
        rrb(&b);
    else if (strcmp(argv[1], "rrr") == 0)
        rrr(&a, &b);
        */
    else
    {
        printf("Invalid operation\n");
        return (1);
    }

    printf("\nAfter %s:\n", argv[1]);
    print_both(a, b);
    free_stack(&a);
    free_stack(&b);
    return (0);
}
