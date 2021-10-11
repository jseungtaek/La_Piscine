/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:59:51 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/11 15:05:01 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putchar(char c);

void	ft_print_first_or_last_line(int x)
{
	int	x_length;

	x_length = 1;
	ft_putchar('o');
	while (x_length < x - 1)
	{
		ft_putchar('-');
		x_length++;
	}
	if (x != 1)
		ft_putchar('o');
	ft_putchar('\n');
}

void	ft_print_mid_lines(int x, int y)
{
	int	x_length;
	int	y_length;

	y_length = 1;
	while (y_length < y - 1)
	{
		ft_putchar('|');
		x_length = 1;
		while (x_length < x - 1)
		{
			ft_putchar(' ');
			x_length++;
		}
		if (x != 1)
			ft_putchar('|');
		ft_putchar('\n');
		y_length++;
	}
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		ft_print_first_or_last_line(x);
		ft_print_mid_lines(x, y);
		if (y > 1)
			ft_print_first_or_last_line(x);
	}
	else if (x == 0 && y > 0)
	{
		while (y > 0)
		{
			ft_putchar('\n');
			y--;
		}
	}
}
