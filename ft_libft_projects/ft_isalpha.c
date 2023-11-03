/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:35:45 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/12 19:21:07 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int character)
{
	if ((character >= 'A' && character <= 'Z')
		|| (character >= 'a' && character <= 'z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
