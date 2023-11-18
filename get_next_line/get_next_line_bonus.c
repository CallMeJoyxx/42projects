/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:26:10 by jtriscar          #+#    #+#             */
/*   Updated: 2023/11/18 19:18:21 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_save(int fd, char *str_save)
{
	char	buff[BUFFER_SIZE + 1];
	int		read_bytes;

	read_bytes = 1;
	while (!ft_strchr(str_save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(str_save);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		str_save = ft_strjoin(str_save, buff);
	}
	return (str_save);
}

char	*ft_get_str(char *tmp)
{
	char	*str;
	int		i;
	int		j;

	if (!tmp)
		return (NULL);
	i = 0;
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
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

char	*ft_save(char *save)
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
	str = (char *)malloc((ft_strlen(save) - c + 1) * sizeof(char));
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
	static char	*str_save[10240];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str_save[fd] = ft_read_save(fd, str_save[fd]);
	if (!str_save[fd])
		return (NULL);
	line = ft_get_str(str_save[fd]);
	str_save[fd] = ft_save(str_save[fd]);
	if (!line || !*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
