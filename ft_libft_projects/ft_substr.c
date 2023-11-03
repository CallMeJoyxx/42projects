/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:45:41 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/21 21:38:54 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, unsigned long len)
{
	unsigned long	s_len;
	unsigned long	i;
	char			*new_s;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
	{
		len = s_len - start;
	}
	new_s = (char *)malloc(len + 1);
	if (new_s == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_s[i] = s[start + i];
		i++;
	}
	new_s[len] = '\0';
	return (new_s);
}
