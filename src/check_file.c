/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 16:42:56 by smokhtar          #+#    #+#             */
/*   Updated: 2018/08/26 16:42:58 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirp			*free_lst(t_dirp *lst)
{
	t_dirp *next;

	if (lst == NULL)
		return (NULL);
	if (g_option & R)
	{
		next = lst->prev;
		lst->next = NULL;
	}
	else
	{
		next = lst->next;
		lst->prev = NULL;
	}
	free(lst->path);
	ft_strclr(lst->name);
	if (!lst)
		free(lst);
	lst = NULL;
	return (next);
}

void			check_file(t_dirp *lst)
{
	DIR			*dirp;
	t_dirp		*file;

	if (g_option & R)
		lst = get_lst_end(lst, 1);
	while (lst)
	{
		if (S_ISDIR(lst->info.st_mode) && ft_strcmp(lst->name, "..") != 0 &&
			ft_strcmp(lst->name, ".") != 0 && (g_option & RR))
		{
			dirp = test_open(lst->path, 1);
			if (dirp)
			{
				file = read_dir(dirp, lst->path);
				closedir(dirp);
				start_print(file, lst->path, 1);
				check_file(file);
			}
		}
		lst = free_lst(lst);
	}
}
