/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 04:24:26 by yaitalla          #+#    #+#             */
/*   Updated: 2015/04/15 23:04:33 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL && tab[i][0] != 0)
		i++;
	return (i);
}