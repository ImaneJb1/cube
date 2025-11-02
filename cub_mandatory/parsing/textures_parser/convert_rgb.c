/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:50:41 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/01 19:11:24 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	rgb_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_hex_color(char *rgb)
{
	char *r;
	char *g;
	char *b;
	int hex_color;
	
	r = (ft_split(rgb, ','))[0];
	g = (ft_split(rgb, ','))[1];
	b = (ft_split(rgb, ','))[2];
	hex_color = rgb_to_hex(ft_atoi(r), ft_atoi(g), ft_atoi(b));
	return(hex_color);
}

