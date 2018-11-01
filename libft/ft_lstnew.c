/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:25:18 by smokhtar          #+#    #+#             */
/*   Updated: 2017/12/09 18:25:32 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = ft_memalloc(sizeof(t_list))) == 0)
		return (0);
	content_size = (content == 0) ? 0 : content_size;
	if (content_size != 0 && (new->content = ft_memalloc(content_size)) != 0)
		ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	new->next = 0;
	return (new);
}
