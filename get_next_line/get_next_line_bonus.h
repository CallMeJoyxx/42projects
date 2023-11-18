/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:13:41 by jtriscar          #+#    #+#             */
/*   Updated: 2023/11/18 22:13:35 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

char			*get_next_line(int fd);

int				ft_strlen(const char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(char *s, int c);
void			*ft_calloc(unsigned long count, unsigned long size);

#endif
