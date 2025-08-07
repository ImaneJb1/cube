/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:12:37 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/07 17:25:42 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char **argv)
{
	textures *txt;

	if(!check_argv(argc, argv))
		return 0;
	if(!check_textures(argv[1]))
		return 0;
	txt = (*text_func());
	if(txt == NULL)
	{
		printf("NULL\n");
		return 0;
	}
	printf("no = %s\n", txt->no);
	printf("so = %s\n", txt->so);
	printf("ea = %s\n", txt->ea);
	printf("we = %s\n", txt->we);
	printf("f = %s\n", txt->f);
	printf("c = %s\n", txt->c);
	return 0;
}
