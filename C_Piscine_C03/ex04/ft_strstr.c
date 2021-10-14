/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:40:02 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/14 19:49:08 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
int	ft_strverify(char *s1, char *s2)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (s1[i++])
	{
		if (s1[i] == s2[j])
		{
			while (s2[j])
			{
				if (s1[i++] == s2[j++])
					flag = 1;
				else if (s1[i++] != s2[j++])
					break ;
			}
			if (flag == 1)
				flag = i - j;
		}
	}
	return (flag);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = ft_strverify(str, to_find);
	j = 0;
	if (i > 0)
	{
		while (str[i])
		{
			str[j++] = str[i++];
		}
		str[j] = '\0';
	}
	return (str);
}	
