/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:23:58 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/11 14:07:14 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (((ft_strlen(haystack) == 0 && ft_strlen(needle) == 0))
		|| ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		k = 0;
		while (needle[k] && haystack[i + k] == needle[k] && k + i < len)
			k++;
		if (needle[k] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
