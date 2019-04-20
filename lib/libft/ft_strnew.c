/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:38:59 by rvolovik          #+#    #+#             */
/*   Updated: 2016/11/26 17:29:04 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	void	*str;

	if ((str = malloc(size + 1)) != NULL)
	{
		ft_bzero(str, size + 1);
		return (str);
	}
	else
		return (NULL);
}
