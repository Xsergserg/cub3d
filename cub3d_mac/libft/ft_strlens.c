/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:13:50 by rbeach            #+#    #+#             */
/*   Updated: 2020/05/24 14:00:01 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlens(const char *str)
{
	int index;

	index = 0;
	if (str)
	{
		while (str[index])
			index++;
	}
	return (index);
}
