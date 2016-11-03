/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 18:34:12 by yaitalla          #+#    #+#             */
/*   Updated: 2015/08/18 20:22:02 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int			tputchar(int c)
{
	write(2, &c, 1);
	return (0);
}

void		process(t_tab *lst)
{
	if (lst->selected == 1 && lst->current == 1)
	{
		tputs(tgetstr("us", NULL), 1, tputchar);
		tputs(tgetstr("so", NULL), 1, tputchar);
		ft_putendl_fd(lst->content, 2);
		tputs(tgetstr("se", NULL), 1, tputchar);
		tputs(tgetstr("ue", NULL), 1, tputchar);
	}
	else if (lst->current == 1 && lst->selected == 0)
	{
		tputs(tgetstr("us", NULL), 1, tputchar);
		ft_putendl_fd(lst->content, 2);
		tputs(tgetstr("ue", NULL), 1, tputchar);
	}
	else if (lst->selected == 1 && lst->current == 0)
	{
		tputs(tgetstr("so", NULL), 1, tputchar);
		ft_putendl_fd(lst->content, 2);
		tputs(tgetstr("se", NULL), 1, tputchar);
	}
	else
		ft_putendl_fd(lst->content, 2);
}

void		display(t_tab *lst, int color)
{
	t_tab		*temp;

	temp = NULL;
	display_check(lst, color);
	temp = lst->next;
	while (temp != lst)
	{
		display_check(temp, color);
		temp = temp->next;
	}
}
