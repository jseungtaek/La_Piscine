/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:08:29 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/19 20:17:20 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (nb < 0 || power < 0)
		return (0);
	return (nb * ft_recursive_power(nb, power - 1));
}
