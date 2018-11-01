/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:18:04 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/16 15:34:36 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_splitted(const char *s, char c)
{
	int		count;
	size_t	idx;
	char	last_c;

	if (ft_strlen(s) == 0)
		return (0);
	count = 1;
	idx = 0;
	last_c = 0;
	while (s[idx] != 0)
	{
		if (s[idx] == c)
		{
			if (s[idx] != last_c && last_c != 0)
				count++;
		}
		last_c = s[idx];
		idx++;
	}
	if (last_c == c)
		count--;
	return (count);
}

static size_t	ft_strlen_split(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != 0 && s[len] != c)
		len++;
	return (len);
}

static char		*ft_extract_word(const char *s, size_t *sidx, char c)
{
	char	*res;
	size_t	idx;
	size_t	len;

	len = ft_strlen_split(s + *sidx, c);
	if ((res = ft_strnew(len)) == 0)
		return (0);
	idx = 0;
	while (idx < len)
		res[idx++] = s[(*sidx)++];
	return (res);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	size_t	idx;
	size_t	sidx;
	size_t	count;

	if (s == 0)
		return (0);
	count = ft_count_splitted(s, c);
	if ((tab = ft_memalloc(sizeof(char *) * (count + 1))) == 0)
		return (0);
	idx = 0;
	sidx = 0;
	while (idx < count)
	{
		while (s[sidx] == c)
			sidx++;
		tab[idx] = ft_extract_word(s, &sidx, c);
		idx++;
	}
	return (tab);
}
