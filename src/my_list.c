/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 14:59:21 by smokhtar          #+#    #+#             */
/*   Updated: 2018/08/26 14:59:23 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirp		*my_lstnew(char *path)
{
	t_dirp	*lst;

	if (!(lst = (t_dirp*)ft_memalloc(sizeof(t_dirp))))
		return (NULL);
	ft_strclr(lst->path);
	ft_strclr(lst->name);
	ft_strcpy(lst->path, path);
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}

void		my_lst_put_in(t_dirp *lst, t_dirp *put)
{
	put->next = lst;
	put->prev = lst->prev;
	lst->prev = put;
	if (put->prev)
		put->prev->next = put;
}

void		my_lst_add(t_dirp *lst, t_dirp *add)
{
	lst->next = add;
	add->prev = lst;
}

t_dirp		*get_lst_end(t_dirp *lst, int i)
{
	if (lst == NULL)
		return (NULL);
	if (i)
	{
		while (lst->next)
			lst = lst->next;
	}
	else
	{
		while (lst->prev)
			lst = lst->prev;
	}
	return (lst);
}

t_dirp		*my_lst_insr(t_dirp *lst, t_dirp *new)
{
	t_dirp	*start;

	start = lst;
	while (lst)
	{
		if (ft_strcmp(lst->name, new->name) > 0)
		{
			my_lst_put_in(lst, new);
			if (start == new)
				return (new);
			return (start);
		}
		lst = lst->next;
	}
	my_lst_add(get_lst_end(start, 1), new);
	return (start);
}
