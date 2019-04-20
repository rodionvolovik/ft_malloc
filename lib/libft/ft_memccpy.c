/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:59:45 by rvolovik          #+#    #+#             */
/*   Updated: 2016/11/30 17:57:38 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ud;
	const unsigned char	*us;
	unsigned char		uc;

	ud = (unsigned char *)dst;
	us = (unsigned char *)src;
	uc = (unsigned char)c;
	while (n--)
	{
		if ((*ud++ = *us++) == uc)
			return (ud);
	}
	return (0);
}
