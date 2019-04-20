/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:08:47 by rvolovik          #+#    #+#             */
/*   Updated: 2016/11/24 15:21:40 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	const char	*s;
	char		*d;

	d = s1;
	s = s2;
	if (n != 0)
	{
		while (*d != 0)
			d++;
		while (n-- != 0)
		{
			if ((*d = *s++) == 0)
				break ;
			d++;
		}
		*d = '\0';
	}
	return (s1);
}
