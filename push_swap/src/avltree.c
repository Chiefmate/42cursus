/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avltree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:01:41 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/04 12:09:32 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* AVL Tree to pick left pivot and right pivot */

#include "../include/push_swap.h"

int	max(int a, int b)
{
	return ((a > b) ? a : b);
}

t_trnode	*new_node(int val)
{
	t_trnode	*ret;

	ret = (t_trnode *)malloc(sizeof(t_trnode));
	ret->val = val;
	ret->height = 1;
	ret->left = NULL;
	ret->right = NULL;
	return (ret);
}

t_trnode	*right_rotate(t_trnode *root)
{
	t_trnode	*lt;
	t_trnode	*lrt;

	lt = root->left;
	lrt = lt->right;
	lt->right = root;
	root->left = lrt;
	root->height = 1 + max(root->left->height, root->right->height);
	lt->height = 1 + max(lt->left->height, lt->right->height);
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
	root->height = 1 + max(root->left->height, root->right->height);
	rt->height = 1 + max(rt->left->height, rt->right->height);
	return (rt);
}
