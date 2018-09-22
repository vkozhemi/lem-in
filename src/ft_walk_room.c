/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walk_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:22:41 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/09/13 18:22:43 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_r		*ft_find_room(t_r *r, int index)
{
	t_r *new_r;

	new_r = r;
	while (new_r)
	{
		if (new_r->num == index)
			return (new_r);
		new_r = new_r->next;
	}
	return (NULL);
}

void	ft_walk_in_room(t_r *r, t_n *n, t_p *p)
{
	t_r		*new_r;
	t_n		*new_n;

	p->count_ant = 1;
	new_r = r;
	while (p->count_ant <= p->ants || ft_check_ants(r))
	{
		ft_go_to_room(r, n, p);
		ft_go_to_room(r, n, p);
		ft_bzero(p->ant, sizeof(int) * p->ants);
		new_n = n;
		while (new_n)
		{
			new_r = ft_find_room(r, new_n->name[0]);
			if (new_r->ant == 0 && p->count_ant <= p->ants)
			{
				new_r->ant = p->count_ant++;
				ft_printf("L%d-%s ", new_r->ant,
					ft_find_room(r, new_r->num)->n);
			}
			new_n = new_n->next;
		}
		ft_printf("\n");
	}
}

void	ft_go_to_room2(t_r *r, t_r *new_r, t_n *new_n, t_p *p)
{
	t_r		*new_r2;

	p->ant[new_r->ant - 1] = 1;
	new_r2 = ft_find_room(r, new_n->name[p->j + 1]);
	if (new_r2->num != p->end)
		new_r2->ant = new_r->ant;
	ft_printf("L%d-%s ", new_r->ant, new_r2->n);
	new_r->ant = 0;
}

void	ft_go_to_room(t_r *r, t_n *n, t_p *p)
{
	t_r		*new_r;
	t_n		*new_n;

	new_r = r;
	while (new_r)
	{
		if (new_r->ant)
		{
			new_n = n;
			while (new_n)
			{
				p->j = 0;
				while (p->j < new_n->i)
				{
					if (new_n->name[p->j] == new_r->num &&
						p->ant[new_r->ant - 1] == 0)
						ft_go_to_room2(r, new_r, new_n, p);
					p->j++;
				}
				new_n = new_n->next;
			}
		}
		new_r = new_r->next;
	}
}

void	ft_print_path(t_n *n, t_r *r)
{
	t_n		*new_n;
	t_r		*tmp_r;
	int		i;
	int		j;

	j = 0;
	new_n = n;
	while (new_n)
	{
		i = -1;
		ft_printf("%Way [%d] ", j++);
		while (++i < new_n->i)
		{
			tmp_r = r;
			while (tmp_r)
			{
				if (new_n->name[i] == tmp_r->num)
					ft_printf("->(%s)", tmp_r->n);
				tmp_r = tmp_r->next;
			}
		}
		new_n = new_n->next;
		ft_printf("\n");
	}
	ft_printf("\n");
}
