/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:50:11 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/12 17:27:50 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	a_cp;
	int	b_cp;

	a_cp = *a;
	b_cp = *b;
	*a = a_cp / b_cp;
	*b = a_cp % b_cp;
}
