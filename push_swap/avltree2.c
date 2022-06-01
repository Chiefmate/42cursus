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

/*
 *  중복 시 삽입 X
 */
t_trnode    *insert(t_trnode *root, int val)
{
    if (!root)
        return (new_node(val));
    if (val > root->val)
        root->right = insert(root->right, val);
    else if (val < root->val)
        root->left = insert(root->left, val);
    else
        return (root);
    root->height = 1 + max(root->left->height, root->right->height);
    root = rebalance(root);
    return (root);
}

/*
 *  삭제
 */
t_trnode    *delete(t_trnode *root, int val)
{
    if (!root)
        return (0);
    if (val > root->val)
        root->right = delete(root->right, val);
    else if (val < root->val)
        root->left = delete(root->left, val);
    else
        return (root);
    root->height = 1 + max(root->left->height, root->right->height);
    root = rebalance(root);
    return (root);
}