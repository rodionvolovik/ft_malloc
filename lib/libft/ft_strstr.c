/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:25:48 by rvolovik          #+#    #+#             */
/*   Updated: 2016/11/26 21:06:25 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	ll;

	ll = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (*big)
	{
		if (*big == *little && ft_strncmp(big, little, ll) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
