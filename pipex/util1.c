/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 08:41:01 by aikram            #+#    #+#             */
/*   Updated: 2023/01/10 08:46:33 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*str;

	i = 0;
	str = malloc(count * size);
	if (!str)
		return (0);
	while (i < (count * size))
		((char *)str)[i++] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i[2];

	i[0] = 0;
	i[1] = -1;
	if (!s1 || !s2)
		return (0);
	s = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(*s));
	if (!s)
		return (0);
	while (s1[++i[1]])
		s[i[1]] = s1[i[1]];
	while (s2[i[0]])
		s[i[1]++] = s2[i[0]++];
	return (s);
}

void	ft_spit(char *s, char c, char **strr, int *i)
{
	while (++i[2] < i[1])
	{
		i[4] = 0;
		i[5] = -1;
		while (s[++i[3]] == c && s[i[3]])
			;
		while (s[i[3]] != c && s[i[3]])
		{
			i[4]++;
			i[3]++;
		}
		strr[i[2]] = (char *)malloc(sizeof(*strr[i[2]]) * (i[4] + 1));
		i[3] -= i[4];
		while (s[i[3]] != c && s[i[3]])
		{
			strr[i[2]][++i[5]] = s[i[3]];
			i[3]++;
		}
		strr[i[2]][++i[5]] = '\0';
	}
	strr[i[2]] = 0;
}

char	**ft_split(char *s, char c)
{
	char	**strr;
	int		i[6];
	int		j;

	if (!s)
		return (0);
	j = -1;
	while (++j < 6)
		i[j] = -1;
	i[1] = 0;
	while (s[++i[0]])
	{
		if (i[0] == 0 && s[i[0]] != c && s[i[0]])
			i[1]++;
		if (s[i[0]] == c && s[i[0] + 1] != c && s[i[0] + 1])
			i[1]++;
	}
	strr = (char **)malloc(sizeof(*strr) * (i[1] + 1));
	if (!strr)
		return (0);
	ft_spit(s, c, strr, i);
	return (strr);
}
