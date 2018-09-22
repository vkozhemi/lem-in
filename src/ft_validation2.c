/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 18:12:55 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/09/05 18:12:58 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_init_room(t_r **r, char *line, t_p *p, int i)
{
	t_r			*new_r;
	char		**str;

	if (ft_countwords(line, ' ') != 3)
		ft_display_error(1, p);
	ft_check_space(line, p);
	str = ft_strsplit(line, ' ');
	new_r = (t_r*)malloc(sizeof(t_r));
	if (str[0][0] == 'L')
		ft_display_error(9, p);
	ft_check_min_in_name(str[0], p);
	new_r->ant = 0;
	new_r->n = ft_strdup(str[0]);
	new_r->i = ft_my_atoi_lem(str[1], p);
	new_r->j = ft_my_atoi_lem(str[2], p);
	ft_check_coord(*r, p);
	ft_error_int(p, new_r);
	new_r->num = p->num;
	ft_init_room2(p, i, line);
	if (*r)
		(*r)->prev = new_r;
	new_r->prev = NULL;
	new_r->next = *r;
	*r = new_r;
	ft_splitdel(str);
}

void	ft_init_room2(t_p *p, int i, char *line)
{
	if (i == 1)
		p->start = p->num;
	if (i == 2)
		p->end = p->num;
	if (p->flag_link)
		ft_display_error(10, p);
	p->map = ft_strjoin_free(p->map, line);
	p->map = ft_strjoin_free(p->map, "\n");
	p->num++;
}

void	ft_allocate_array(t_p *p, t_r *r)
{
	int		k;
	t_r		*tmp_r;
	t_r		*tmp_r2;
	int		num;

	p->ar = ft_memalloc(sizeof(int **) * p->num);
	k = -1;
	while (++k < p->num)
		p->ar[k] = ft_memalloc(sizeof(int *) * p->num);
	tmp_r = r;
	while (tmp_r)
	{
		num = tmp_r->num;
		tmp_r2 = r;
		while (tmp_r2)
		{
			p->ar[num][tmp_r2->num] = 0;
			tmp_r2 = tmp_r2->next;
		}
		tmp_r = tmp_r->next;
	}
}

void	ft_link_array(t_p *p, t_r *r)
{
	t_r		*tmp_r;
	t_r		*tmp_r2;
	int		num;

	tmp_r = r;
	while (tmp_r)
	{
		num = tmp_r->num;
		tmp_r2 = r;
		while (tmp_r2)
		{
			if (num == p->b_n && tmp_r2->num == p->a_n)
			{
				p->ar[num][tmp_r2->num] = 2147483647;
				p->ar[tmp_r2->num][num] = 2147483647;
			}
			tmp_r2 = tmp_r2->next;
		}
		tmp_r = tmp_r->next;
	}
}

void	ft_ants(t_p *p, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0)
			ft_display_error(8, p);
		i++;
	}
	p->ants = ft_atoi(line);
	p->map = ft_strjoin_free(p->map, line);
	p->map = ft_strjoin_free(p->map, "\n");
	if ((p->ants < 1) || (p->ants > 2147483647))
		ft_display_error(8, p);
	p->ant = malloc(sizeof(int) * p->ants);
	j = 0;
	while (j < p->ants)
		p->ant[j++] = 0;
}
