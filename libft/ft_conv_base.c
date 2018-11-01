/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 13:55:10 by smokhtar          #+#    #+#             */
/*   Updated: 2018/01/17 12:26:13 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_p2(int nb, int to)
{
	int		r;
	size_t	i;
	int		n;
	char	*rr;

	n = nb;
	i = 1;
	r = 0;
	while ((nb = nb / to))
		i++;
	nb = (n < 0) ? 1 : 0;
	if (!(rr = ft_strnew(i + nb)))
		return (NULL);
	if (nb == 1)
		rr[i--] = '-';
	while (n)
	{
		i--;
		r = n % to;
		rr[i] = (r < 10) ? r + 48 : 65 + (r - 10);
		n = n / to;
	}
	return (rr);
}

static int	ft_p1(char *nb, int src)
{
	int r;
	int i;
	int c;

	i = 0;
	r = ((nb[i] >= 48 && nb[i] <= 57) ? nb[i] - 48 : nb[i] - 55);
	while (nb[++i])
	{
		c = ((nb[i] >= 48 && nb[i] <= 57) ? ft_atoi(&nb[i]) : nb[i] - 55);
		r = r * src + c;
	}
	return (r);
}

char		*ft_conv_base(char *nb, int src, int to)
{
	int r;

	if (src != 10)
		r = ft_p1(nb, src);
	else
		r = ft_atoi(nb);
	if (to != 10)
		return (ft_p2(r, to));
	return (ft_itoa(r));
}
