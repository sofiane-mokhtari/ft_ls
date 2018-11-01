/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 02:01:19 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/20 17:33:19 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putfile(char *file)
{
	char	buf[128];
	int		fd;
	int		size;

	fd = open(file, O_RDONLY);
	while ((size = read(fd, buf, 128)))
		write(1, buf, size);
	close(fd);
}
