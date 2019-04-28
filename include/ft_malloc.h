/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <rvolovik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 07:36:28 by rvolovik          #+#    #+#             */
/*   Updated: 2019/04/28 15:27:32 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_FT_MALLOC_H_
# define FT_MALLOC_FT_MALLOC_H_

# include <stdlib.h>
# include <pthread.h>

/**
 * Allowed functions
 *
 * mmap(2) - claim and return the memory pages to the system
 * munmap(2) - claim and return the memory pages to the system
 * getpagesize(3)
 * getrlimit(2)
 * lpthread
 */

# define N_BLOCKS 		100
# define TINY			(size_t)getpagesize()
# define SMALL			(size_t)getpagesize() * 16
# define BLOCK_SIZE(x)	((size_t)x + sizeof(t_block))
# define G_SIZE			3
# define I_TINY			0
# define I_SMALL		1
# define I_LARGE		2

typedef struct 			s_block
{
	struct s_block		*next;
	size_t				size;
	int					free;
	void				*memory;
}						t_block;

t_block					*g_memory[G_SIZE];
extern pthread_mutex_t	g_mutex;

int		find_allocated_block(t_block *block, int index, int make_free);

void    free(void *ptr);
/**
 * -) tries to change the size of the allocation pointed to by “ptr” to “size”, and returns “ptr”.
 * -) If there is not enough room to enlarge the memory allocation pointed to by ptr, realloc() creates a new allocation,
 * 		copies as much of the old data pointed to by “ptr” as will fit to the new allocation, frees the old allocation,
 * 		and returns a pointer to the allocated memory
 * -) If there is an error, the malloc() et realloc() functions return a NULL pointer.
 */
// void    *realloc(void *ptr, size_t size);
void    *malloc(size_t size);
/**
 * allows visual on the state of the allocated memory pages.
 *
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
void	ft_putaddr(unsigned long long ptr);
void	show_alloc_mem();

/**
 * displays more details, for example, a history of allocations, or an hexa dump of the allocated pages.
 */
// void	show_alloc_mem_ex();

/**
 * BONUS:
 *
 * -) Manage the malloc debug environment variables. You can imitate those from malloc system or invent your own.
 * -) Create a show_alloc_mem_ex() function that displays more details, for example, a history of allocations, or an hexa dump of the allocated pages.
 * -) “Defragment” the freed memory.
 * -) Manage the use of your malloc in a multi-threaded program (so to be “thread safe” using the pthread lib).
 */

#endif  // FT_MALLOC_FT_MALLOC_H_


// gcc -o mytest mytest.c ../src/malloc.c -I../include/ -I../lib/libft/includes -L../lib/libft/ -lft && /usr/bin/time -l ./mytest