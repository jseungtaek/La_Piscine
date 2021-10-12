/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:08:51 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/12 11:06:58 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_num(int num1, int num2)
{
	ft_putchar(num1 / 10 + '0');
	ft_putchar(num1 % 10 + '0');
	ft_putchar(' ');
	ft_putchar(num2 / 10 + '0');
	ft_putchar(num2 % 10 + '0');
	if (!(num1 == 98 && num2 == 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	num2 = 1;
	while (num1 < 99)
	{
		while (num2 < 100)
		{
			ft_print_num(num1, num2);
			num2++;
		}
		num1++;
		num2 = num1 + 1;
	}
}	
