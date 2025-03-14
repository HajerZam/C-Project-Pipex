/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:18:06 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/14 12:40:36 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
void	ft_conversion(char c, va_list args, int *count);
void	ft_print_ptr(unsigned long ptr, int *count);
void	init_files(char *in_path, char *out_path, int *infile, int *outfile);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr_signed(int n, int *count);
void	ft_putnbr_unsigned(unsigned int n, int base, char *digits, int *count);

#endif