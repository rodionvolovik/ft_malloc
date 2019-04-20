/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:22:09 by rvolovik          #+#    #+#             */
/*   Updated: 2016/11/30 16:31:44 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*res;

	if (!s)
		return (0);
	if ((new = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	res = new;
	while (*s)
	{
		*new = (*f)(*s);
		new++;
		s++;
	}
	return (res);
}
