/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:49:17 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/06 15:35:57 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;

	if (lst)
	{
		while (*lst)
		{
			head = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = head;
		}
	}
	head = NULL;
	lst = NULL;
}
