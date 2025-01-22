/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:57:56 by ybouryal          #+#    #+#             */
/*   Updated: 2024/10/22 21:14:54 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_overflow(size_t x, size_t y)
{
	long long int	num;

	num = x * y;
	if (num > INT_MAX)
		return (1);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*bytes;
	void			*ptr;
	size_t			len;
	size_t			i;

	if (is_overflow(nmemb, size) == 1)
		return (NULL);
	len = nmemb * size;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	bytes = (unsigned char *)ptr;
	i = 0;
	while (i < len)
	{
		bytes[i] = 0;
		i++;
	}
	return (ptr);
}
