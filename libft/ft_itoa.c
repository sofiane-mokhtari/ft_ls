/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:15:39 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/20 14:09:52 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long int	div;
	long int	nb;
	char		*dst;
	int			i;

	div = 1;
	i = 0;
	nb = (n < 0) ? -n : n;
	if (n == -2147483648)
	{
		dst = ft_strdup("-2147483648");
		return (dst);
	}
	while (div <= nb)
		div *= 10;
	if (!(dst = (char*)malloc(((div % 10 + ((n < 0) ? 2 : 1)) * sizeof(char)))))
		return (NULL);
	dst[(div % 10) + 1 + ((n < 0) ? 1 : 0)] = '\0';
	if (n < 0)
		dst[i++] = '-';
	if (n == 0)
		dst[i] = '0';
	while ((div = div / 10) != 0)
		dst[i++] = (((nb / div) % 10) + 48);
	return (dst);
}
