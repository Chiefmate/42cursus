/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avltree2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:35:38 by marvin            #+#    #+#             */
/*   Updated: 2022/05/26 15:35:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* AVL Tree to pick left pivot and right pivot */

#include "push_swap.h"

t_trnode    *rebalance(t_trnode *root)
{
    int bf;

    bf = get_balance_factor(root);
    
    //  LL
    if (bf > 1 && root->val < root->left->val)
        return (right_rotate(root));
    //  RR
    if (bf < -1 && root->val > root->right->val)
        return (left_rotate(root));
    //  LR
    if (bf > 1 && root->val > root->left->val)
    {
        root->left = left_rotate(root->left);
        return (right_rotate(root));
    }
    //  RL
    if (bf < -1 && root->val < root->right->val)
    {
        root->right = right_rotate(root->right);
        return (left_rotate(root));
    }
    return (root);
}

int get_balance_factor(t_trnode *root)
{
    if (!root)
        return (0);
    if (!(root->left) && !(root->right))
        return (0);
    else if (!(root->left))
        return (-(root->right->height));
    else if (!(root->right))
        return (root->left->height);
    else
        return (root->left->height - root->right->height);
}

/*
 *  중복 시 삽입 X
 */
t_trnode    *avl_insert(t_trnode *root, int val)
{
    if (!root)
        return (new_node(val));
    if (val > root->val)
        root->right = avl_insert(root->right, val);
    else if (val < root->val)
        root->left = avl_insert(root->left, val);
    else
        return (root);
    root->height = 1 + max(root->left->height, root->right->height);
    root = rebalance(root);
    return (root);
}

/*
 *  삭제
 */
t_trnode    *avl_delete(t_trnode *root, int val)
{
    if (!root)
        return (0);
    if (val > root->val)
        root->right = avl_delete(root->right, val);
    else if (val < root->val)
        root->left = avl_delete(root->left, val);
    else
        return (root);
    root->height = 1 + max(root->left->height, root->right->height);
    root = rebalance(root);
    return (root);
}