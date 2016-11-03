/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 15:26:39 by yaitalla          #+#    #+#             */
/*   Updated: 2015/08/18 23:10:13 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		go_space(t_all *all)
{
	t_tab		*lst;

	lst = all->llst;
	while (!lst->current)
		lst = lst->next;
	lst->selected = lst->selected == 0 ? 1 : 0;
	lst->current = 0;
	lst->next->current = 1;
}

void		go_down(t_all *all)
{
	t_tab		*lst;

	lst = all->llst;
	while (lst->current != 1)
		lst = lst->next;
	lst->current = 0;
	lst->next->current = 1;
}

void		go_up(t_all *all)
{
	t_tab		*lst;

	lst = all->llst;
	while (lst->current != 1)
		lst = lst->next;
	lst->current = 0;
	lst->prev->current = 1;
}

static int	go_del(t_all *all)
{
	t_tab		*lst;

	if (all->llst == all->llst->next)
	{
		free(all->llst);
		return (0);
	}
	lst = all->llst;
	if (all->llst->current == 1)
		all->llst = all->llst->next;
	else
	{
		while (lst->current != 1)
			lst = lst->next;
	}
	lst->prev->next = lst->next;
	lst->next->prev = lst->prev;
	lst->next->current = 1;
	free(lst->content);
	free(lst);
	all->height--;
	return (1);
}

int			key_ok(t_all *all)
{
	char		buf[3];

	ft_memset(buf, 0, 3);
	read(0, buf, 3);
	if (K_ECHAP)
		return (0);
	if (size_ok(all))
	{
		key_action(all, buf);
		if (K_DEL || K_BAKSP)
		{
			if (!go_del(all))
				return (0);
		}
		if (K_ENTER)
		{
			all->enter = 1;
			return (0);
		}
		screen_clear();
		display(all->llst, all->color);
	}
	return (1);
}
