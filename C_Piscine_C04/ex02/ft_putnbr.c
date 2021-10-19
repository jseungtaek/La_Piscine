/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 01:00:17 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/19 13:50:45 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	recursive_func(int nb)
{
	if (nb <= 0)
		return ;
	recursive_func(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putnbr(int nb)
{
	int	num;

	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			num = 214748364;
			recursive_func(num);
			ft_putchar(8 + '0');
		}
		nb *= -1;
	}
	else if (nb == 0)
		ft_putchar('0');
	recursive_func(nb);
}
