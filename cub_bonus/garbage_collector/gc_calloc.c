/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:01:05 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/04 16:15:14 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	**mem_arr(void)
{
	static void	*mem_arr[6000000];

	return (mem_arr);
}

int	*mem_count(void)
{
	static int	count;

	return (&count);
}

void	*gc_malloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
	{
		printf("allocation faillure\n");
		return (NULL);
	}
	(mem_arr()[(*mem_count())++]) = mem;
	return (mem);
}

void	*gc_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = calloc(count, size);
	if (!mem)
	{
		printf("allocation faillure\n");
		return (NULL);
	}
	(mem_arr()[(*mem_count())++]) = mem;
	return (mem);
}

void	free_all(void)
{
	int i;
	int count;
	i = 0;
	count = (*mem_count());
	while(i < count)
	{
		// printf("i = %d count = %d  %s\n",i, (*mem_count()), (char *)mem_arr()[i]);
		if(mem_arr() && mem_arr()[i])
		{
			free(mem_arr()[i]);
			mem_arr()[i] = NULL;
		}
		i++;
	}
	(*mem_count()) = 0;
	(*mem_arr()) = NULL;
	destroy_all();
}
