/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:19:39 by oukhanfa          #+#    #+#             */
/*   Updated: 2024/06/30 19:40:37 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush_sup(int x, int y, int c, int l);

void	rush(int x, int y)
{
	int	l;
	int	c;

	l = 1;
	while (l <= y)
	{
		if (x != 0)
		{
			c = 1;
			while (c <= x)
			{
				rush_sup(x, y, c, l);
				c++;
			}
			ft_putchar('\n');
			l++;
		}
		else
		{
			break ;
		}
	}
}

void	rush_sup(int x, int y, int c, int l)
{
	if ((l == 1 || l == y) && (c == 1 || c == x))
	{
		ft_putchar('o');
	}
	else if ((l == 1 || l == y) && (c != 1 && c != x))
	{
		ft_putchar('-');
	}
	else if ((l != 1 && l != y) && (c == 1 || c == x))
	{
		ft_putchar('|');
	}
	else
	{
		ft_putchar(' ');
	}
}
