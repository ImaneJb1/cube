/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_initializer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:08:40 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/06 23:08:16 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

t_textures	**global_tex(void)
{
	static t_textures	*text;

	return (&text);
}

t_textures	*init_textures(void)
{
	t_textures	**text;

	text = global_tex();
	*text = gc_calloc(1, sizeof(t_textures));
	if (!*global_tex())
	{
		perror("");
		return (NULL);
	}
	return (*text);
}
