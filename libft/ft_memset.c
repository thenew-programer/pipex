/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:38:21 by ybouryal          #+#    #+#             */
/*   Updated: 2024/10/22 18:38:22 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	c = (unsigned char)c;
	tmp = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		tmp[i] = c;
		i++;
	}
	return (dest);
}
