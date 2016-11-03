/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 07:15:32 by yaitalla          #+#    #+#             */
/*   Updated: 2015/08/18 23:15:23 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		test(t_all *all)
{
	int			i;

	i = 0;
	while (all->height)
	{
		if (all->llst->selected == 1)
		{
			ft_putstr_fd(all->llst->content, 1);
			ft_putchar(' ');
			all->llst->selected = 0;
			i = 1;
		}
		all->height--;
		all->llst = all->llst->next;
	}
	if (i)
		ft_putchar('\n');
}

int			terminit(t_all *all)
{
	struct winsize	win;

	if (tgetent(NULL, getenv("TERM")) < 1)
		return (0);
	if (tcgetattr(0, &(all->term)) == -1)
		return (0);
	all->term.c_lflag &= ~(ICANON | ECHO);
	all->term.c_cc[VMIN] = 1;
	all->term.c_cc[VTIME] = 0;
	ioctl(0, TIOCGWINSZ, &win);
	all->lins = win.ws_row;
	all->cols = win.ws_col;
	if (tcsetattr(0, 0, &(all->term)) == -1)
		return (0);
	tputs(tgetstr("ti", NULL), 1, tputchar);
	tputs(tgetstr("vi", NULL), 1, tputchar);
	return (1);
}

int			termclose(t_all *all)
{
	all->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(all->term)) == -1)
		return (0);
	tputs(tgetstr("te", NULL), 1, tputchar);
	tputs(tgetstr("ve", NULL), 1, tputchar);
	return (1);
}

static void	go(t_all *all, char **av)
{
	screen_clear();
	fill_list(av, all);
	display(all->llst, all->color);
	size_ok(all);
	reset(0, all);
	while (1)
	{
		if (!key_ok(all))
			return ;
	}
}

int			main(int ac, char **av)
{
	t_all		all;

	if (ac == 1)
	{
		putcolor("Too few parameters", BOLD_MAGENTA, 2, 1);
		exit(0);
	}
	all.llst = NULL;
	signaler();
	if (!terminit(&all))
		return (1);
	go(&all, av);
	if (!termclose(&all))
		return (1);
	if (all.enter)
		test(&all);
	return (0);
}
