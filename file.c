/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 17:03:50 by yaitalla          #+#    #+#             */
/*   Updated: 2015/08/19 18:32:16 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		screen_clear(void)
{
	tputs(tgetstr("cl", NULL), 1, tputchar);
}

int			size_ok(t_all *all)
{
	if (all->cols - 2 < all->width || all->lins - 2 < all->height)
	{
		screen_clear();
		putcolor("The window is too small.", BOLD_RED, 2, 1);
		return (0);
	}
	else
	{
		screen_clear();
		display(all->llst, all->color);
	}
	return (1);
}

void		resizer(void)
{
	t_all			*all;
	struct winsize	wind;

	all = NULL;
	all = reset(1, all);
	screen_clear();
	ioctl(0, TIOCGWINSZ, &wind);
	all->cols = wind.ws_col;
	all->lins = wind.ws_row;
	size_ok(all);
}

void		signaler(void)
{
	int				i;

	i = 1;
	while (i < 32)
	{
		signal(i, sig_catcher);
		i++;
	}
}
