/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   js_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:09:48 by joonpark          #+#    #+#             */
/*   Updated: 2021/08/14 13:40:46 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	count_str(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
		{
			++count;
			while (*s && *s != c)
				++s;
		}
	}
	return (count);
}

static void	ft_strncpy(char *dest, const char *src, int n)
{
	while (*src && n > 0)
	{
		*dest = *src;
		++dest;
		++src;
		--n;
	}
	*dest = '\0';
}

static char	**make_ret(char const *s, char c)
{
	char	**ret;
	size_t	tot;

	if (!s)
		return (NULL);
	tot = count_str(s, c);
	ret = (char **)malloc(sizeof(char *) * (tot + 1));
	if (!ret)
		return (NULL);
	return (ret);
}

char	**js_split(char const *s, char c)
{
	const char	*cur;
	char		**ret;
	size_t		idx;

	ret = make_ret(s, c);
	if (!ret)
		return (NULL);
	idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			cur = s;
			while (*s && *s != c)
				++s;
			ret[idx] = (char *)malloc(sizeof(char) * (s - cur + 1));
			ft_strncpy(ret[idx++], cur, (s - cur));
		}
		if (!*s)
			break ;
		++s;
	}
	ret[idx] = 0;
	return (ret);
}
