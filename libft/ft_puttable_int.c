/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:04:23 by smokhtar          #+#    #+#             */
/*   Updated: 2018/01/31 14:54:12 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttable_int(int **tab, int x, int y)
{
	int		i;
	int		e;

	i = 0;
	e = 0;
	while (i < x)
	{
		while (e < y)
		{
			ft_putnbr(tab[i][e]);
			ft_putchar('	');
			e++;
		}
		e = 0;
		i++;
		ft_putchar('\n');
	}
}
