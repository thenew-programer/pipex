/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:17:49 by ybouryal          #+#    #+#             */
/*   Updated: 2024/10/26 11:31:21 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;

	if (*lst == NULL || !del)
		return ;
	while (*lst)
	{
		cur = (*lst);
		(*lst) = (*lst)->next;
		ft_lstdelone(cur, del);
	}
	*lst = NULL;
}
