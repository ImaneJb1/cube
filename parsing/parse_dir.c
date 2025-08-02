/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:22:42 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/02 11:02:38 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parse_dir(char *line, dir *dir)
{
	static config arr[6] = {{"NO ", 0, dir->no}, {"SO ", 0, NULL}, {"WE ", 0, NULL}, {"EA ", 0, NULL}};
	
	if(ft_strncmp(line, "NO ", 3))
	{
		if(dir->no == 1)
		{
			printf("invalid map\n");
			return;
		}
		dir->no = 1;
		
	}
}