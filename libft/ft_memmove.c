/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:54:53 by ybouryal          #+#    #+#             */
/*   Updated: 2024/10/24 17:28:20 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)dest;
	tmp2 = (unsigned char *)src;
	if (dest >= src)
	{
		while (n--)
			tmp1[n] = tmp2[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
