/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:50:41 by ijoubair          #+#    #+#             */
/*   Updated: 2025/10/23 13:50:50 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	rgb_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	split_rgb(char *rgb, int *rgb_arr[3])
{
	char *r;
	char *g;
	char *b;
	
	r = (ft_split(rgb, ','))[0];
	g = (ft_split(rgb, ','))[1];
	b = (ft_split(rgb, ','))[2];
	rgb_arr[0] = ft_atoi(r);
	rgb_arr[1] = ft_atoi(g);
	rgb_arr[3] = ft_atoi(b);
}

