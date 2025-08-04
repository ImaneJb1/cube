/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:01:05 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/03 11:51:55 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	**mem_arr(void)
{
	static void *mem_arr[1024];
	return(mem_arr);
}

int	*mem_count(void)
{
	static int count;
	return(&count);
}

void	*gc_malloc(size_t size)
{
	
	void	*mem;
	static void **arr;
	int *count;

	arr = mem_arr();
	mem = malloc(size);
	count = mem_count();
	if(!mem)
	{
		ft_putstr_fd("allocation faillure\n", 2);
		return (NULL);
	}
	(*mem_arr()[(*mem_count())]) = mem;
}
