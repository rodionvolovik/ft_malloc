/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:49:59 by rvolovik          #+#    #+#             */
/*   Updated: 2016/11/30 17:37:11 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	n;
	char	*s_last;

	s_last = NULL;
	n = (char)c;
	while (*s)
	{
		if (*s == n)
			s_last = (char *)s;
		s++;
	}
	if (*s == n)
		return (s_last = (char *)s);
	return (s_last);
}
