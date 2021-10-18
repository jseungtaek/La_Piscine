/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:40:02 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/18 16:45:59 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *s1)
{
	int	str_len;

	str_len = 0;
	while (s1[str_len])
		str_len++;
	return (str_len);
}

int	ft_whensame(char *s1, char *s2, int i, int j)
{
	int	flag;

	flag = -1;
	while (s2[j])
	{
		if (s1[i] != s2[j])
		{
			flag = -1;
			break ;
		}
		else if (s1[i] == s2[j])
			flag = 1;
		i++;
		j++;
	}
	if (flag == 1)
		return (i - j);
	else
		return (-1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == to_find[j])
			start = ft_whensame(str, to_find, i, j);
		i++;
	}
	if (start >= 0)
	{
		while (str[i])
			str[j++] = str[i++];
		str[j] = '\0';
		return (str);
	}
	else if (ft_strlen(to_find) == 0)
		return (str);
	else
		return (NULL);
}
