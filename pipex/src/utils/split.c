/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:13:30 by joonpark          #+#    #+#             */
/*   Updated: 2021/07/21 16:45:09 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <unistd.h>
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
			{
				if (*s == '\'')
				{
					++s;
					while (*s && *s != '\'')
						++s;
				}
				++s;
			}
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

static void	helper(const char *s, const char *cur, char **ret, char c)
{
	size_t	idx;

	idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			cur = s;
			if (*s && *s == '\'')
			{
				++cur;
				++s;
				while (*s && *s != '\'')
					++s;
			}
			while (*s && *s != c && *s != '\'')
				++s;
			ret[idx] = (char *)malloc(sizeof(char) * (s - cur + 1));
			ft_strncpy(ret[idx++], cur, (s - cur));
		}
		if (!*s)
			break ;
		++s;
	}
	ret[idx] = 0;
}

char	**ft_split(char const *s, char c)
{
	const char	*cur;
	char		**ret;

	ret = make_ret(s, c);
	if (!ret)
		return (NULL);
	helper(s, cur, ret, c);
	return (ret);
}
