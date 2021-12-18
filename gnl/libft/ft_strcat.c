/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:19:22 by jdavis            #+#    #+#             */
/*   Updated: 2021/11/24 14:19:11 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char	*s1, const char	*s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		i = ft_strlen(s1);
		while (s2[j] != '\0')
		{
			s1[i + j] = s2[j];
			++j;
		}
		s1[i + j] = '\0';
	}
	return (s1);
}
