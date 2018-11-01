/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:34:42 by smokhtar          #+#    #+#             */
/*   Updated: 2018/08/15 17:34:43 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "libft.h"
# include "/usr/include/sys/syslimits.h"
# include "/usr/include/sys/xattr.h"
# include "errno.h"

# define A 2
# define L 4
# define R 8
# define RR 16
# define T 32
# define TIRER 64
# define NO_WORD 128
# define F 256
# define N 512
# define ERRORT "ls: illegal option -- -\nusage: ls [-alrtR] [file ...]\n"
# define XATT XATTR_NOFOLLOW

int					g_option;

typedef struct		s_arg
{
	char			*name;
	DIR				*dirp;
}					t_arg;

typedef struct		s_dirp
{
	char			path[PATH_MAX];
	char			name[FILENAME_MAX];
	struct dirent	*dir;
	struct stat		info;
	struct s_dirp	*prev;
	struct s_dirp	*next;
}					t_dirp;

typedef struct		s_lprint
{
	int				link;
	int				poid;
	int				uid;
	int				gid;
}					t_lprint;

/*
**		ft_ls
*/

DIR					*test_open(char *filename, int i);

/*
**		parseur
*/

int					parser(char **av);
t_arg				**argument(char **av, int len, int i, int e);

/*
**		read_dir
*/

t_dirp				*read_dir(DIR *dirp, char *filename);
void				read_file(t_dirp *lst, char *path);

/*
**		start_print
*/

void				start_print(t_dirp *lst, char *filename, int i);

/*
**		print_l
*/

void				set_tab(t_lprint *tab);
void				prin_n(int str, int space, int more);
void				prin_s(char *str, int space, int more);
void				print_perm(mode_t perm);
void				print_id(t_dirp *lst, t_lprint *tab);

/*
**		check_file
*/

void				check_file(t_dirp *lst);
t_dirp				*free_lst(t_dirp *lst);
void				free_lst_all(t_dirp *lst);

/*
**		list
*/

void				my_lst_put_in(t_dirp *lst, t_dirp *put);
t_dirp				*my_lstnew(char *path);
void				my_lst_add(t_dirp *lst, t_dirp *add);
t_dirp				*my_lst_insr(t_dirp *lst, t_dirp *new);
t_dirp				*get_lst_end(t_dirp *lst, int i);

/*
**			insert_sort
*/

t_dirp				*get_file_at(t_dirp *file, int index);
t_dirp				*sort_ascii(t_dirp *file, int size);
t_dirp				*get_first_dirp(t_dirp *file);
void				inser_sort(t_dirp **file);
void				swap_far(t_dirp *a, t_dirp *b);
void				swap_next(t_dirp *a, t_dirp *b);
int					ft_nbrlen(int nb);

#endif
