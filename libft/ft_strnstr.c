/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:13:59 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/19 15:27:53 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	lon;
	char	*str;

	lon = 0;
	str = (char*)haystack;
	i = (size_t)ft_strlen(needle) - 1;
	if (ft_strlen(needle) == 0)
		return (str);
	while (*str && lon + i < len && lon < len)
	{
		if (*str == needle[0])
		{
			if (ft_strcmp(ft_strsub(str, 0, i + 1), needle) == 0)
				return (str);
		}
		str++;
		lon++;
	}
	return (NULL);
}
