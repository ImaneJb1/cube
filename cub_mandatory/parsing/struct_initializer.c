/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_initializer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:08:40 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/05 23:15:34 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

textures **global_tex(void)
{
	static textures *text;
	return(&text);
}

textures *init_textures(void)
{
	textures **text;
	text = global_tex();
	*text = gc_calloc(1, sizeof(textures));
	if(!*global_tex())
	{
		perror("");
		return(NULL);
	}
	return(*text);
}
