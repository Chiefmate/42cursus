/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avltree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:01:41 by hyunhole          #+#    #+#             */
/*   Updated: 2022/05/26 13:01:41 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* AVL Tree to pick left pivot and right pivot */

#include "push_swap.h"

t_trnode	*right_rotate(t_trnode *root)
{
	t_trnode	*lt;
	t_trnode	*lrt;

	lt = root->left;
	lrt = lt->right;
	lt->right = root;
	root->left = lrt;
	return (lt);
}

t_trnode	*left_rotate(t_trnode *root)
{
	t_trnode	*rt;
	t_trnode	*rlt;

	rt = root->right;
	rlt = root->left;
	rt->left = root;
	root->right = rlt;
	return (rt);
}

t_trnode	*rebalance(t_trnode *root)
{
	int	bf;

	bf = get_balance_factor(root);
	if (bf )
}

int	get_balance_factor(t_trnode *root)
{
	if (!root)
		return (0);
	if (!(root->left) && !(root->right))
		return (0);
	else if (!(root->right))
		return (root->left->height);
	else if (!(root->left))
		return (-(root->right->height));
	else
		return (root->left->height - root->left->height);
}