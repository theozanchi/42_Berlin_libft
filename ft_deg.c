/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:12:53 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/24 18:49:31 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_deg(float theta_rad)
{
	return (theta_rad / M_PI * 180);
}