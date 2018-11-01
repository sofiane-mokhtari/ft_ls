/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 09:36:19 by smokhtar          #+#    #+#             */
/*   Updated: 2018/08/26 09:36:21 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		errno_stat(void)
{
	if (errno == ENOENT)
		return (1);
	if (errno == ELOOP)
	{
		ft_putstr(strerror(errno));
		return (1);
	}
	ft_putstr(strerror(errno));
	exit(0);
}

static char		*ft_path(char *s1, char *s2)
{
	if (ft_strlen(s1) == 0)
		return (ft_strcat(s1, s2));
	return (ft_strcat(ft_strcat(s1, "/"), s2));
}

void			read_file(t_dirp *lst, char *path)
{
	char	**tab;

	if (!(tab = ft_strsplit(path, '/')))
		ft_error("malloc error\n");
	ft_strcpy(lst->name, tab[ft_tablen(tab) - 1]);
	if (lstat(lst->path, &lst->info) == -1)
		errno_stat();
	ft_tabdel(tab);
}

t_dirp			*read_dir(DIR *dirp, char *filename)
{
	struct dirent	*dp;
	t_dirp			*stt;
	t_dirp			*new;

	stt = NULL;
	while ((dp = readdir(dirp)))
		if (dp->d_name[0] != '.' || ((g_option & A) && dp->d_name[0] == '.'))
		{
			if (!(new = my_lstnew(filename)))
				ft_error("malloc error\n");
			new->dir = dp;
			ft_strcpy(new->name, dp->d_name);
			ft_path(new->path, dp->d_name);
			if (lstat(new->path, &new->info) == -1)
				errno_stat();
			if (stt)
				my_lst_add(get_lst_end(stt, 1), new);
			else
				stt = new;
		}
	if (stt)
		inser_sort(&stt);
	stt = get_lst_end(stt, 0);
	return (stt);
}
