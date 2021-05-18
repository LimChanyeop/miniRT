/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:45:36 by clim              #+#    #+#             */
/*   Updated: 2021/05/18 13:45:38 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	report_error(int err_num)
{
	if (err_num == 1)
		perror("vector input ERROR\n");
	else if (err_num == 2)
		perror("R,G,B input ERROR\n");
	else if (err_num == 3)
		perror("angle input ERROR\n");
	else if (err_num == 4)
		perror("light input ERROR\n");
	else if (err_num == 5)
		perror("Unallowed Negative Value ERROR\n");
	else if (err_num == 6)
		perror("not RT file (File must be formatted by '.rt')\n");
	else if (err_num == 7)
		perror("no necessary input in .rt file\n");
	else if (err_num == 8)
		perror(".rt file Line ERROR\n");
	else if (err_num == 9)
		perror("File dose not exist in ./scene");
	exit(err_num);
}
