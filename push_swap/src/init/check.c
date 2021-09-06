/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:50:08 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/01 21:38:23 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	make_integer(LLINT *a, char **arg, int *k)
{
	int		i;
	t_nbr	tmp;

	i = 0;
	while (arg[i] != NULL)
	{
		tmp = js_strnbr(arg[i]);
		if (tmp.val < INT_MIN || tmp.val > INT_MAX)
			return (error(""));
		if (tmp.res < 0)
			return (error(""));
		a[*k] = tmp.val;
		++*k;
		++i;
	}
	return (1);
}

static LLINT	*helper(char ***strs, int size)
{
	LLINT	*a;
	int		k;
	int		idx;
	int		ret;

	a = (LLINT *)malloc(sizeof(LLINT) * size);
	k = 0;
	idx = 0;
	while (strs[idx] != NULL)
	{
		ret = make_integer(a, strs[idx], &k);
		if (ret < 0)
		{
			free(a);
			return (ptr_error(""));
		}
		++idx;
	}
	return (a);
}

static	LLINT	*check_helper(t_arr *numbers, char ***strs)
{
	int		size;
	LLINT	*ret;

	size = find_strs_lenfth(strs);
	ret = helper(strs, size);
	free_strs(strs);
	if (ret == NULL)
		return (ptr_error(""));
	if (check_duplicate(ret, size) < 0)
	{
		free(ret);
		return (ptr_error(""));
	}
	numbers->arr = ret;
	numbers->size = size;
	return (ret);
}

LLINT	*check(t_arr *numbers, int argc, char *argv[])
{
	char	***strs;
	int		idx;
	LLINT	*ret;

	strs = (char ***)malloc(sizeof(char **) * argc);
	if (strs == NULL)
		return (ptr_error(""));
	idx = 0;
	while (++idx < argc)
		strs[idx - 1] = js_split(argv[idx], ' ');
	strs[idx - 1] = NULL;
	ret = check_helper(numbers, strs);
	if (ret == NULL)
		return (ptr_error(""));
	return (ret);
}
