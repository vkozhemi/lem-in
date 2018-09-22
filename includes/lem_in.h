/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:52:58 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/08/30 17:53:16 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include "../libftprintf/includes/libft.h"
# include "../libftprintf/includes/get_next_line.h"
# include "../libftprintf/includes/printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

typedef struct		s_r
{
	char			*n;
	int				num;
	long long		i;
	long long		j;
	int				ant;
	struct s_r		*next;
	struct s_r		*prev;
}					t_r;

typedef struct		s_n
{
	int				*name;
	int				i;
	struct s_n		*next;
	struct s_n		*prev;
}					t_n;

typedef struct		s_c
{
	char			*comment;
	struct s_c		*next;
	struct s_c		*prev;
}					t_c;

typedef struct		s_p
{
	int				**ar;
	char			*map;
	char			*a;
	char			*b;
	int				ants;
	int				*ant;
	int				i;
	int				j;
	int				start;
	int				end;
	int				num_start;
	int				num_end;
	int				num_link;
	int				check_room_a;
	int				check_room_b;
	int				num;
	int				a_n;
	int				b_n;
	int				flag;
	int				min_i;
	int				min_j;
	int				ii;
	int				jj;
	int				save;
	int				fl;
	int				flag_link;
	int				way;
	int				flag_no_way;
	char			**lem_in;
	int				rooms;
	char			*name_room;
	int				f;
	int				k;
	int				count_ant;
	struct s_r		*r;
}					t_p;

/*
** --------------------main------------------------
*/
void				ft_validation(t_p *p, t_r **r);
void				ft_find_distance(t_p *p, int i, int dist);
void				ft_start_end(t_p *p);
/*
**--------------------errors---------------------
*/
void				ft_error_arg(t_r *r, t_p *p);
void				ft_display_error(int flag, t_p *p);
void				ft_display_error2(int flag, t_p *p);
void				ft_error_int(t_p *p, t_r *r);
void				ft_init_struct(t_p *p);
int					ft_my_atoi_lem(const char *str, t_p *p);
/*
**--------------------validation-----------------
*/
void				ft_start(t_p *p, t_r **r, char **line);
void				ft_end(t_p *p, t_r **r, char **line);
void				ft_link(t_p *p, t_r *r, char *line);
void				ft_comment(t_p *p, char *line);
void				ft_get_ants(t_p *p);
/*
**-------------------validation2------------------
*/
void				ft_init_room(t_r **r, char *line, t_p *p, int i);
void				ft_init_room2(t_p *p, int i, char *line);
void				ft_allocate_array(t_p *p, t_r *r);
void				ft_link_array(t_p *p, t_r *r);
void				ft_ants(t_p *p, char *line);
/*
**-------------------walk_room--------------------
*/
void				ft_go_to_room(t_r *r, t_n *n, t_p *p);
void				ft_go_to_room2(t_r *r, t_r *new_r, t_n *new_n, t_p *p);
void				ft_walk_in_room(t_r *r, t_n *n, t_p *p);
t_r					*ft_find_room(t_r *r, int index);
void				ft_print_path(t_n *n, t_r *r);
/*
**-------------------find_path-----------------------
*/
void				ft_allocate_ants(t_n **n);
void				ft_walking_ants2(t_p *p, t_n *n, int *i, int *j);
void				ft_walking_ants(t_p *p, t_n *n, int k);
void				ft_delete_list(t_n **n);
/*
**-------------------check_error---------------------
*/
void				ft_check_coord(t_r *r, t_p *p);
void				ft_check_space(char *line, t_p *p);
void				ft_check_min_in_name(char *str, t_p *p);
void				ft_check_rooms(t_p *p, t_r *r, char *line);
int					ft_check_ants(t_r *r);

#endif
