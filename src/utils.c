/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:05:05 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/16 11:29:57 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_split_len(char **strs)
{
	int	i;

	if (!strs)
		return (-1);
	i = 0;
	while (strs[i])
		i++;
	return (i);
}

char	*ft_strs_cat(char **strs, int len)
{
	char	*str;
	int		strs_len;
	int		i;

	i = 0;
	strs_len = 0;
	while (i < len)
		strs_len += ft_strlen(strs[i++]);
	str = (char *)malloc(sizeof(char) * (strs_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	str[0] = 0;
	while (i < len)
		ft_strlcat(str, strs[i++], strs_len + 1);
	str[strs_len] = 0;
	return (str);
}
