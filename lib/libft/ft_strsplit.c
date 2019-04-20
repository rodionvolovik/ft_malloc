/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:26:59 by rvolovik          #+#    #+#             */
/*   Updated: 2016/11/30 17:41:20 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_words(char const *str, char c)
{
	int		words;

	words = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
			words++;
		while (*str && *str != c)
			str++;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	x;

	x = 0;
	if (!s || !(tab = (char**)malloc(sizeof(char*) * ((ft_words(s, c) + 1)))))
		return (NULL);
	tab[ft_words(s, c)] = NULL;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (i)
		{
			tab[x] = ft_strnew(i);
			if (tab[x] == NULL)
				return (NULL);
			ft_strncpy(tab[x++], s, i);
			s = s + i;
		}
	}
	return (tab);
}
