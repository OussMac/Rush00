/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:39:21 by oukhanfa          #+#    #+#             */
/*   Updated: 2024/11/28 06:16:48 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	ft_size(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}

int	ft_trans(char *num_str)
{
	int	num;
	int	i;
	int	size;

	i = 0;
	num = 0;
	size = 0;
	while (num_str[size] != '\0')
	{
		size++;
	}
	while (i < size)
	{
		num = (num * 10) + num_str[i] - 48;
		i++;
	}
	return (num);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_istoobig(char *num)
{
	long int	i;
	long int	size;
	long int	divide;

	size = ft_size(num);
	i = 0;
	divide = 10000000000;
	if (size > 10)
	{
		return (1);
	}
	else if (size == 10)
	{
		while (num[i] != '\0')
		{
			if (num[i] - 48 > (2147483647 % divide) / (divide / 10))
			{
				return (1);
			}
			divide = divide / 10;
			i++;
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc != 3 || argv[1][0] == '-' || argv[2][0] == '-')
	{
		write(1, "please enter two strictly positive integers", 43);
		write(1, "\n", 1);
	}
	else if (!(ft_isnum(argv[1]) && ft_isnum(argv[2])))
	{
		write(1, "please type the number in a simple way", 38);
		write(1, "\n", 1);
	}
	else if (ft_istoobig(argv[2]) == 1 || ft_istoobig(argv[1]) == 1)
	{
		write(1, "please enter a number within the 4-bytes int range", 50);
		write(1, "\n", 1);
	}
	else
	{
		x = ft_trans(argv[1]);
		y = ft_trans(argv[2]);
		rush(x, y);
	}
	return (0);
}
