/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:17:53 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/15 10:58:32 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*p_dst;
	const char	*p_src;

	p_dst = dst;
	p_src = src;
	i = len;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
		while (i--)
			p_dst[i] = p_src[i];
	return (dst);
}
