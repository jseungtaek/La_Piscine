/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:30:27 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/14 18:39:08 by sejeon           ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	dest_len;
	int	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (nb--)
	{
		dest[dest_len++] = src [i++];
		if (src[i] == '\0')
			dest[dest_len] = '\0';
	}
	dest[dest_len] = '\0';
	return (dest);
}
