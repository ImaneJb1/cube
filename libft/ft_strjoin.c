/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:06:29 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/06 17:52:54 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus/header_bonus.h"
#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s3;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = gc_calloc(len + 1, len * sizeof(char) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
	{
		s3[i++] = s1[j++];
	}
	j = 0;
	while (s2 && s2[j])
	{
		s3[i++] = s2[j++];
	}
	s3[i] = '\0';
	return (s3);
}
