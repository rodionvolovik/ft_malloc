/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:53:27 by rvolovik          #+#    #+#             */
/*   Updated: 2016/11/26 17:30:49 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t c)
{
	void	*allmem;

	if ((allmem = malloc(c)) != NULL)
	{
		ft_bzero(allmem, c);
		return (allmem);
	}
	else
		return (NULL);
}
