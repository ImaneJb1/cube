/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:01:05 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/10 15:33:18 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	***mem_arr(void)
{
	static void *mem_arr[1024];
	return(&mem_arr);
}

int	*mem_count(void)
{
	static int count;
	return(&count);
}

void	*gc_malloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if(!mem)
	{
		printf("allocation faillure\n");
		return (NULL);
	}
	(*mem_arr()[(*mem_count())++]) = mem;
}

void free_all(void)
{
	int i;

	i = 0;
	while(i < *mem_count())
	{
		free(*mem_arr()[i]);
		i++;
	}
	*mem_count() = 0;
}
