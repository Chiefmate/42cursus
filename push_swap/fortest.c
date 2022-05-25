/*  internal use
 *  SHOULD BE DELETED WHEN SUBMITTING
 */

#include "push_swap.h"

/*  stack print function
 */

void    print_stack(t_stack *a, t_stack *b)
{
    int     count;
    t_node  *temp_a;
    t_node  *temp_b;
    int     num_a;
    int     num_b;

    count = a->count;
    if (count < b->count)
        count = b->count;
    temp_a = a->head;
    temp_b = b->head;
    for (int i = 0; i < count; i++)
    {
        if (!temp_a && !temp_b)
            printf(" \t \n");
        else if (!temp_a)
        {
            num_b = temp_b->data;
            temp_b = temp_b->next;
            printf(" \t%d\n", num_b);
        }
        else if (!temp_b)
        {
            num_a = temp_a->data;
            temp_a = temp_a->next;
            printf("%d\t \n", num_a);
        }
        else
        {
            num_a = temp_a->data;
            temp_a = temp_a->next;
            num_b = temp_b->data;
            temp_b = temp_b->next;
            printf("%d\t%d\n", num_a, num_b);
        }
    }
    printf("-\t-\na\tb\n%d\t%d\n", a->count, b->count);
    
    printf("-------------------------\n");
    return ;
}