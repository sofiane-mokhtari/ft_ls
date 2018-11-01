/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:04:03 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/15 10:55:19 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*as;

	as = (char*)s;
	i = ft_strlen(s);
	as = as + i;
	while (i >= 0 && *as-- != c)
		i--;
	if (i == -1)
		return (NULL);
	return (++as);
}
