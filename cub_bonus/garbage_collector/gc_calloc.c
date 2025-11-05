/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:01:05 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/05 16:24:10 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

typedef struct s_mem
{
	void			*ptr;
	struct s_mem	*next;
}	t_mem;

static t_mem	*g_mem_list = NULL;

/* Add new allocated pointer to the linked list */
static void	add_mem(void *ptr)
{
	t_mem	*new_node;

	new_node = malloc(sizeof(t_mem));
	if (!new_node)
	{
		printf("allocation failure (list node)\n");
		free(ptr);
		return;
	}
	new_node->ptr = ptr;
	new_node->next = g_mem_list;
	g_mem_list = new_node;
}

/* Replacement for malloc */
void	*gc_malloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
	{
		printf("allocation failure\n");
		return (NULL);
	}
	add_mem(mem);
	return (mem);
}

/* Replacement for calloc */
void	*gc_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = calloc(count, size);
	if (!mem)
	{
		printf("allocation failure\n");
		return (NULL);
	}
	add_mem(mem);
	return (mem);
}

/* Free all tracked allocations */
void	free_all(void)
{
	t_mem	*tmp;

	destroy_all();
	while (g_mem_list)
	{
		tmp = g_mem_list;
		g_mem_list = g_mem_list->next;
		if (tmp->ptr)
			free(tmp->ptr);
		free(tmp);
	}
}
