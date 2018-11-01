/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:33:59 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/10 11:14:56 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (!(dst = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	dst[i + 1] = '\0';
	while (i >= 0)
	{
		dst[i] = src[i];
		i--;
	}
	return (dst);
}
