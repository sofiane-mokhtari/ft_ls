/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:56:51 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/10 12:10:39 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int div;
	long int nb;

	nb = n;
	div = 1;
	if (n == 0)
		ft_putchar('0');
	if (n < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	while (div <= nb)
		div *= 10;
	div = div / 10;
	while (div != 0)
	{
		ft_putchar(((nb / div) % 10) + 48);
		div = div / 10;
	}
}
