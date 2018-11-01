/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:28:43 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/15 16:51:31 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int len;
	int idx;

	len = ft_strlen(s1);
	idx = 0;
	while (s2[idx])
	{
		s1[len + idx] = s2[idx];
		idx++;
	}
	s1[idx + len] = '\0';
	return (s1);
}
