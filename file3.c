/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 13:28:20 by yaitalla          #+#    #+#             */
/*   Updated: 2015/08/18 20:22:13 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_all		*reset(int i, t_all *all)
{
	static t_all	*temp = NULL;

	if (!i)
		temp = all;
	return (temp);
}

void		display_check(t_tab *lst, int color)
{
	if (color == 0)
		process(lst);
	else if (color == 1)
		process1(lst);
	else if (color == 2)
		process2(lst);
}

void		process1(t_tab *lst)
{
	if (lst->selected == 1 && lst->current == 1)
	{
		tputs(tgetstr("us", NULL), 1, tputchar);
		tputs(tgetstr("so", NULL), 1, tputchar);
		putcolor(lst->content, CYAN, 1, 1);
		tputs(tgetstr("se", NULL), 1, tputchar);
		tputs(tgetstr("ue", NULL), 1, tputchar);
	}
	else if (lst->current == 1 && lst->selected == 0)
	{
		tputs(tgetstr("us", NULL), 1, tputchar);
		putcolor(lst->content, GREEN, 1, 1);
		tputs(tgetstr("ue", NULL), 1, tputchar);
	}
	else if (lst->selected == 1 && lst->current == 0)
	{
		tputs(tgetstr("so", NULL), 1, tputchar);
		putcolor(lst->content, YELLOW, 1, 1);
		tputs(tgetstr("se", NULL), 1, tputchar);
	}
	else
		putcolor(lst->content, BOLD_LIGHT_GREY, 1, 1);
}

void		process2(t_tab *lst)
{
	if (lst->selected == 1 && lst->current == 1)
	{
		tputs(tgetstr("us", NULL), 1, tputchar);
		tputs(tgetstr("so", NULL), 1, tputchar);
		putcolor(lst->content, BROWN, 1, 1);
		tputs(tgetstr("se", NULL), 1, tputchar);
		tputs(tgetstr("ue", NULL), 1, tputchar);
	}
	else if (lst->current == 1 && lst->selected == 0)
	{
		tputs(tgetstr("us", NULL), 1, tputchar);
		putcolor(lst->content, MAGENTA, 1, 1);
		tputs(tgetstr("ue", NULL), 1, tputchar);
	}
	else if (lst->selected == 1 && lst->current == 0)
	{
		tputs(tgetstr("so", NULL), 1, tputchar);
		putcolor(lst->content, CYAN, 1, 1);
		tputs(tgetstr("se", NULL), 1, tputchar);
	}
	else
		putcolor(lst->content, BOLD_LIGHT_GREY, 1, 1);
}
