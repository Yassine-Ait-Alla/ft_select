/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 04:08:13 by yaitalla          #+#    #+#             */
/*   Updated: 2015/01/23 01:17:31 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				e_len(char *s)
{
	size_t				i;

	i = 0;
	while (s[i] != '=' && s[i])
		i++;
	return (i);
}
