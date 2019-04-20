/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:38:26 by rvolovik          #+#    #+#             */
/*   Updated: 2016/11/26 18:39:50 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	char	*res;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if ((new = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	res = new;
	while (*s)
	{
		*new = (*f)(i, *s);
		new++;
		s++;
		i++;
	}
	return (res);
}
