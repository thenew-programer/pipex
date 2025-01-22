/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:31:16 by ybouryal          #+#    #+#             */
/*   Updated: 2024/10/23 10:55:07 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trimstr_len(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end]) && s1[end])
		end--;
	return (end - start);
}

static char	*empty_str(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		buf_idx;
	int		len;
	char	*s1_trimed;

	len = trimstr_len(s1, set);
	if (len <= 0)
		return (empty_str());
	s1_trimed = (char *)malloc(sizeof(char) * (len + 1));
	if (!s1_trimed)
		return (NULL);
	i = 0;
	buf_idx = 0;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	j = i;
	while (s1[i] && i < len + j + 1)
	{
		s1_trimed[buf_idx++] = s1[i];
		i++;
	}
	s1_trimed[buf_idx] = 0;
	return (s1_trimed);
}
