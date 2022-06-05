/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:59:47 by hyunhole          #+#    #+#             */
/*   Updated: 2022/05/11 18:59:47 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  for print_stack. SHOULD BE DELETED */
#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>

typedef struct s_node {
    int             data;
    struct s_node   *next;
}   t_node;

typedef struct s_stack {
    int     count;
    t_node  *head;
}   t_stack;

typedef struct s_trnode {
    struct s_trnode *left;
    struct s_trnode *right;
    int             val;
    int             height;
}  t_trnode;

typedef struct s_tree {
    t_trnode    *top;
}  t_tree;

void    print_stack(t_stack *a, t_stack *b);

int     push_top(t_stack *s, int data);
int     push_bottom(t_stack *s, int data);
int     ft_pop(t_stack *s, int *data_out);
t_stack *create_stack(void);
void    destroy_stack(t_stack *s);
int     pop_from_bot(t_stack *s, int *data_out);

int     ft_swap(t_stack *s);
int     ft_push(t_stack *dst, t_stack *src);
int     rotate(t_stack *s);
int     rev_rotate(t_stack *s);

void	sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void    smlsort_case132(t_stack *a);
void    smlsort_case213(t_stack *a);
void    smlsort_case231(t_stack *a);
void    smlsort_case312(t_stack *a);
void    smlsort_case321(t_stack *a);
void    smlsort_b_case312(t_stack *b);
void    smlsort_b_case231(t_stack *b);
void    smlsort_b_case213(t_stack *b);
void    smlsort_b_case132(t_stack *b);
void    smlsort_b_case123(t_stack *b);

void	sml_sort_a(t_stack *a, int r);
void	a_to_b(t_stack *a, t_stack *b, int r);
void	backrotate_ra_rb(t_stack *a, t_stack *b, int num[]);
void	sml_sort_btoa(t_stack *a, t_stack *b, int r);
void	b_to_a(t_stack *a, t_stack *b, int r);

void    select_pivots(t_stack *a, int r, int pivot[]);
void	intarr_sort(int arr[], int begin, int end);
int     is_sorted(t_stack *a, int r);
int     is_sorted_rev(t_stack *b, int r);

int     parse_input(t_stack *a, int argc, char *argv[]);

long long	atoi_with_check(char *s, t_stack *a, char **splitarr);
void	    ft_destroy_split(char **splitarr);

void    ft_error_with_clear(t_stack *a, char **splitarr);
void    ft_error(void);