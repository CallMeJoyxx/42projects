/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:39:19 by jtriscar          #+#    #+#             */
/*   Updated: 2023/11/04 21:59:26 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static char	*ft_next_str(char **tmp)
{
	char	*str;
	char	*ptr;

	ptr = *tmp;
	while (*ptr && *ptr != '\n')
		ptr++;
	ptr += (*ptr == '\n');
	str = ft_substr(*tmp, 0, (unsigned long)(ptr - *tmp));
	if (!str)
	{
		free(*tmp);
		*tmp = NULL;
		return (NULL);
	}
	ptr = ft_strdup(ptr + 1);
	free (*tmp);
	*tmp = ptr;
	return (str);
}

static int	find_nl(const char *buff, int buff_length)
{
	int	i;

	i = 0;
	while (i < buff_length)
	{
		if (buff[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

static char	*ft_read(int fd, int *nl_found)
{
	char	buff[BUFFER_SIZE];
	char	*result;
	int		nl_index;
	int		byt_read;

	result = NULL;
	nl_index = -1;
	while (1)
	{
		byt_read = read(fd, buff, BUFFER_SIZE);
		if (byt_read < 0)
		{
			free(result);
			return (NULL);
		}
		if (byt_read == 0)
		{
			break ;
		}
		nl_index = find_nl(buff, byt_read);
		if (nl_index >= 0)
		{
			*nl_found = 1;
		}
		result = ft_strjoin(result, buff, nl_index);
		if (nl_index >= 0)
		{
			break ;
		}
		nl_index = find_nl(buff, byt_read);
		*nl_found = (nl_index >= 0);
		result = ft_strjoin(result, buff, byt_read);
		if (nl_index >= 0)
			break ;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*part_line;
	char	*nl;
	int		nl_found;

	nl_found = 0;
	line = NULL;
	part_line = ft_read(fd, &nl_found);
	while (part_line != NULL)
	{
		if (nl_found)
		{
			nl = ft_next_str(&part_line);
			line = ft_strjoin(line, nl, ft_strlen(nl));
			free(nl);
			free(part_line);
			break ;
		}
		else
		{
			line = ft_strjoin(line, part_line, ft_strlen(part_line));
			free(part_line);
			part_line = ft_read(fd, &nl_found);
		}
	}
	return (line);
}
