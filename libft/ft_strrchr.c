/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:25:46 by ybouryal          #+#    #+#             */
/*   Updated: 2024/10/22 16:17:39 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t		i;
	const char	*pos;

	pos = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			pos = str + i;
		i++;
	}
	if (str[i] == c)
		pos = str + i;
	return ((char *)pos);
}
