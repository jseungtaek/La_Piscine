/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:42:11 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/17 18:36:14 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_isdigit(char *str, int i)
{
	if (str[i] >= 48 && str[i] <= 57)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	operator;
	int	num;

	i = 0;
	operator = 1;
	num = 0;
	while (*str != '\0' && !(ft_isdigit(str, i)))
	{
		if (str[i] == '-')
			operator *= -1;
		i++;
	}
	while (ft_isdigit(str, i))
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * operator);
}
