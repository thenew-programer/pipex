/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:50:21 by ybouryal          #+#    #+#             */
/*   Updated: 2024/10/22 16:53:15 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*str;
	unsigned char		*tmp;
	size_t				i;

	str = (const unsigned char *)src;
	tmp = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		tmp[i] = str[i];
		i++;
	}
	return (dest);
}
