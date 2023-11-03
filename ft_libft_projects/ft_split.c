/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 07:28:45 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/23 19:23:13 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	counter_word(const char *s, char c)
{
	int	count;
	int	wrd;

	count = 0;
	wrd = 0;
	while (*s)
	{
		if (*s != c && wrd == 0)
		{
			wrd = 1;
			count++;
		}
		else if (*s == c)
			wrd = 0;
		s++;
	}
	return (count);
}

static char	**free_your_malloc(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i] != NULL)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	return (NULL);
}

static char	*alloc_word(const char *s, int start, int end)
{
	int		len;
	char	*word;

	if (start < 0 || end < start || s == NULL)
	{
		return (NULL);
	}
	word = (char *)malloc(end - start + 1);
	if (word == NULL)
	{
		return (NULL);
	}
	len = 0;
	while (start < end)
		word[len++] = s[start++];
	word[len] = '\0';
	return (word);
}

char	**split_string(const char *s, char c, char **result, int arr[4])
{
	while (s[arr[1]])
	{
		if (s[arr[1]] != c)
		{
			arr[3] = arr[1];
			while (s[arr[1]] && s[arr[1]] != c)
				arr[1]++;
			result[arr[2]++] = alloc_word(s, arr[3], arr[1]);
			if (result[arr[2] - 1] == NULL)
				return (free_your_malloc(result));
		}
		else
			arr[1]++;
	}
	result[arr[2]] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		arr[4];
	char	**result;

	arr[0] = counter_word(s, c);
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	result = (char **)malloc((arr[0] + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	result = split_string(s, c, result, arr);
	return (result);
}
