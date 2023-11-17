/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:37:54 by jtriscar          #+#    #+#             */
/*   Updated: 2023/11/17 21:07:39 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

char			*get_next_line(int fd);

int				ft_strlen(const char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(char *s, int c);
void			*ft_calloc(unsigned long count, unsigned long size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned long size);

#endif
