/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:36:00 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/22 07:40:15 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*new_s;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_s = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (new_s == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(new_s, (char *)s1, len1 + 1);
	ft_strlcpy(new_s + len1, (char *)s2, len2 + 1);
	return (new_s);
}
