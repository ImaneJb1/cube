/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:16:39 by ijoubair          #+#    #+#             */
/*   Updated: 2025/10/31 21:41:02 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

textures	**text_func(void)
{
	static textures	*text;

	return (&text);
}

char	***the_map(void)
{
	static char	**map;

	return (&map);
}

t_data	*data_func(void)
{
	static t_data	data;

	return (&data);
}
