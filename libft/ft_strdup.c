/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:37:05 by yaitalla          #+#    #+#             */
/*   Updated: 2015/01/28 11:55:49 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s1) + 1;
	new = (char *)malloc(sizeof(char) * len);
	if (new == NULL)
		return (NULL);
	return (ft_strcpy(new, s1));
}
