/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichoi <ichoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:55:42 by ichoi             #+#    #+#             */
/*   Updated: 2021/10/10 15:54:28 by ichoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putchar(char c);

void	ft_print_first_line(int x)
{
	int	x_length;

	x_length = 1;
	ft_putchar('/');
	while (x_length < x - 1)
	{
		ft_putchar('*');
		x_length++;
	}
	if (x != 1)
		ft_putchar('\\');
	ft_putchar('\n');
}

void	ft_print_mid_lines(int x, int y)
{
	int	x_length;
	int	y_length;

	y_length = 1;
	while (y_length < y - 1)
	{
		ft_putchar('*');
		x_length = 1;
		while (x_length < x - 1)
		{
			ft_putchar(' ');
			x_length++;
		}
		if (x != 1)
			ft_putchar('*');
		ft_putchar('\n');
		y_length++;
	}
}

void	ft_print_last_line(int x, int y)
{
	int	x_length;

	x_length = 1;
	if (y > 1)
	{
		ft_putchar('\\');
		while (x_length < x - 1)
		{
			ft_putchar('*');
			x_length++;
		}
		if (x != 1)
			ft_putchar('/');
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		ft_print_first_line(x);
		ft_print_mid_lines(x, y);
		ft_print_last_line(x, y);
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
