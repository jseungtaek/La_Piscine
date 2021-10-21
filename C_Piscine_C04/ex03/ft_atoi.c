/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:42:11 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/22 01:54:15 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_isdigit(char *str, int i)
{
	if (str[i] >= 48 && str[i] <= 57)
		return (1);
	return (0);
}

int	ft_skip(char *str, int *start)
{
	int	i;

	i = 1;
	while ((str[*start] >= 9 && str[*start] <= 13) || str[*start] == ' ')
		*start += 1;
	while (str[*start] == '+' || str[*start] == '-')
	{
		if (str[*start] == '-')
			i *= -1;
		*start += 1;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	operator;
	int	num;

	i = 0;
	operator = 1;
	num = 0;
	operator = ft_skip(str, &i);
	while (ft_isdigit(str, i))
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * operator);
}
