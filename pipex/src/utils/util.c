/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:05:51 by joonpark          #+#    #+#             */
/*   Updated: 2021/07/17 13:56:24 by joonpark         ###   ########.fr       */
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

#include <stdio.h>
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
	while (*s2)
		ret[idx++] = *s2++;
	ret[idx] = '\0';
	return (ret);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && *s1 && n > 0)
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
