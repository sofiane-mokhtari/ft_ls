/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 09:45:23 by smokhtar          #+#    #+#             */
/*   Updated: 2018/08/26 09:45:25 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		find_type(t_dirp *lst)
{
	char	t;

	t = (S_ISDIR(lst->info.st_mode)) ? 'd' : '-';
	t = (S_ISLNK(lst->info.st_mode)) ? 'l' : t;
	return (t);
}

static void		print_date(t_dirp *lst)
{
	char	*str;
	char	**tmp;
	int		date;

	str = ctime(&lst->info.st_mtime) + 4;
	if (!(tmp = ft_strsplit(str, ' ')))
		ft_error("malloc error\n");
	date = ft_atoi(tmp[3]);
	str[ft_strlen(str) - 14] = '\0';
	ft_putstr(str);
	if (date == 2018)
	{
		tmp[2][ft_strlen(tmp[2]) - 3] = '\0';
		prin_s(tmp[2], 5, 0);
	}
	else
		prin_n(ft_atoi(tmp[3]), 4, 1);
	ft_putchar(' ');
	ft_tabdel(tmp);
}

static t_lprint	*find_max(t_dirp *lst)
{
	struct passwd	*p;
	struct group	*g;
	int				m;
	t_lprint		*tab;

	if (!(tab = (t_lprint*)malloc(sizeof(t_lprint))))
		ft_error("malloc error\n");
	set_tab(tab);
	while (lst)
	{
		p = getpwuid(lst->info.st_uid);
		g = getgrgid(lst->info.st_gid);
		if (p && (m = ((p) ? ft_strlen(p->pw_name) :
			ft_nbrlen(lst->info.st_uid))) > tab->uid)
			tab->uid = m;
		if (g && (m = ((g) ? ft_strlen(g->gr_name) :
			ft_nbrlen(lst->info.st_gid))) > tab->gid)
			tab->gid = m;
		if ((m = ft_nbrlen(lst->info.st_size)) > tab->poid)
			tab->poid = m;
		if ((m = ft_nbrlen(lst->info.st_nlink)) > tab->link)
			tab->link = m;
		lst = (g_option & R) ? lst->prev : lst->next;
	}
	return (tab);
}

static void		print_l(t_dirp *lst)
{
	t_lprint	*tab;
	char		str[PATH_MAX];

	tab = find_max(lst);
	while (lst)
	{
		ft_putchar(find_type(lst));
		print_perm(lst->info.st_mode);
		ft_putchar((listxattr(lst->path, NULL, 0, XATT) > 0) ? '@' : ' ');
		prin_n(lst->info.st_nlink, tab->link, 1);
		print_id(lst, tab);
		prin_n(lst->info.st_size, tab->poid, 1);
		print_date(lst);
		ft_putstr(lst->name);
		if (S_ISLNK(lst->info.st_mode))
		{
			ft_memset(str, 0, PATH_MAX);
			readlink(lst->path, str, PATH_MAX);
			ft_putstr(" -> ");
			ft_putstr(str);
		}
		ft_putchar('\n');
		lst = (g_option & R) ? lst->prev : lst->next;
	}
	free(tab);
}

void			start_print(t_dirp *lst, char *filename, int i)
{
	if (g_option & R)
		lst = get_lst_end(lst, 1);
	if (i > 0)
		ft_putchar('\n');
	if (i >= 0)
	{
		ft_putstr(filename);
		ft_putstr(":\n");
	}
	if (g_option & L)
		print_l(lst);
	else
		while (lst)
		{
			ft_putstr_nl(lst->name);
			if (g_option & R)
				lst = lst->prev;
			else
				lst = lst->next;
		}
}
