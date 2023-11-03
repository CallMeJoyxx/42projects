/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:46:16 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/22 02:29:22 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		arr[3];
	char	*str;

	arr[0] = 1;
	if (n < 0)
		arr[0] = -1;
	arr[1] = n;
	arr[2] = (n <= 0);
	while (arr[1] != 0)
	{
		arr[1] /= 10;
		arr[2]++;
	}
	str = (char *)malloc(arr[2] + 1);
	if (str == NULL)
		return (NULL);
	str[arr[2]] = '\0';
	while (arr[2] > 0)
	{
		str[--arr[2]] = '0' + (n % 10) * arr[0];
		n /= 10;
	}
	if (arr[0] == -1)
		str[0] = '-';
	return (str);
}
