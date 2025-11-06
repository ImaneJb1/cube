/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:50:41 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/06 15:32:29 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	rgb_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	is_numb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	get_hex_color(char *rgb)
{
	char	*r;
	char	*g;
	char	*b;
	int		hex_color;

	r = (ft_split(rgb, ','))[0];
	g = (ft_split(rgb, ','))[1];
	b = (ft_split(rgb, ','))[2];
	if (!is_numb(r) || !is_numb(g) || !is_numb(b))
	{
		printf("Invalid RGB color\n");
		free_and_exit(1);
	}
	hex_color = rgb_to_hex(ft_atoi(r), ft_atoi(g), ft_atoi(b));
	return (hex_color);
}
