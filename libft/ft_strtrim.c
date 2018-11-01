/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:36:51 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/20 14:49:00 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dst;
	int		stt;
	int		end;

	stt = 0;
	if (s == NULL)
		return (NULL);
	while (s[stt] && (s[stt] == '\n' || s[stt] == ' ' || s[stt] == '\t'))
		stt++;
	end = ft_strlen(s) - 1;
	while (s[end] == '\n' || s[end] == ' ' || s[end] == '\t')
		end--;
	if (end < stt)
		return (ft_strnew(1));
	if ((dst = ft_strsub(s, stt, end - stt + 1)) == NULL)
		return (NULL);
	return (dst);
}
