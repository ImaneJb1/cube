/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:16:39 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/09 15:50:43 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

textures **text_func(void)
{
	static textures *text;
	return(&text);
}

char ***the_map(void)
{
	char *map;
	return(&map);
}