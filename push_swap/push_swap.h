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

typedef struct s_node {
    int             data;
    struct s_node   *next;
}   t_node;

typedef struct s_stack {
    int     count;
    t_node  *head;
}   t_stack;

int     push_top(t_stack *s, int data);
int     push_bottom(t_stack *s, int data);
int     pop(t_stack *s, int *data_out);
t_stack *create_stack(void);
void    destroy_stack(t_stack *s);

int     swap(t_stack *s);
int     push(t_stack *dst, t_stack *src);
int     rotate(t_stack *s);
int     rev_rotate(t_stack *s);
int     pop_from_bot(t_stack *s, int *data_out);
void    print_stack(t_stack *a, t_stack *b);

