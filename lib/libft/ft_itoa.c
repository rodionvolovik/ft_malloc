/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:24:43 by rvolovik          #+#    #+#             */
/*   Updated: 2016/11/28 13:57:48 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_rank(int n)
{
	int rank;

	rank = 0;
	if (n <= 0)
		rank++;
	while (n)
	{
		rank++;
		n /= 10;
	}
	return (rank);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		len;

	len = ft_rank(n);
	if (!(s = ft_strnew(len)))
		return (NULL);
	if (n >= 0)
	{
		s[--len] = 48 + (n % 10);
		n /= 10;
		while (n > 0)
		{
			s[--len] = 48 + (n % 10);
			n /= 10;
		}
		return (s);
	}
	s[0] = '-';
	while (n)
	{
		s[--len] = 48 - (n % 10);
		n /= 10;
	}
	return (s);
}
