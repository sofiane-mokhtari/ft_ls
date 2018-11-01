/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:35:24 by smokhtar          #+#    #+#             */
/*   Updated: 2018/08/15 17:35:25 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		do_it(char *name, DIR *dirp, int i)
{
	t_dirp		*lst;

	lst = read_dir(dirp, name);
	closedir(dirp);
	start_print(lst, name, i);
	check_file(lst);
}

static void		foreach_arg(t_arg **arg)
{
	int			i;
	t_dirp		*lst;
	int			len;

	i = -1;
	while (arg[++i])
		if (!(arg[i]->dirp = test_open(arg[i]->name, 0)) && errno != 2)
		{
			g_option |= N;
			lst = my_lstnew(arg[i]->name);
			read_file(lst, arg[i]->name);
			start_print(lst, arg[i]->name, -2);
			free_lst(lst);
		}
	if (g_option & N)
		ft_putchar('\n');
	len = i;
	i = (g_option & R) ? i - 1 : 0;
	while ((i >= 0 && arg[i] && !(g_option & R)) || (i >= 0 && g_option & R))
	{
		if (arg[i]->dirp)
			do_it(arg[i]->name, arg[i]->dirp, (len == 1) ? -2 : i);
		free(arg[i]->name);
		i = (g_option & R) ? i - 1 : i + 1;
	}
}

static void		no_arg(void)
{
	DIR		*dirp;

	dirp = test_open(".", 0);
	do_it(".", dirp, -2);
}

DIR				*test_open(char *filename, int i)
{
	DIR		*dirp;
	char	**tab;

	if ((dirp = opendir(filename)) == NULL)
	{
		if (errno == 20)
			return (NULL);
		if (!(tab = ft_strsplit(filename, '/')))
			ft_error("malloc error\n");
		if (i)
		{
			ft_putchar('\n');
			ft_putstr(filename);
			ft_putstr(":\n");
		}
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(tab[ft_tablen(tab) - 1], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar('\n');
		ft_tabdel(tab);
	}
	return (dirp);
}

int				main(int ac, char **av)
{
	t_arg	**arg;
	int		len;

	av++;
	len = ac - parser(av) - 1;
	if (len <= 0)
		arg = NULL;
	else
		arg = (ac > 1) ? argument(av, len, 0, 0) : NULL;
	if (arg)
		foreach_arg(arg);
	else
		no_arg();
	return (0);
}
