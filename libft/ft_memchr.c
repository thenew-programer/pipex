/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:24:17 by ybouryal          #+#    #+#             */
/*   Updated: 2024/10/22 16:39:02 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmp;
	size_t				i;

	i = 0;
	tmp = (const unsigned char *)s;
	c = (unsigned char)c;
	while (i < n)
	{
		if (tmp[i] == c)
			return ((void *)(tmp + i));
		i++;
	}
	return (0);
}
