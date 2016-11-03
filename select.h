/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/24 21:48:42 by yaitalla          #+#    #+#             */
/*   Updated: 2015/08/18 20:22:04 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include "libft.h"
# include "colors.h"
# include <termcap.h>
# include <dirent.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <signal.h>

# define K_UP		(buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
# define K_DOWN		(buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
# define K_ENTER	(buf[0] == 10 && !buf[1] && !buf[2])
# define K_ECHAP	(buf[0] == 27 && !buf[1] && !buf[2])
# define K_SPACE	(buf[0] == 32 && !buf[1] && !buf[2])
# define K_DEL		(buf[0] == 127 && !buf[1] && !buf[2])
# define K_BAKSP	(buf[0] == 27 && buf[1] == 91 && buf[2] == 51)

typedef struct		s_tab
{
	int				max_len;
	int				selected;
	int				current;
	char			*content;
	struct s_tab	*next;
	struct s_tab	*prev;
}					t_tab;

typedef struct		s_all
{
	struct termios	term;
	int				enter;
	int				color;
	int				size_ok;
	int				cols;
	int				lins;
	int				width;
	int				height;
	t_tab			*llst;
}					t_all;

int					termclose(t_all *all);
t_all				*reset(int i, t_all *all);
void				go_space(t_all *all);
void				go_down(t_all *all);
void				go_up(t_all *all);
void				key_action(t_all *all, char buf[3]);
int					terminit(t_all *all);
void				resizer(void);
void				signaler(void);
void				sig_catcher(int i);
int					recurcmp(char *s1, char *s2);
void				return_key(t_all *all);
int					delete_test();
int					key_ok(t_all *all);
int					size_ok(t_all *all);
void				process(t_tab *lst);
void				process1(t_tab *lst);
void				process2(t_tab *lst);
void				display(t_tab *lst, int color);
void				display_check(t_tab *lst, int color);
t_tab				*save(char *str);
t_tab				*lst_init(void);
void				get_lst(t_all *all, t_tab *lst);
void				fill_list(char **av, t_all *all);
int					tputchar(int c);
void				screen_clear(void);

#endif
