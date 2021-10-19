/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:54:14 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/19 16:27:39 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (str[strlen])
		strlen++;
	return (strlen);
}

int	ft_check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(str) <= 1)
		return (0);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-'
			|| str[i] < 32 || str[i] > 126)
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_num;
	long	nbr_num;

	base_num = ft_strlen(base);
	nbr_num = nbr;
	if (ft_check_base(base))
	{
		if (nbr_num < 0)
		{
			ft_putchar('-');
			nbr_num *= -1;
		}
		if (nbr_num < base_num)
			ft_putchar(base[nbr_num]);
		else
		{
			ft_putnbr_base(nbr_num / base_num, base);
			ft_putnbr_base(nbr_num % base_num, base);
		}
	}
}
