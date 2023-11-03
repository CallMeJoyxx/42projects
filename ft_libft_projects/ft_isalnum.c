/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:02:50 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/12 19:24:30 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int character)
{
	if ((character >= 'A' && character <= 'Z')
		|| (character >= 'a' && character <= 'z')
		|| (character >= '0' && character <= '9'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
