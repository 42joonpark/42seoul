/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:10:45 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/23 13:01:53 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define NO_ARGUMENT "Usage: ./fdf <file_name> \n"

# define MLX_INIT_ERROR "mlx_init() Error \n"
# define MLX_NEW_WINDOW_ERROR "mlx_new_window() Error \n"
# define MAP_INIT_ERROR "map_init() Error \n"
# define CAMERA_INIT_ERROR "camera_init() error \n"

# define MAP_OPEN_ERROR "file open() Error \n"
# define READ_MAP_ERROR "map.c/read_map() Error \n"
# define FILE_READ_ERROR "map.c/file_read() Error \n"
# define NEW_COORD_ERROR "map.c/get_new_coord() Error \n"
# define WRONG_LENGTH "Found wrong line length. Exiting \n"
# define MAP_CREAT_ERROR "src/init.c reading map encountered error \n"

#endif
