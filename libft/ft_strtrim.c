/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:55:54 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/11 16:02:45 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		++set;
	}
	return (0);
}

static int	get_front(char const *s, char const *set, int back)
{
	int	idx;

	idx = 0;
	while (s[idx] && idx < back && isinset(set, s[idx]))
		++idx;
	return (idx);
}

static int	get_back(char const *s, char const *set)
{
	int	idx;

	idx = ft_strlen(s) - 1;
	while (idx >= 0 && isinset(set, s[idx]))
		--idx;
	return (idx);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		front;
	int		back;
	int		idx;
	char	*ret;

	if (!s1)
		return (NULL);
	back = get_back(s1, set);
	front = get_front(s1, set, back);
	ret = (char *)malloc(sizeof(char) * ((back - front) + 2));
	if (!ret)
		return (NULL);
	idx = 0;
	while (idx <= (back - front))
	{
		ret[idx] = s1[front + idx];
		++idx;
	}
	ret[idx] = '\0';
	return (ret);
}
