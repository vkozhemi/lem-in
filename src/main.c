/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:47:49 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/08/30 17:47:51 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_init_struct(t_p *p)
{
	p->i = 1;
	p->start = 0;
	p->end = 0;
	p->num_start = 0;
	p->num_end = 0;
	p->num_link = 0;
	p->num = 0;
	p->flag = -1;
	p->flag_link = 0;
	p->way = 0;
	p->flag_no_way = 0;
	p->map = ft_strnew(0);
}

void	ft_validation(t_p *p, t_r **r)
{
	char	*line;

	ft_init_struct(p);
	ft_get_ants(p);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, "##start") && ++p->num_start)
			ft_start(p, r, &line);
		else if (!ft_strcmp(line, "##end") && ++p->num_end)
			ft_end(p, r, &line);
		else if (line[0] == '#')
			ft_comment(p, line);
		else if (ft_strchr(line, '-'))
		{
			if (ft_countwords(line, ' ') == 3)
				ft_init_room(r, line, p, 0);
			else if (ft_countwords(line, ' ') == 1 &&
				ft_countwords(line, '-') == 2)
				ft_link(p, *r, line);
		}
		else if (ft_countwords(line, ' ') == 3)
			ft_init_room(r, line, p, 0);
		p->i++;
		free(line);
	}
}

void	ft_find_distance(t_p *p, int i, int dist)
{
	int j;

	j = 0;
	while (j < p->num)
	{
		if (i == p->start)
			return ;
		else if (j != p->end)
		{
			if (p->ar[i][j] > dist && p->ar[i][j] > 0)
			{
				p->ar[i][j] = dist;
				p->ar[j][i] = dist;
				ft_find_distance(p, j, dist + 1);
			}
		}
		j++;
	}
}

void	ft_cmp_ants_ways(t_n **n, t_p *p)
{
	t_n		*new_n;
	t_n		*temp;
	int		i;

	i = p->ants;
	new_n = (*n)->next;
	while (new_n)
	{
		i = i - new_n->i;
		if (i < 0)
			i = 0;
		if (i < new_n->i - 1)
		{
			temp = new_n->next;
			new_n->prev->next = temp;
			if (temp)
				temp->prev = new_n->prev;
			free(new_n->name);
			free(new_n);
			new_n = temp;
		}
		else
			new_n = new_n->next;
	}
}

int		main(void)
{
	t_r		*r;
	t_p		*p;
	t_n		*n;

	p = (t_p*)malloc(sizeof(t_p));
	r = NULL;
	n = NULL;
	ft_validation(p, &r);
	ft_error_arg(r, p);
	ft_find_distance(p, p->end, 1);
	p->r = r;
	while (!p->flag_no_way)
	{
		ft_allocate_ants(&n);
		ft_walking_ants(p, n, 0);
		if (p->flag_no_way)
			ft_delete_list(&n);
	}
	if (!n)
		ft_display_error(13, p);
	printf("%s\n", p->map);
	ft_cmp_ants_ways(&n, p);
	ft_print_path(n, r);
	ft_walk_in_room(r, n, p);
	return (0);
}
