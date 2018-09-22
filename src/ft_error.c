/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 19:25:25 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/09/01 19:25:28 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_display_error(int flag, t_p *p)
{
	if (flag == 1)
		ft_printf("ERROR: invalid numbers of arg, need 3, (line %d)\n", p->i);
	else if (flag == 2)
		ft_printf("ERROR: need one ##start, start = %d\n", p->start);
	else if (flag == 3)
		ft_printf("ERROR: need one ##end, end = %d\n", p->end);
	else if (flag == 4)
		ft_printf("ERROR: empty line, (line %d)\n", p->i);
	else if (flag == 5)
		ft_printf("ERROR: need one link between rooms\n");
	else if (flag == 6)
		ft_printf("ERROR: does not exist room, (line %d)\n", p->i);
	else if (flag == 7)
		ft_printf("ERROR: coordinates are not int, (line %d)\n", p->i);
	else if (flag == 8)
		ft_printf("ERROR: wrong number of ants, (line %d)\n", p->i);
	else if (flag == 9)
		ft_printf("ERROR: wrong name of room, (line %d)\n", p->i);
	else if (flag == 10)
		ft_printf("ERROR: wrong order rooms and links, (line %d)\n", p->i);
	else if (flag == 11)
		ft_printf("ERROR: too much spaces, (line %d)\n", p->i);
	else if (flag == 12 || flag == 13 || flag == 14)
		ft_display_error2(flag, p);
	exit(1);
}

void	ft_display_error2(int flag, t_p *p)
{
	if (flag == 12)
		ft_printf("ERROR: same name of rooms or coords, (line %d)\n", p->i);
	else if (flag == 13)
		ft_printf("ERROR: sorry bro or jen9, there are no ways!\n");
	else if (flag == 14)
		ft_printf("ERROR: empty file or papka\n");
	exit(1);
}

void	ft_error_arg(t_r *r, t_p *p)
{
	if (p->num_start != 1)
		ft_display_error(2, p);
	if (p->num_end != 1)
		ft_display_error(3, p);
	if (p->num_link < 1)
		ft_display_error(5, p);
	ft_check_coord(r, p);
}

void	ft_error_int(t_p *p, t_r *new_r)
{
	if (new_r->i > 2147483647 || new_r->j > 2147483647)
		ft_display_error(7, p);
	if (new_r->i < -2147483648 || new_r->j < -2147483648)
		ft_display_error(7, p);
}

int		ft_my_atoi_lem(const char *str, t_p *p)
{
	int						i;
	int						sign;
	unsigned long long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' && ++i)
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		ft_display_error(7, p);
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	if (sign == -1 && result > 2147483648)
		ft_display_error(7, p);
	else if (result > 2147483647)
		ft_display_error(7, p);
	return ((int)result * sign);
}
