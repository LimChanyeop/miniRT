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
		printf("vector input ERROR\n");
	else if (err_num == 2)
		printf("R,G,B input ERROR\n");
	else if (err_num == 3)
		printf("angle input ERROR\n");
	else if (err_num == 4)
		printf("light input ERROR\n");
	else if (err_num == 5)
		printf("Unallowed Negative Or Zero Value ERROR\n");
	else if (err_num == 6)
		printf("file input format ERROR\n");
	else if (err_num == 7)
		printf("no necessary input in .rt file ERROR\n");
	else if (err_num == 8)
		printf(".rt file Line ERROR\n");
	else if (err_num == 9)
		printf("File dose not exist in ./scene ERROR\n");
	else if (err_num == 10)
		printf("Memory Allocation Failed ERROR\n");
	else if (err_num == 11)
		printf("bmp file make ERROR\n");
	exit(1);
}
