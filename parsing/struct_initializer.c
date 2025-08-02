/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:08:40 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/02 10:20:54 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

dir_flags	*init_flags(void)
{
	dir_flags *flags;
	
	flags = malloc(sizeof(dir_flags));
	if(!flags)
	{
		perror("");
		return(NULL);
	}
	ft_bzero(flags, sizeof(flags));
	return(flags);
}
