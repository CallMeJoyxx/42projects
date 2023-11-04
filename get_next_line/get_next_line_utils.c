/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:50:48 by jtriscar          #+#    #+#             */
/*   Updated: 2023/11/04 21:15:42 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	unsigned long	len;
	unsigned long	i;
	char			*cpy;

	len = 0;
	while (s1[len] != '\0')
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
		cpy[i] = s1[i];
		i++;
	}
	cpy[len] = '\0';
	return (cpy);
}

char	*ft_strjoin(const char *s1, const char *s2, unsigned long len)
{
	unsigned long	s1_len;
	char			*new_s;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	new_s = (char *)malloc(s1_len + len + 1);
	if (!new_s)
		return (NULL);
	ft_memcpy(new_s, s1, s1_len);
	ft_memcpy(new_s + s1_len, s2, len);
	new_s[s1_len + len] = '\0';
	return (new_s);
}

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

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, unsigned long n)
{
	unsigned long		i;
	char				*d;
	char				*s;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (dest == (void *)0 && src == (void *)0)
		return ((void *)0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
