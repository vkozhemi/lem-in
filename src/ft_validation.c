/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 19:27:09 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/09/04 19:27:26 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_start(t_p *p, t_r **r, char **line)
{
	p->map = ft_strjoin_free(p->map, *line);
	p->map = ft_strjoin_free(p->map, "\n");
	free(*line);
	get_next_line(0, line);
	p->i++;
	ft_init_room(r, *line, p, 1);
}

void	ft_end(t_p *p, t_r **r, char **line)
{
	p->map = ft_strjoin_free(p->map, *line);
	p->map = ft_strjoin_free(p->map, "\n");
	free(*line);
	get_next_line(0, line);
	p->i++;
	ft_init_room(r, *line, p, 2);
}

void	ft_link(t_p *p, t_r *r, char *line)
{
	int i;

	i = 0;
	p->num_link = 0;
	while (line[i])
		if (line[i++] == '-')
			p->num_link++;
	if (line[0] == '-' || line[ft_strlen(line) - 1] == '-')
		ft_display_error(5, p);
	if (p->num_link != 1)
		ft_display_error(5, p);
	ft_check_rooms(p, r, line);
	if (++p->flag == 0)
		ft_allocate_array(p, r);
	ft_link_array(p, r);
	p->flag_link = 1;
	p->map = ft_strjoin_free(p->map, line);
	p->map = ft_strjoin_free(p->map, "\n");
}

void	ft_comment(t_p *p, char *line)
{
	p->map = ft_strjoin_free(p->map, line);
	p->map = ft_strjoin_free(p->map, "\n");
}

void	ft_get_ants(t_p *p)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	if (!line)
		ft_display_error(14, p);
	while (line[0] == '#')
	{
		p->map = ft_strjoin_free(p->map, line);
		free(line);
		get_next_line(0, &line);
	}
	ft_ants(p, line);
}
