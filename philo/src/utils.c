/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:24:43 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/09 18:56:26 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


static int	ft_count_spaces(const char *str, int i)
{
	while ((str[i] == '\t') || (str[i] == '\v') || (str[i] == '\f')
		|| (str[i] == '\r') || (str[i] == '\n') || (str[i] == ' '))
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int						i;
	int						is_negative;
	unsigned long long int	result;

	i = 0;
	is_negative = 1;
	result = 0;
	i = ft_count_spaces(str, i);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative = -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= 48) && (str[i] <= 57))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (result > LONG_MAX && is_negative == 1)
		return (-1);
	else if (result > LONG_MAX && is_negative == -1)
		return (0);
	else
		return (is_negative * (int)result);
}

long long int	ft_atoll(char *str)
{
	int				i;
	long long int	is_negative;
	long long int	result;

	i = 0;
	is_negative = 1;
	result = 0;
	i = ft_count_spaces(str, i);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative = -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= 48) && (str[i] <= 57))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (is_negative * result);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*copydest;
	char	*copysrc;

	i = 0;
	copydest = (char *)dest;
	copysrc = (char *)src;
	if ((!(dest) && !(src)) && (n > 0))
		return (NULL);
	while (i < n)
	{
		copydest[i] = copysrc[i];
		i++;
	}
	return (copydest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (!dest || !src)
		return (0);
	while (src[len] != '\0')
		++len;
	if (len + 1 < size)
		ft_memcpy(dest, (char *)src, len + 1);
	else if (size != 0)
	{
		ft_memcpy(dest, (char *)src, size - 1);
		dest[size - 1] = '\0';
	}
	return (len);
}