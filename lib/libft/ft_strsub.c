/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:12:13 by rvolovik          #+#    #+#             */
/*   Updated: 2016/11/26 19:45:30 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	char	*res;

	if (!s)
		return (0);
	if ((new = ft_strnew(len)) == NULL)
		return (NULL);
	res = new;
	s += (start);
	while (len--)
		*new++ = *s++;
	return (res);
}
