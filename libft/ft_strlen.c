/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:08:11 by ijoubair          #+#    #+#             */
/*   Updated: 2025/01/30 20:25:37 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if(!str)
		return(0);
	while (str[len])
	{
		len++;
	}
	return (len);
}
// #include <stdio.h>
// int	main(void)
// {
// 		printf("%ld", strlen(NULL));
// 	return (0);
// }
