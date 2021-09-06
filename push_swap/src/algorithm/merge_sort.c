/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 00:26:03 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/01 21:42:51 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
static void	insert_rest(LLINT *arr, t_merge *node, int i, int j)
{
	while (i < node->n1)
	{
		arr[node->k] = node->left[i];
		++i;
		++node->k;
	}
	while (j < node->n2)
	{
		arr[node->k] = node->right[j];
		++j;
		++node->k;
	}
}

static void	init_merge(LLINT *arr, t_merge *node)
{
	int	i;

	i = 0;
	while (i < node->n1)
	{
		node->left[i] = arr[node->l + i];
		++i;
	}
	i = 0;
	while (i < node->n2)
	{
		node->right[i] = arr[node->m + 1 + i];
		++i;
	}
}

static int	do_merge(LLINT *arr, t_merge *node)
{
	int		i;
	int		j;

	init_merge(arr, node);
	i = 0;
	j = 0;
	node->k = node->l;
	while (i < node->n1 && j < node->n2)
	{
		if (node->left[i] <= node->right[j])
		{
			arr[node->k] = node->left[i];
			++i;
		}
		else
		{
			arr[node->k] = node->right[j];
			++j;
		}
		++node->k;
	}
	insert_rest(arr, node, i, j);
	return (1);
}

static int	merge(LLINT *arr, int l, int m, int r)
{
	t_merge	node;
	int		ret;

	node.n1 = m - l + 1;
	node.n2 = r - m;
	node.l = l;
	node.m = m;
	node.r = r;
	node.left = (int *)malloc(sizeof(int) * node.n1);
	if (node.left == NULL)
		return (error(""));
	node.right = (int *)malloc(sizeof(int) * node.n2);
	if (node.right == NULL)
		return (error(""));
	ret = do_merge(arr, &node);
	if (ret < 0)
		return (error(""));
	free(node.left);
	free(node.right);
	return (1);
}

int	merge_sort(LLINT *arr, int l, int r)
{
	int	m;
	int	ret;

	if (l < r)
	{
		m = l + (r - l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		ret = merge(arr, l, m, r);
		if (ret < -1)
			return (error(""));
	}
	return (1);
}
