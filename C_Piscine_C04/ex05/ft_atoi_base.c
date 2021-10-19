/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:47:40 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/19 20:55:35 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (str[strlen])
		strlen++;
	return (strlen);
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

int	ft_nota_conv(char a, char *base)
{
	int	i;

	i = 0;
	while (base[i] && a != base[i])
		i++;
	if (i >= ft_strlen(base))
		return (-1);
	return (i);
}

int	ft_base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		base_length;
	int		operator;
	int		i;
	long	result;

	base_length = ft_strlen(base);
	operator = 1;
	result = 0;
	i = 0;
	if (ft_base_check(base))
	{
		operator = ft_skip(str, &i);
		while (ft_nota_conv(str[i], base) >= 0 && str[i])
		{
			result = result * base_length + ft_nota_conv(str[i], base);
			i++;
		}
		return (result * operator);
	}
	return (0);
}
