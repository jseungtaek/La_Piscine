/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:40:02 by sejeon            #+#    #+#             */
/*   Updated: 2021/10/18 14:47:07 by sejeon           ###   ########.fr       */
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

	flag = 0;
	while (s2[j])
	{
		if (s1[i] != s2[j])
		{
			flag = 0;
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
		return (0);
}

int	ft_strverify(char *s1, char *s2)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (s1[i])
	{
		if (s1[i] == s2[j])
			flag = ft_whensame(s1, s2, i, j);
		if (flag == 0)
			j = 0;
		i++;
	}
	return (flag);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*p;

	*p = "";
	i = ft_strverify(str, to_find);
	j = 0;
	if (i >= 0)
	{
		if (!(ft_strlen(to_find)))
			return (p);
		else
		{
			while (str[i])
				p[j++] = str[i++];
			p[j] = '\0';
			return (p);
		}
	}
	else
		return (p);
}
