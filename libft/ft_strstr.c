/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:00:39 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/15 17:56:17 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*str;
	char	c;

	i = ft_strlen(needle) - 1;
	c = needle[0];
	str = (char*)haystack;
	if (ft_strcmp(needle, "") == 0)
		return (str);
	while (*str)
	{
		if (*str == c)
			if (ft_strcmp(ft_strsub(str, 0, i + 1), needle) == 0)
				return (str);
		str++;
	}
	return (NULL);
}
