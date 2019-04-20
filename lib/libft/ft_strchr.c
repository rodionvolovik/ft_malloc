/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:20:49 by rvolovik          #+#    #+#             */
/*   Updated: 2016/11/27 20:45:59 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cs;
	char	n;

	cs = NULL;
	n = (char)c;
	while (*s)
	{
		if (*s == n)
			return (cs = (char *)s);
		s++;
	}
	if (*s == n)
		return (cs = (char *)s);
	return (NULL);
}
