/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:49:46 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/15 16:51:54 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	len;
	size_t	idx;
	size_t	lon;

	lon = ft_strlen(s2);
	if (size == 0)
		return (lon);
	len = ft_strlen(s1);
	if (size < len)
		return (size + lon);
	lon += len;
	idx = 0;
	while (s2[idx] && len + idx < size - 1)
	{
		s1[len + idx] = s2[idx];
		idx++;
	}
	s1[idx + len] = '\0';
	return (lon);
}
