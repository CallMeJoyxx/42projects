/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 06:24:48 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/22 06:32:07 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	char	n_l;

	n_l = '\n';
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, &n_l, 1);
}
