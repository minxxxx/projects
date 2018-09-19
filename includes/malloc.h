/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 07:39:42 by khansman          #+#    #+#             */
/*   Updated: 2017/06/08 07:39:44 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

/*
** ----------\
** Includes   |
** ----------/
*/

/*
** # ifdef __APPLE__
** #  include <strings.h>
** # else
** #  include <string.h>
** # endif
*/

# include <sys/mman.h>
# include <sys/types.h>
# include <sys/resource.h>
# include <unistd.h>
# include <pthread.h>

/*
** Bonus
*/
# include <stdlib.h>

/*
** ----------\
** Defines    |
** ----------/
*/

/*
** Limits
** Tiny is 128 but -8 for safety code
** Small is 32768 but -8 for safety code
*/
# define TINY_MAX 120
# define SMALL_MAX 32760

# define MAX_INT 2147483647
# define MIN_INT -2147483648

/*
** Return Values
*/
# define FATAL_ERROR_RETURN(x) if(x)return(-1)
# define ERROR_RETURN(x) if(x)return(0)
# define SUCCESS_RETURN(x) if(x)return(1)

/*
** Flags
*/
# define MMAP_PROT PROT_READ|PROT_WRITE
# define MMAP_FLAGS MAP_ANON|MAP_PRIVATE
# define MMAP_FFLAGS MAP_ANON|MAP_PRIVATE|MAP_FIXED

/*
** Tolerance
*/
# define TINY_TOLERANCE    8
# define SMALL_TOLERANCE  16
# define LARGE_TOLERANCE  32

/*
** Types
*/
# define NO_BLOCK        0
# define TINY_BLOCK      1
# define SMALL_BLOCK     2
# define LARGE_BLOCK     3

/*
** Shorten
*/
# define BLOCK_END block->ps.size + block
# define ADD_BLOCK_MEMBER ++block->active_members

/*
** ----------\
** Structures |
** ----------/
*/

/*
** Sizes
*/
typedef struct			s_page_size
{
	int					pages;
	int					size;
}						t_page_size;

/*
** Linked Lists
*/
typedef struct			s_tiny_list
{
	unsigned char		used : 1;
	unsigned char		next : 7;
}						t_tiny_list;

typedef struct			s_small_list
{
	unsigned short		used : 1;
	unsigned short		next : 15;
}						t_small_list;

typedef struct			s_block_zone
{
	struct s_block_zone	*next;
	t_page_size			ps;
	size_t				active_members;
}						t_block_zone;

/*
** Tracking
*/
typedef struct			s_malloc_zones
{
	t_block_zone		*tiny_block;
	t_block_zone		*small_block;
	t_block_zone		*large_block;
}						t_malloc_zones;

typedef struct			s_block_data
{
	char				block_type;
	t_block_zone		*block;
}						t_block_data;

/*
** ----------\
** Globals    |
** ----------/
*/

# ifdef MAIN_FILE

t_malloc_zones			g_zones;
int						g_page_size;
unsigned int			g_total_mem;
pthread_mutex_t			g_tiny_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t			g_small_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t			g_large_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t			g_lock_all = PTHREAD_MUTEX_INITIALIZER;

# else

extern t_malloc_zones	g_zones;
extern int				g_page_size;
extern unsigned int		g_total_mem;
extern pthread_mutex_t	g_tiny_lock;
extern pthread_mutex_t	g_small_lock;
extern pthread_mutex_t	g_large_lock;
extern pthread_mutex_t	g_lock_all;

# endif

/*
** ----------\
** Libft      |
** ----------/
*/
void					ft_bzero(void *s, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					ft_print_hex_l(unsigned long num);
void					ft_putchar(char c);
void					ft_putendl(char const *s);
void					ft_putnbr(unsigned long num);
void					ft_putstr(char const *s);

/*
** ----------\
** Prototypes |
** ----------/
*/

/*
** calloc.c
*/
void					*calloc(size_t count, size_t size);

/*
** erorr_quit.c
*/
void					malloc_error_quit(char *error_message);

/*
** find_block.c
*/
char					is_in_block(t_block_zone *block, void *ptr);
t_block_data			find_in_tiny_block(void *ptr);
t_block_data			find_in_small_block(void *ptr);
t_block_data			find_in_large_block(void *ptr);
t_block_data			find_block(void *ptr);

/*
** free.c
*/
void					free_tiny_block(t_block_zone *block, void *ptr);
void					free_small_block(t_block_zone *block, void *ptr);
void					free_large_block(t_block_zone *block);
void					free_all_blocks(void);
void					free(void *ptr);

/*
** init.c
*/
void					init_memory(void);

/*
** malloc.c
*/
void					*malloc_tiny_block(size_t size);
void					*malloc_small_block(size_t size);
void					*malloc_large_block(size_t size);
void					*malloc(size_t size);

/*
** pages.c
*/
t_page_size				round_to_pagesize(int size);
void					*allocate_page(void	*start_point, size_t size);

/*
** print.c
*/
void					print_total_usage(void);

/*
** realloc_large_block.c
*/
char					resize_large_block(t_block_zone *block, t_page_size ps,
						size_t size);
void					*realloc_large_block(t_block_zone *block, size_t size);

/*
** realloc_small_block.c
*/
char					divide_small_block(t_small_list *small, size_t size);
char					merge_small_block(t_small_list *small);
char					realloc_small_block(void *ptr, size_t size);

/*
** realloc_tiny_block.c
*/
char					divide_tiny_block(t_tiny_list *tiny, size_t size);
char					merge_tiny_block(t_tiny_list *tiny);
char					realloc_tiny_block(void *ptr, size_t size);

/*
** scan_small_block.c
*/
char					compatable_small_block(t_small_list *small,
						size_t size);
void					*scan_small_block(t_block_zone *block, size_t size);

/*
** scan_tiny_block.c
*/
char					compatable_tiny_block(t_tiny_list *tiny, size_t size);
void					*scan_tiny_block(t_block_zone *block, size_t size);

/*
** show_alloc_mem.c
*/
void					show_tiny_list(t_block_zone *block);
void					show_small_list(t_block_zone *block);
void					show_large_block(t_block_zone *block);
void					show_alloc_block(t_block_zone *block, char type);
void					show_alloc_mem(void);

/*
** zones.c
*/
char					extend_zone(t_block_zone *block, t_page_size page_size);
char					malloc_zone(size_t size, t_block_zone **start_block);

/*
** Bonus Summary:
** -> free_all_blocks
** -> double free error handling
** -> thread safe
** -> defragor needs to be added
** -> calloc: just bzero everything in memory
** -> valloc: The allocated memory is aligned on a page boundary
** -> reallocf: identical to the realloc() function, except
**    that it will free the passed pointer when the requested memory
**    cannot be allocated.
*/

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif
