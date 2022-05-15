
#include "push_swap.h"

/*
 *  Sort top n numbers of stack a in ascending order, using empty stack b (Even if b is not empty, consider it as empty)
 *  Always results in sorted stack a, and empty stack b (if b was not empty, the data remains the same as before)
 *  Do nothing if n <= 1
 *  cnt[0], [1], [2] is equal to a_cnt, b_cnt, c_cnt, respectively
 * 
 */ 

void dqsort(t_stack *a, t_stack *b, int n)
{
    t_node  *lp;
    t_node  *rp;
    t_node  *curr;
    int     i;
    int     cnt[3];

    if (n <= 1)
        return ;

    if (n == 2)
    {
        if (a->head->data > a->head->next->data)
            swap(a);
        return ;
    }
    if (n <= 5)
    {
        small_sort(a, b, n);
        return ;
    }
    lp = a->head;
    rp = a->head;
    i = 0;
    while (++i < n)
        rp = rp->next;
    if (lp->data > rp->data)
    {
        curr = lp;
        lp = rp;
        rp = curr;
    }
    curr = a->head;

    cnt[0] = 0;
    cnt[1] = 0;
    cnt[2] = 0;
    i = -1;
    while (++i < n)
    {
        if (curr->data < lp->data)
        {
            push(b, a);
            cnt[0]++;
        }
        else if (lp->data <= curr->data && curr->data <= rp->data)
        {
            rotate(a);
            cnt[1]++;
        }
        else
        {
            push(b, a);
            rotate(b);
            cnt[2]++;
        }
    }

    i = -1;
    while (++i < cnt[2])
        rev_rotate(b);
    dqsort_rev(b, a, cnt[2]);
    i = -1;
    while (++i < cnt[2])
        push(a, b);
    
    i = -1;
    while (++i < cnt[1])
        rev_rotate(a);
    dqsort(a, b, cnt[1]);
    
    dqsort_rev(b, a, cnt[0]);
    i = -1;
    while (++i < cnt[0])
        push(a, b);
    
    print_stack(a, b);
}

/*
 *  Sort top n numbers of stack a in descending order, using empty stack b (Even if b is not empty, consider it as empty)
 *  Always results in sorted stack a, and empty stack b (if b was not empty, the data remains the same as before)
 *  Do nothing if n <= 1
 *  cnt[0], [1], [2] is equal to a_cnt, b_cnt, c_cnt, respectively
 * 
 */ 

void dqsort_rev(t_stack *a, t_stack *b, int n)
{
    t_node  *lp;
    t_node  *rp;
    t_node  *curr;
    int     i;
    int     cnt[3];

    if (n <= 1)
        return ;

    if (n == 2)
    {
        if (a->head->data > a->head->next->data)
            swap(a);
        return ;
    }
    
    if (n <= 5)
    {
        small_sort_rev(a, b, n);
        return ;
    }
    lp = a->head;
    rp = a->head;
    i = 0;
    while (i++ < n - 1)
        rp = rp->next;
    if (lp->data > rp->data)
    {
        curr = lp;
        lp = rp;
        rp = curr;
    }

    curr = a->head;

    cnt[0] = 0;
    cnt[1] = 0;
    cnt[2] = 0;
    i = 0;
    while (i++ < n)
    {
        if (curr->data < lp->data)
        {
            push(b, a);
            cnt[0]++;
        }
        else if (lp->data <= curr->data && curr->data <= rp->data)
        {
            rotate(a);
            cnt[1]++;
        }
        else
        {
            push(b, a);
            rotate(b);
            cnt[2]++;
        }
    }
    dqsort(b, a, cnt[0]);
    i = 0;
    while (i++ < cnt[0])
        push(a, b);
    
    i = 0;
    while (i++ < cnt[1])
        rev_rotate(a);
    dqsort_rev(a, b, cnt[1]);
    
    i = 0;
    while (i++ < cnt[2])
        rev_rotate(b);
    dqsort(b, a, cnt[2]);
    i = 0;
    while (i++ < cnt[2])
        push(a, b);
}

void    small_sort(t_stack *a, t_stack *b, int n)
{
    int     i;
    int     key;
    int     cnt;

    i = -1;
    while (++i < n)
    {
        cnt = 0;
        key = find_smallest_data(a, n - i);
        printf("key:%d\n", key);
        while (key != a->head->data && cnt < n - 1)
        {
            rotate(a);
            cnt++;
        }
        push(b, a);
        while (--cnt >= 0)
            rev_rotate(a);
        printf("Current\n");
        print_stack(a, b);
    }
    i = 0;
    while (++i <= n)
        push (a, b);
}

int find_smallest_data(t_stack *a, int n)
{
    int     ret;
    t_node  *curr;
    int     i;

    if (n == 0)
        return (0);
    ret = a->head->data;
    curr = a->head;
    i = 0;
    while (++i <= n)
    {
        curr = curr->next;
        if (ret > curr->data)
            ret = curr->data;
    }
    return (ret);
}

int find_biggest_data(t_stack *a, int n)
{
    int     ret;
    t_node  *curr;
    int     i;

    ret = a->head->data;
    curr = a->head;
    i = 1;
    while (i++ < n)
    {
        curr = curr->next;
        if (ret < curr->data)
            ret = curr->data;
    }
    return (ret);
}