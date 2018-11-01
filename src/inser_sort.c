/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inser_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 17:36:13 by smokhtar          #+#    #+#             */
/*   Updated: 2018/08/26 17:36:14 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirp		*get_file_at(t_dirp *file, int index)
{
	int		i;

	i = 0;
	while (file)
	{
		if (i++ == index)
			return (file);
		file = file->next;
	}
	return (NULL);
}

t_dirp		*sort_ascii(t_dirp *file, int size)
{
	int		i;
	t_dirp	*tmp_side;

	i = 0;
	tmp_side = file;
	while (file && i <= size)
	{
		if (ft_strcmp(tmp_side->name, file->name) < 0)
			tmp_side = file;
		file = file->next;
		i++;
	}
	if (i == 0)
		return (NULL);
	return (tmp_side);
}

void		swap_far(t_dirp *a, t_dirp *b)
{
	t_dirp *p;
	t_dirp *n;

	n = b->next;
	p = b->prev;
	b->prev = a->prev;
	b->next = a->next;
	a->prev = p;
	a->next = n;
	if (b->next)
		b->next->prev = b;
	if (b->prev)
		b->prev->next = b;
	if (a->next)
		a->next->prev = a;
	if (a->prev)
		a->prev->next = a;
}

void		swap_next(t_dirp *a, t_dirp *b)
{
	a->next = b->next;
	b->prev = a->prev;
	if (a->next)
		a->next->prev = a;
	if (b->prev)
		b->prev->next = b;
	b->next = a;
	a->prev = b;
}
