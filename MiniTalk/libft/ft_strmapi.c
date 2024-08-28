/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 07:12:56 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/22 07:17:11 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned long	len;
	unsigned long	i;
	char			*cpy;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	cpy = (char *)malloc(len + 1);
	if (cpy == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		cpy[i] = f(i, s[i]);
		i++;
	}
	cpy[len] = '\0';
	return (cpy);
}
