/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:01:05 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/02 16:29:31 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	**mem_arr(void)
{
	static void *mem_arr[1024];
	return(mem_arr);
}

void	*gc_malloc(size_t size)
{
	static void 	*pointer;
	void		*tmp;
	static int i;
	void	*mem;
	
	mem = malloc(size);
	if(!mem)
	{
		ft_putstr_fd("allocation faillure\n", 2);
		return (NULL);
	}
	tmp = pointer;
	i = i + size;
	tmp + i = mem;
}
