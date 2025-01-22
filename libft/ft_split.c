/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:55:53 by ybouryal          #+#    #+#             */
/*   Updated: 2024/10/23 11:26:01 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			len++;
		while (s[i] != c && s[i])
			i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	buf_idx;
	char	**strs;

	len = word_count(s, c);
	strs = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	buf_idx = 0;
	while (s[i] && buf_idx != len)
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		strs[buf_idx] = (char *)malloc(sizeof(char) * (j + 1));
		j = 0;
		while (s[i] != c && s[i])
			strs[buf_idx][j++] = s[i++];
		strs[buf_idx++][j] = 0;
	}
	strs[buf_idx] = NULL;
	return (strs);
}
