/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:08:51 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/11 21:15:45 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int num1_first;
	int num1_second;
	int num2_first;
	int num2_second;

	num1_first = 0;
	num1_second = 0;
	num2_first = 0;
	num2_second = 1;
	while (
