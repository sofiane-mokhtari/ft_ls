/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:50 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/13 14:33:39 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*as;
	int		i;

	i = 0;
	if (!(as = (char*)malloc((size * sizeof(char)))))
		return (NULL);
	while (i <= ((int)size))
		as[i++] = 0;
	return (as);
}
