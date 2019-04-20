/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:42:41 by rvolovik          #+#    #+#             */
/*   Updated: 2016/11/27 20:47:13 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*copy;
	char	*cp_ret;

	size = ft_strlen(s1) + 1;
	if ((copy = (char *)malloc(size)) == NULL)
		return (NULL);
	cp_ret = copy;
	while (*s1)
		*copy++ = *s1++;
	*copy = '\0';
	return (cp_ret);
}
