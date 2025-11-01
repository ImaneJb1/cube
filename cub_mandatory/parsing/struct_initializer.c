/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_initializer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:08:40 by ijoubair          #+#    #+#             */
/*   Updated: 2025/10/31 21:50:09 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

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
