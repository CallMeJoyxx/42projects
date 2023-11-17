/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:07:16 by jtriscar          #+#    #+#             */
/*   Updated: 2023/11/17 21:07:24 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_save(int fd, char *nl_found)
{
	static char	*buff;
	int			read_bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(nl_found, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			free(nl_found);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		nl_found = ft_strjoin(nl_found, buff);
	}
	free(buff);
	return (nl_found);
}

static char	*ft_get_str(char *tmp)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	j = 0;
	while (tmp[j] != '\0' && tmp[j] != '\n')
	{
		str[j] = tmp[j];
		j++;
	}
	if (tmp[j] == '\n')
	{
		str[j] = tmp[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

static char	*ft_save(char *save)
{
	char	*str;
	int		c;
	int		i;

	if (!save)
		return (NULL);
	c = 0;
	while (save[c] && save[c] != '\n')
		c++;
	if (!save[c])
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(save) - c + 1);
	if (!str)
		return (NULL);
	c++;
	i = 0;
	while (save[c])
		str[i++] = save[c++];
	str[i] = '\0';
	free(save);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*st_save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	st_save = ft_read_save(fd, st_save);
	if (!st_save)
		return (NULL);
	line = ft_get_str(st_save);
	st_save = ft_save(st_save);
	if (!line || !*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
