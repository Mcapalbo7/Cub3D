/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:12:27 by mla-mona          #+#    #+#             */
/*   Updated: 2024/07/31 19:07:38 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_rgb(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

int	check_comma(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == ',')
			count++;
		str++;
	}
	return (count);
}

void	parse_rgb(char *str, t_color *rgb)
{
	char	**mat;

	if (check_comma(str) != 2)
	{
		reset_color(rgb);
		return ;
	}
	while (!ft_isdigit(*str))
		str++;
	mat = ft_split(str, ',');
	if (rgb->red == -1 || rgb->green == -1 || rgb->blue == -1)
	{
		rgb->red = ft_atoi(mat[0]);
		rgb->green = ft_atoi(mat[1]);
		rgb->blue = ft_atoi(mat[2]);
	}
	else
		reset_color(rgb);
	free_rgb(mat);
}

int	convert_color_to_int(t_color rgb)
{
	int	color;

	color = rgb.red;
	color = (color << 8) + rgb.green;
	color = (color << 8) + rgb.blue;
	return (color);
}
