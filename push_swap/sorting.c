
#include "push_swap.h"

void    sml_sort(t_stack *a, t_stack *b, int n)
{
    if (n == 2)
    {
        if (a->head->data > a->head->next->data)
            swap(a);
        return ;
    }
    if (a->head->data > a->head->next->data)
    {
        
    }
}