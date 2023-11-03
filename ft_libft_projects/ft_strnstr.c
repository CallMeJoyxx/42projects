/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:01:01 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/17 19:20:15 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, unsigned long len)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	len_needle;

	i = 0;
	len_needle = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && len-- >= len_needle)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *) haystack + i);
		i++;
	}
	return ((void *) 0);
}
