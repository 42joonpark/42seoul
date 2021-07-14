/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:05:51 by joonpark          #+#    #+#             */
/*   Updated: 2021/07/09 13:16:13 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int		ret;

	ret = 0;
	while (s[ret])
		++ret;
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	size_t	idx;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	s1_size = 0;
	while (s1[s1_size])
		++s1_size;
	s2_size = 0;
	while (s2[s2_size])
		++s2_size;
	ret = (char *)malloc(sizeof(char) * (s1_size + s2_size + 2));
	if (!ret)
		return (NULL);
	idx = 0;
	while (*s1)
		ret[idx++] = *s1++;
	ret[idx++] = ' ';
	while (*s2)
		ret[idx++] = *s2++;
	ret[idx] = '\0';
	return (ret);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cur;
	size_t			cnt;

	cnt = 0;
	cur = (unsigned char *)b;
	while (cnt < len)
	{
		*cur = c;
		++cur;
		++cnt;
	}
	return (b);
}
