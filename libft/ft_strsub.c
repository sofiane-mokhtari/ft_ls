/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:18:13 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/13 16:10:21 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	int				i;
	unsigned int	end;

	end = start + len;
	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(dst = ft_strnew(len)))
		return (NULL);
	while (start < end)
		dst[i++] = s[start++];
	return (dst);
}
