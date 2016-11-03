/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 23:49:47 by yaitalla          #+#    #+#             */
/*   Updated: 2015/08/18 20:22:08 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void		canceller(void)
{
	t_all		*all;

	all = NULL;
	all = reset(1, all);
	termclose(all);
	exit(0);
}

static void		continuer(void)
{
	t_all		*all;

	all = NULL;
	all = reset(1, all);
	all->term.c_lflag &= ~(ICANON | ECHO);
	all->term.c_cc[VMIN] = 1;
	all->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &(all->term));
	tputs(tgetstr("ti", NULL), 1, tputchar);
	tputs(tgetstr("vi", NULL), 1, tputchar);
	signal(SIGTSTP, sig_catcher);
	resizer();
	size_ok(all);
}

static void		stopper(void)
{
	t_all		*all;
	char		cp[2];

	all = NULL;
	all = reset(1, all);
	cp[0] = all->term.c_cc[VSUSP];
	cp[1] = 0;
	all->term.c_lflag |= (ICANON | ECHO);
	signal(SIGTSTP, SIG_DFL);
	screen_clear();
	tcsetattr(0, 0, &(all->term));
	tputs(tgetstr("te", NULL), 1, tputchar);
	tputs(tgetstr("ve", NULL), 1, tputchar);
	ioctl(0, TIOCSTI, cp);
}

void			sig_catcher(int i)
{
	if (i == SIGCONT)
		continuer();
	else if (i == SIGTSTP)
		stopper();
	else if (i == SIGWINCH)
		resizer();
	else
		canceller();
}

void			key_action(t_all *all, char buf[3])
{
	if (K_UP)
		go_up(all);
	if (K_DOWN)
		go_down(all);
	if (K_SPACE)
		go_space(all);
	if (recurcmp(buf, ":") == 0)
	{
		if (all->color < 2)
			all->color++;
		else
			all->color = 0;
	}
}
