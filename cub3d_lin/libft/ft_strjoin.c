/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:03:05 by rbeach            #+#    #+#             */
/*   Updated: 2020/05/26 14:04:38 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if ((s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		i = 0;
		j = 0;
		while (s1[i])
		{
			s[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			s[i + j] = s2[j];
			j++;
		}
		s[i + j] = '\0';
	}
	return (s);
}
