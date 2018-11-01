/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:28:51 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/20 17:24:41 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	int		len;
	int		len1;
	int		i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len = len1 + ft_strlen(s2);
	if (!(str = ft_strnew(len)))
		return (NULL);
	i = 0;
	str = ft_strcpy(str, s1);
	while (s2[i])
	{
		str[len1 + i] = s2[i];
		i++;
	}
	free((void*)s1);
	free((void*)s2);
	s1 = NULL;
	s2 = NULL;
	return (str);
}
