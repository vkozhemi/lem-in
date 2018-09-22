/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:35:18 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/09/13 18:35:20 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_allocate_ants(t_n **n)
{
	t_n		*new_n;
	t_n		*tmp;

	new_n = (t_n*)malloc(sizeof(t_n));
	new_n->next = NULL;
	tmp = *n;
	if (!tmp)
	{
		new_n->prev = NULL;
		*n = new_n;
		(*n)->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_n;
		new_n->prev = tmp;
	}
}

void	ft_start_end(t_p *p)
{
	int i;

	i = 0;
	while (++i <= p->ants)
		ft_printf("L%d-%s ", i, ft_find_room(p->r, p->end)->n);
	ft_printf("\n");
	exit(1);
}

void	ft_walking_ants2(t_p *p, t_n *n, int *i, int *j)
{
	p->min_j = p->ar[*i][*j];
	if (++p->f == 0)
	{
		n->name = malloc(sizeof(int) * (p->min_j));
		n->i = p->min_j;
	}
	if (p->ar[p->start][*j] == 1 || p->ar[*j][p->start] == 1)
		ft_start_end(p);
	if (p->ar[*i][*j] == 1)
		p->ar[*i][*j] = 1;
	else
		p->ar[*i][*j] = 0;
	if (p->ar[*j][*i] == 1)
		p->ar[*j][*i] = 1;
	else
		p->ar[*j][*i] = 0;
	p->ii = *i;
	p->jj = *j;
}

void	ft_walking_ants(t_p *p, t_n *n, int k)
{
	int i;
	int j;

	p->f = -1;
	p->rooms = 0;
	p->min_i = 2147483647;
	i = p->start;
	while (n->next)
		n = n->next;
	while (i < p->num)
	{
		p->fl = 0;
		j = -1;
		p->min_j = 2147483647;
		while (++j < p->num)
			if (p->ar[i][j] > 0 && p->min_j > p->ar[i][j])
				ft_walking_ants2(p, n, &i, &j);
		if (p->min_j == p->min_i && ++p->flag_no_way)
			return ;
		p->min_i = p->min_j;
		i = p->jj;
		n->name[k++] = i;
		if (i == p->end && ++p->way)
			return ;
	}
}

void	ft_delete_list(t_n **n)
{
	t_n		*del;

	del = *n;
	while (del->next)
		del = del->next;
	if (del->prev)
		del->prev->next = NULL;
	else
		*n = NULL;
	free(del);
}
