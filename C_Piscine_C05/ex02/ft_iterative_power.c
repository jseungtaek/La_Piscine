/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:03:15 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/19 20:15:26 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = nb;
	if (nb < 0 || power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		nb *= result;
		power--;
	}
	return (nb);
}
