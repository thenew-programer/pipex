/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:49:26 by ybouryal          #+#    #+#             */
/*   Updated: 2024/10/25 18:18:39 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*_itoa(int n, char *buffer, size_t len)
{
	size_t	is_neg;
	size_t	buf_idx;

	is_neg = 0;
	buf_idx = len - 1;
	if (n < 0)
	{
		is_neg = 1;
		n *= -1;
	}
	while (n)
	{
		buffer[buf_idx--] = (n % 10) + '0';
		n /= 10;
	}
	if (is_neg)
		buffer[0] = '-';
	return (buffer);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		len;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = numlen(n);
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (!number)
		return (NULL);
	number[len] = 0;
	if (n == 0)
	{
		number[0] = '0';
		return (number);
	}
	_itoa(n, number, len);
	return (number);
}
