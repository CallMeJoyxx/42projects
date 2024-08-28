/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 06:36:19 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/22 07:11:00 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		lenght;
	char	*new_s;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strrchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) -1;
	while (end >= start && ft_strrchr(set, s1[end]))
		end--;
	lenght = end - start + 1;
	new_s = (char *)malloc(lenght + 1);
	if (new_s == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(new_s, (char *)s1 + start, lenght + 1);
	return (new_s);
}
