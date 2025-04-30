#include <stdio.h>
#include "push_swap.h"
//#include "libft.h"

int main(void)
{
    /*
        // test parsing
      // Test ft_isdigit
    printf("ft_is_digit('4') = %d (expected 1)\n", ft_is_digit('4'));
    printf("ft_is_digit('a') = %d (expected 0)\n", ft_is_digit('a'));
    printf("ft_is_digit('0') = %d (expected 1)\n", ft_is_digit('0'));
    printf("ft_is_digit('9') = %d (expected 1)\n", ft_is_digit('9'));
    printf("ft_is_digit(' ') = %d (expected 0)\n", ft_is_digit(' '));
    printf("ft_is_digit('+') = %d (expected 0)\n", ft_is_digit('+'));
  
      // Test ft_atoi_long
      printf("ft_atoi_long(\"42\") = %ld (expected 42)\n", ft_atoi_long("42"));
      printf("ft_atoi_long(\"-42\") = %ld (expected -42)\n", ft_atoi_long("-42"));
      printf("ft_atoi_long(\"2147483647\") = %ld (expected 2147483647)\n", ft_atoi_long("2147483647"));
      printf("ft_atoi_long(\"2147483648\") = %ld (expected > INT_MAX)\n", ft_atoi_long("2147483648"));
  
      // Test ft_is_valid_nbr
      printf("ft_is_valid_nbr(\"123\") = %d (expected 1)\n", ft_is_valid_nbr("123"));
      printf("ft_is_valid_nbr(\"-123\") = %d (expected 1)\n", ft_is_valid_nbr("-123"));
      printf("ft_is_valid_nbr(\"+123\") = %d (expected 1)\n", ft_is_valid_nbr("+123"));
      printf("ft_is_valid_nbr(\"12a3\") = %d (expected 0)\n", ft_is_valid_nbr("12a3"));
      printf("ft_is_valid_nbr(\"2147483648\") = %d (expected 0)\n", ft_is_valid_nbr("2147483648"));
      printf("ft_is_valid_nbr(\"-2147483649\") = %d (expected 0)\n", ft_is_valid_nbr("-2147483649"));
      printf("ft_is_valid_nbr(\"+\") = %d (expected 0)\n", ft_is_valid_nbr("+"));
      printf("ft_is_valid_nbr(\"-\") = %d (expected 0)\n", ft_is_valid_nbr("-"));
    */

    //test stack_utils
    t_node *stack = NULL;

    // Test 1: create_node + add_node
    printf("== Test create_node + add_node ==\n");
    add_node(&stack, 10);
    add_node(&stack, 20);
    add_node(&stack, 30);
    print_stack(stack); // Output atteso: 30 20 10

    // Test 2: ft_error_dup (nessun duplicato)
    printf("\n== Test ft_error_dup (no duplicates) ==\n");
    printf("Duplicates found: %d (expected 0)\n", ft_error_dup(stack));

    // Test 3: ft_error_dup (con duplicato)
    add_node(&stack, 20); // Aggiungiamo un duplicato
    printf("\n== Test ft_error_dup (with duplicate 20) ==\n");
    printf("Duplicates found: %d (expected 1)\n", ft_error_dup(stack));

    // Test 4: print_stack
    printf("\n== Test print_stack ==\n");
    print_stack(stack); // Output atteso: 20 30 20 10

    // Test 5: free_stack
    printf("\n== Test free_stack ==\n");
    free_stack(&stack);
    if (stack == NULL)
        printf("Stack freed successfully\n");
    else
        printf("Error: Stack not freed\n");

    return (0);
}


