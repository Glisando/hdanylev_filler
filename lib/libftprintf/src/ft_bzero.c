/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:29:57 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/06 12:28:42 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

void	ft_bzero(void *b, size_t len)
{
	size_t	i;
	char	*arr;

	if (len == 0)
		return ;
	i = 0;
	arr = b;
	while (i < len)
	{
		arr[i] = '\0';
		i++;
	}
}
