/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_initializer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imane <imane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:08:40 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/10 18:00:36 by imane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// dir_flags	*init_flags(void)
// {
// 	dir_flags *flags;
	
// 	flags = malloc(sizeof(dir_flags));
// 	if(!flags)
// 	{
// 		perror("");
// 		return(NULL);
// 	}
// 	ft_bzero(flags, sizeof(flags));
// 	return(flags);
// }

textures *init_textures(void)
{
	textures *text;

	text = gc_calloc(1, sizeof(textures));
	if(!text)
	{
		perror("");
		return(NULL);
	}
	return(text);
}
