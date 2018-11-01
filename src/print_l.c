/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:37:51 by smokhtar          #+#    #+#             */
/*   Updated: 2018/09/06 13:37:52 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		set_tab(t_lprint *tab)
{
	tab->link = 0;
	tab->poid = 0;
	tab->uid = 0;
	tab->gid = 0;
}

void		print_perm(mode_t perm)
{
	ft_putchar((perm & S_IRUSR) ? 'r' : '-');
	ft_putchar((perm & S_IWUSR) ? 'w' : '-');
	ft_putchar((perm & S_IXUSR) ? 'x' : '-');
	ft_putchar((perm & S_IRGRP) ? 'r' : '-');
	ft_putchar((perm & S_IWGRP) ? 'w' : '-');
	ft_putchar((perm & S_IXGRP) ? 'x' : '-');
	ft_putchar((perm & S_IROTH) ? 'r' : '-');
	ft_putchar((perm & S_IWOTH) ? 'w' : '-');
	ft_putchar((perm & S_IXOTH) ? 'x' : '-');
}

void		prin_s(char *str, int space, int more)
{
	int		len;

	len = ft_strlen(str);
	len = (space + more) - len;
	while (len--)
		ft_putchar(' ');
	ft_putstr(str);
	ft_putchar(' ');
}

void		prin_n(int str, int space, int more)
{
	int		len;

	len = ft_nbrlen(str);
	len = (space + more) - len;
	while (len--)
		ft_putchar(' ');
	ft_putnbr(str);
	ft_putchar(' ');
}

void		print_id(t_dirp *lst, t_lprint *tab)
{
	struct passwd	*p;
	struct group	*g;

	p = getpwuid(lst->info.st_uid);
	g = getgrgid(lst->info.st_gid);
	if (!(p) || !(p->pw_name))
		prin_n(lst->info.st_gid, tab->uid, 0);
	else
		prin_s(p->pw_name, tab->uid, 0);
	if (!(g) || !(g->gr_name))
		prin_n(lst->info.st_gid, tab->gid, 1);
	else
		prin_s(g->gr_name, tab->gid, 1);
}
