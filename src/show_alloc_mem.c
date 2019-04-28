/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <rvolovik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 08:58:43 by rvolovik          #+#    #+#             */
/*   Updated: 2019/04/28 15:30:43 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>
#include <libft.h>
#include <stdio.h>

void	ft_putaddr(unsigned long long ptr)
{
	const char	hex[16] = "0123456789abcdef";
	char		s[16];
	int			i;

	i = 0;
	if (ptr == 0)
		s[i++] = '0';
	while (ptr != 0)
	{
		s[i++] = hex[ptr % 16];
		ptr /= 16;
	}
	write(1, "0x", 2);
	while (i--)
		ft_putchar(s[i]);
}

size_t    print_memory(t_block *memory, char* name)
{
    t_block *p_block;
    size_t  size;

    size = 0;
    p_block = memory;
    if (p_block)
    {
        ft_putstr(name);
        ft_putstr(" : ");
        ft_putaddr((unsigned long long)((void*)p_block));
        ft_putstr("\n");
    }
    while (p_block)
    {
        if (!p_block->free)
        // if (1)
        {
            ft_putaddr((unsigned long long)((void*)p_block->memory));
            ft_putstr(" - ");
            ft_putaddr((unsigned long long)((void*)p_block->memory + p_block->size));
            ft_putstr(": ");
            ft_putstr(" (free=");
            ft_putnbr(p_block->free);
            ft_putstr(") ");
            ft_putnbr(p_block->size);
            ft_putstr(" bytes\n");
            size += p_block->size;
        }
        p_block = p_block->next;
    }
    return size;
}

void    show_alloc_mem()
{
    size_t  size;

    size = 0;
    size += print_memory(g_memory[I_TINY], "TINY");
    size += print_memory(g_memory[I_SMALL], "SMALL");
    size += print_memory(g_memory[I_LARGE], "LARGE");
    ft_putstr("Total: ");
    ft_putnbr(size);
    ft_putstr(" bytes\n");
}

/*
 * Example:
 * TINY : 0xA0000
 * 0xA0020 - 0xA004A : 42 bytes
 * 0xA006A - 0xA00BE : 84 bytes
 * SMALL : 0xAD000
 * 0xAD020 - 0xADEAD : 3725 bytes
 * LARGE : 0xB0000
 * 0xB0020 - 0xBBEEF : 48847 bytes
 * Total : 52698 bytes
 */