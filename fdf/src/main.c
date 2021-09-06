/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:28:49 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/23 10:46:47 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc < 2)
		fatal(NO_ARGUMENT);
	else
	{
		fdf_init(&fdf, argv[1]);
		make_hook(&fdf);
		mlx_loop(fdf.mlx);
	}
}
