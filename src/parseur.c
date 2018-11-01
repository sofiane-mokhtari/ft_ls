/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 18:29:51 by smokhtar          #+#    #+#             */
/*   Updated: 2018/08/15 18:29:52 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		test_option(char *str)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'a' && str[i] != 'l' && str[i] != 'r' && str[i] != 'R'
			&& str[i] != 't')
		{
			ft_putstr_fd("ft_ls: illegal option -- ", 2);
			ft_putstr_fd("\nusage: ft_ls [-alrtR] [file ...]\n", 2);
			exit(0);
		}
		i++;
	}
	return (1);
}

static int		parser_option(char *str)
{
	test_option(str);
	if (ft_strchr(str, 'a'))
		g_option |= A;
	if (ft_strchr(str, 'l'))
		g_option |= L;
	if (ft_strchr(str, 'r'))
		g_option |= R;
	if (ft_strchr(str, 'R'))
		g_option |= RR;
	if (ft_strchr(str, 't'))
		g_option |= T;
	return (1);
}

int				parser(char **av)
{
	int		i;

	i = 0;
	g_option = 0;
	while (av[i] && !(g_option & TIRER))
	{
		if (av[i][0] == '-')
		{
			if (av[i][1] == '-')
			{
				if (av[i][2] && av[i][2] == '-')
					test_option(av[i]);
				g_option |= TIRER;
				i++;
			}
			else
				i += parser_option(av[i]);
		}
		else
			return (i);
	}
	return (i);
}

t_arg			**argument(char **av, int len, int i, int e)
{
	t_arg	**tab;

	if (!(tab = (t_arg**)malloc(sizeof(t_arg*) * (len + 1))))
		return (NULL);
	tab[len] = NULL;
	while (av[i] && av[i][0] == '-')
	{
		if (av[i][1] && av[i][1] == '-')
		{
			i++;
			break ;
		}
		i++;
	}
	if (e < len)
	{
		while (av[i])
		{
			if (!(tab[e] = (t_arg*)malloc(sizeof(t_arg))))
				return (NULL);
			tab[e++]->name = ft_strdup(av[i++]);
		}
	}
	return (tab);
}
