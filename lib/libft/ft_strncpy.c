/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:46:02 by rvolovik          #+#    #+#             */
/*   Updated: 2016/11/25 17:48:29 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*cd;
	const char	*cs;

	cd = dst;
	cs = src;
	if (len != 0)
	{
		while (len--)
		{
			if ((*cd++ = *cs++) == 0)
			{
				while (len--)
					*cd++ = 0;
				break ;
			}
		}
	}
	return (dst);
}
