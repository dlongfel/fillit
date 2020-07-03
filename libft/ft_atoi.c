/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:37:22 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:37:23 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v'
			|| *str == ' ' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		result = result * 10 + (*str - '0');
		if (result < 0 && sign == -1)
			return (0);
		else if (result < 0 && sign == 1)
			return (-1);
		str++;
	}
	return (result * sign);
}
