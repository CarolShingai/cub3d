/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:57:02 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/20 21:04:12 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_vector	add_vector(t_vector v1, t_vector v2)
{
	t_vector	new_vector;

	new_vector.x = v1.x + v2.x;
	new_vector.y = v1.y + v2.y;
	return (new_vector);
}

t_vector	create_vector(float x, float y)
{
	t_vector	new_vector;

	new_vector.x = x;
	new_vector.y = y;
	return (new_vector);
}

t_vector	mult_vector(t_vector vector, double mult)
{
	t_vector	new_vector;

	new_vector.x = vector.x * mult;
	new_vector.y = vector.y * mult;
	return (new_vector);
}

t_vector	copy_vector(t_vector v)
{
	t_vector	new_vector;

	new_vector.x = v.x;
	new_vector.y = v.y;
	return (new_vector);
}

t_vector	rotate(t_vector v, double angle)
{
	t_vector	new_vector;

	new_vector.x = v.x * cos(angle) - v.y * sin(angle);
	new_vector.y = v.x * sin(angle) + v.y * cos(angle);
	return (new_vector);
}
