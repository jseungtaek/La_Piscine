/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:09:15 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/14 23:21:15 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	recursive_f(int nb)
{
	if (nb <= 0)
		return ;
	recursive_f(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putnbr(int nb)
{
	int	a;

	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			a = 214748364;
			recursive_f(a);
			ft_putchar(8 + '0');
		}
		nb = nb * -1;
	}
	recursive_f(nb);
}
