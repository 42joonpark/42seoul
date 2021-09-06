/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   js_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:08:19 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/04 10:50:43 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*js_strjoin(const char *s1, const char *s2)
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
