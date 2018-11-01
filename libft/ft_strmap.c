/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:49:18 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/13 16:05:40 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dst;

	if (s == NULL || f == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (!(dst = ft_strnew(i)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = f(s[i]);
		i++;
	}
	return (dst);
}
