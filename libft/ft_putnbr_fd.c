/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:17:58 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/13 14:33:20 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int div;
	long int nb;

	nb = n;
	div = 1;
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	while (div <= nb)
		div *= 10;
	div = div / 10;
	while (div != 0)
	{
		ft_putchar_fd(((nb / div) % 10) + 48, fd);
		div = div / 10;
	}
}
