/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inser_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:21:18 by smokhtar          #+#    #+#             */
/*   Updated: 2018/09/12 16:21:19 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		get_list_size(t_dirp *file)
{
	int		size;

	size = 0;
	while (file)
	{
		file = file->next;
		size++;
	}
	return (size);
}

static void		file_time_sort(t_dirp *file)
{
	while (file->next)
	{
		if (file->info.st_mtime - file->next->info.st_mtime < 0)
		{
			swap_next(file, file->next);
			file = get_lst_end(file, 0);
		}
		else
			file = file->next;
	}
}

void			inser_sort(t_dirp **file)
{
	t_dirp	*tmp;
	t_dirp	*tmp_side;
	int		i;

	if (g_option & T)
		file_time_sort(*file);
	else
	{
		i = get_list_size(*file) - 1;
		tmp = (*file);
		while ((tmp_side = sort_ascii(tmp, i)))
		{
			if (tmp_side->next)
			{
				if (tmp_side->next == get_file_at(tmp, i))
					swap_next(tmp_side, get_file_at(tmp, i));
				else
					swap_far(tmp_side, get_file_at(tmp, i));
				tmp = (*file);
			}
			i--;
		}
	}
}
