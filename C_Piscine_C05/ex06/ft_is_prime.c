/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:23:43 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/19 19:29:35 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_is_prime(int nb)
{
	int	i;
	int	cnt;

	i = 1;
	cnt = 0;
	if (nb == 0 || nb == 1)
		return (0);
	while (i <= nb)
	{
		if (nb % i == 0)
			cnt++;
		if (cnt > 2)
			return (0);
		i++;
	}
	return (1);
}
