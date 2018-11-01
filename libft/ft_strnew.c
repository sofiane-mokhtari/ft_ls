/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:26:10 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/10 11:06:28 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	int		i;
	char	*new;

	i = 0;
	if (!(new = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (i <= ((int)size))
		new[i++] = '\0';
	return (new);
}
