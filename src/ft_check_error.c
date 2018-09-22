/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 20:54:23 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/09/15 20:54:25 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_check_ants(t_r *r)
{
	t_r		*new_r;
	int		i;
	int		j;

	new_r = r;
	i = 0;
	j = 0;
	while (new_r)
	{
		if (!new_r->ant)
			i++;
		new_r = new_r->next;
		j++;
	}
	if (i == j)
		return (0);
	return (1);
}

void	ft_check_coord(t_r *r, t_p *p)
{
	t_r	*new_r;
	t_r	*new_r2;

	new_r = r;
	new_r2 = r;
	while (new_r2)
	{
		if (new_r->num != new_r2->num && new_r->i == new_r2->i &&
			new_r->j == new_r2->j)
			ft_display_error(12, p);
		if (new_r->num != new_r2->num && !ft_strcmp(new_r->n, new_r2->n))
			ft_display_error(12, p);
		new_r2 = new_r2->next;
	}
}

void	ft_check_space(char *line, t_p *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '-')
			j++;
		i++;
	}
	if (j > 2)
		ft_display_error(11, p);
}

void	ft_check_min_in_name(char *str, t_p *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	if (j > 0)
		ft_display_error(9, p);
}

void	ft_check_rooms(t_p *p, t_r *r, char *line)
{
	t_r		*tmp_r;
	char	**str;

	str = ft_strsplit(line, '-');
	p->a = ft_strdup(str[0]);
	p->b = ft_strdup(str[1]);
	tmp_r = r;
	ft_check_space(line, p);
	p->check_room_a = 0;
	p->check_room_b = 0;
	while (tmp_r)
	{
		if (!ft_strcmp(tmp_r->n, p->a) && ++p->check_room_a)
			p->a_n = tmp_r->num;
		if (!ft_strcmp(tmp_r->n, p->b) && ++p->check_room_b)
			p->b_n = tmp_r->num;
		tmp_r = tmp_r->next;
	}
	if (!p->check_room_a || !p->check_room_b)
		ft_display_error(6, p);
	if (p->a)
		free(p->a);
	if (p->b)
		free(p->b);
	ft_splitdel(str);
}
