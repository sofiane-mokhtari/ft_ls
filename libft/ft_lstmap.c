/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:54:16 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/20 17:01:41 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*dst;

	new = ft_lstnew(0, 0);
	dst = new;
	while (lst)
	{
		tmp = f(lst);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		if (new->next == 0)
			return (0);
		if (dst == 0)
			dst = new;
		lst = lst->next;
		new = new->next;
	}
	new = dst->next;
	ft_memdel((void**)&dst);
	return (new);
}
