/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:57:00 by smokhtar          #+#    #+#             */
/*   Updated: 2018/03/02 17:40:17 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_n_stock(int fd, char *stock)
{
	char	*buff;
	char	*tmp;
	int		ret;

	tmp = NULL;
	ret = 0;
	if (!(buff = malloc((sizeof(char) * BUFF_SIZE) + 1)))
		return (NULL);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		tmp = stock;
		stock = ft_strjoin(stock, buff);
		free(tmp);
		if (!stock)
			stock = ft_strsub(buff, 0, BUFF_SIZE);
		if (ft_strchr(buff, '\n') != 0)
			break ;
	}
	free(buff);
	return (stock);
}

int			get_next_line(const int fd, char **line)
{
	static char	*stock[OPEN_MAX];
	int			i;
	int			len;

	i = 0;
	if (fd < 0 || fd > OPEN_MAX || !line || read(fd, NULL, 0) < 0)
		return (-1);
	stock[fd] = ft_read_n_stock(fd, stock[fd]);
	if (stock[fd] == NULL)
		return (-1);
	if (stock[fd][0] == '\0')
		return (0);
	len = ft_strlen(stock[fd]);
	while (stock[fd][i] != '\n' && stock[fd][i] != '\0')
		i++;
	if (((*line) = ft_strsub(stock[fd], 0, i)) == NULL)
		return (-1);
	if (i == len)
		i--;
	stock[fd] = ft_strncpy(stock[fd], &stock[fd][i + 1], ft_strlen(stock[fd]));
	return (1);
}
