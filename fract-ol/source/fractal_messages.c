/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_messages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:37:46 by scornhol          #+#    #+#             */
/*   Updated: 2022/02/18 22:38:13 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	put_perror(const char *message, int err_code)
{
	if (err_code)
		perror(message);
	else
		ft_putendl_fd((char *)message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	put_help_message(void)
{
	ft_putendl_fd("\033[30;42m| RULES FOR GETTING STARTED\t\t\t\t|\033[0m", 1);
	ft_putendl_fd("\033[32m| Run the program as follows:\t\t\t\t|", 1);
	ft_putendl_fd("|   ./fractol [name] [num] [num]\t\t\t|", 1);
	ft_putendl_fd("| [name] - required argument,\t\t\t\t|", 1);
	ft_putendl_fd("|\ttaking strictly the following values:\t\t|", 1);
	ft_putendl_fd("|\t- mandelbrot\t\t\t\t\t|", 1);
	ft_putendl_fd("|\t- julia\t\t\t\t\t\t|", 1);
	ft_putendl_fd("|\t- burning_ship\t\t\t\t\t|", 1);
	ft_putendl_fd("|\t- celtic_mandelbrot\t\t\t\t|", 1);
	ft_putendl_fd("| [num] [num] - additional arguments,\t\t\t|", 1);
	ft_putendl_fd("|\treal numbers used in the pair for julia set\t|", 1);
	ft_putendl_fd("| sample usage:\t\t\t\t\t\t|", 1);
	ft_putendl_fd("|  ./fractol mandelbrot\t\t\t\t\t|", 1);
	ft_putendl_fd("|  ./fractol julia 0.15 -0.725\t\t\t\t|\033[0m", 1);
	ft_putendl_fd("\033[30;42m|\t\t\t\t\t\t\t|\033[0m", 1);
}

void	put_use_message(void)
{
	ft_putendl_fd("\033[30;46m|  RULES FOR USE\t\t\t\t|\033[0m", 1);
	ft_putendl_fd("\033[36m|   Movements:\t\t[^] [<] [v] [>] \t|", 1);
	ft_putendl_fd("|   Zoom:\t\tmouse wheel\t\t|", 1);
	ft_putendl_fd("|   Iterations:\t\t[+] [-]\t\t\t|", 1);
	ft_putendl_fd("|   Color:\t\t[C]\t\t\t|", 1);
	ft_putendl_fd("|   Set default values:\t[R]\t\t\t|", 1);
	ft_putendl_fd("|   Exit: \t\t[esc]\t\t\t|\033[0m", 1);
	ft_putendl_fd("\033[30;46m|\t\t\t\t\t\t|\033[0m", 1);
}
