/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:19:29 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/12 10:49:28 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_digit(int first, int second, int third)
{
	ft_putchar(first + '0');
	ft_putchar(second + '0');
	ft_putchar(third + '0');
	if (!(first == 7 && second ==8 && third ==9))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int	first;	
	int	second;	
	int	third;

	first = 0;
	second = 1;
	third = 2;
	while (first < second && first < 8)
	{
		while (second < third && second < 9)
		{
			while (third < 10)
			{
				ft_print_digit(first, second, third);
				third++;
			}
			second++;
			third = second + 1;
		}
		first++;
		second = first + 1;
		third = second + 1;
	}
}
