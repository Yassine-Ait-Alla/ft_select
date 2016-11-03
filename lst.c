/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 13:16:47 by yaitalla          #+#    #+#             */
/*   Updated: 2015/08/18 19:02:53 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_tab		*lst_init(void)
{
	t_tab		*lst;

	lst = (t_tab *)malloc(sizeof(t_tab));
	lst->max_len = 0;
	lst->selected = 0;
	lst->current = 0;
	lst->content = NULL;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

t_tab		*save(char *str)
{
	t_tab		*lst;

	lst = lst_init();
	lst->max_len = ft_strlen(str);
	lst->content = ft_strdup(str);
	return (lst);
}

void		get_lst(t_all *all, t_tab *lst)
{
	t_tab		*temp;

	if (all->llst == NULL)
	{
		lst->prev = lst;
		lst->next = lst;
		all->llst = lst;
		lst->current = 1;
	}
	else
	{
		temp = all->llst->prev;
		temp->next = lst;
		lst->next = all->llst;
		lst->prev = temp;
		all->llst->prev = lst;
	}
}

void		fill_list(char **av, t_all *all)
{
	int			i;
	t_tab		*temp;

	i = 1;
	while (av[i])
	{
		temp = save(av[i]);
		get_lst(all, temp);
		i++;
	}
	all->height = i;
	while (i > 1)
	{
		if (all->width < all->llst->max_len)
			all->width = all->llst->max_len;
		all->llst = all->llst->next;
		i--;
	}
	all->enter = 0;
	all->color = 0;
}
