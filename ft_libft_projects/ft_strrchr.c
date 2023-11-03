/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:22:25 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/22 03:32:15 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*lst;

	lst = ((void *)0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			lst = ((char *)(s + i));
		i++;
	}
	if ((char)c == s[i])
	{
		return ((char *)(s + i));
	}
	return (lst);
}
