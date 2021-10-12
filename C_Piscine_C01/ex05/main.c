/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:32:06 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/12 17:47:26 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char *str);

int	main(void)
{
	char	*str;

	str = "arraasdasdasdasdasdasdasdy";
	ft_putstr(str);
	return (0);
}
