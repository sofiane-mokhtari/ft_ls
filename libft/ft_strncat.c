/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:46:04 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/15 16:51:41 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int len;
	int idx;

	len = ft_strlen(s1);
	idx = 0;
	while (s2[idx] && idx < (int)n)
	{
		s1[len + idx] = s2[idx];
		idx++;
	}
	s1[idx + len] = '\0';
	return (s1);
}
