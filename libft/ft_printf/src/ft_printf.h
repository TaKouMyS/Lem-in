/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:57:52 by amamy             #+#    #+#             */
/*   Updated: 2019/04/24 17:23:03 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>

/*
** define examples:
** F_W_P : flag width + precision
** B_DONE : in ft_analyse, when it's the end of format, nothing more to read
** F_PLUS_MINUS : When +- are on
** AP_NEG : when the variadic argument is negative.
** F_UNSIGNED : when it's a u,o, x, X conversion.
** ONLY_CONV : when there are no flags to deals with.
** F_PERCENT : %43% cases.
** F_S : when it's a %s converion.
** F_C_0 / F_AP_0 : when the variadic argument is 0.
*/

/*
** Defines for specifics conversions.
*/

# define F_S 524288
# define F_PERCENT 262144

/*
** Defines for flags.
*/

# define F_ZERO 1
# define F_PLUS 2
# define F_MINUS 4
# define F_SHARP 8
# define F_SPACE 16
# define F_PLUS_MINUS 1024
# define F_WIDTH 32
# define F_PRECIS 64
# define F_W_P 256
# define F_H 2048
# define F_HH 4096
# define F_L 8192
# define F_LL 16384
# define F_BIG_L 16777216
# define F_BIG_X 33554432
# define F_X 268435456

/*
** Defines for when specifics values worth 0;.
*/

# define F_C_0 1048576
# define F_C_02 128
# define F_S_0 2097152
# define F_AP_0 67108864
# define F_X_0 134217728
# define F_W_P_0 1073741824
# define F_O 536870912

/*
** Various defines.
*/

# define B_DONE 512
# define TMP_S_M 8388608
# define F_UNSIGNED 65536
# define AP_NEG 32768
# define ONLY_CONV 131072
# define F0 4194304

typedef	struct	s_data
{
	va_list		ap;
	int			done;
	int			flag_sz;
	int			ap_sz;
	char		*buf;
	int			conv_sz;
	int			conv_t_sz;
	int			f;
	int			tmp;
	int			*index_0;
	int			width_precis_minus;
	char		*tmp_s;
}				t_data;

typedef	struct	s_float
{
	int			width;
	long double ap;
	long long	deci_p;
	char		*int_p;
	char		*s_deci_p;
	char		*str_deci_ar_cp;
}				t_float;

int				ft_printf(const char *str, ...);
char			*ft_got_flag(char *str, t_data *data);
int				ft_active_flag(int i, char *f, t_data *data);
char			*ft_analyse(char *str, t_data *data);
char			*ft_next_p100(char *str, t_data *data);
void			ft_disable_flag(t_data *data);
char			*ft_flag_conv(char *f, char *ret_conv, int i, t_data *d);
char			*ft_special_cases(int i, char *f, t_data *d);
char			*ft_fwp_minus(char *final, t_data *data);
char			*ft_for_minus(char *ret_conv, char *flag, int i, t_data *data);
char			*ft_only_conv(char *flags, t_data *data);
char			*ft_which_flag(char *flag, char conv, t_data *data);
char			*ft_search_forbidden_conv(char *str);

char			*ft_precision_d(char *flags, t_data *data);
int				ft_precision_s(char *flags, t_data *data);
int				ft_float_w_a(t_data *d, t_float *ft, char *flag);
char			*ft_float_w_a_width(char *final, t_float *ft, t_data *d);
int				ft_float_width(t_data *d, t_float *ft, char *f, long double r);

char			*ft_flag_minus(int int_p, int after, char *final, t_data *d);
char			*ft_s(char *final, int before, int after, t_data *data);
char			*ft_preci_width(char *flag, t_data *data);
char			*ft_case1(char *final, int i, int after, t_data *data);
char			*ft_case2(char *final, int int_p, int after, t_data *data);
char			*ft_case3(char *final, int int_p, int after, t_data *data);
char			*ft_not_ap_neg(int before, int after, char *final, t_data *d);
char			*ft_conv_hhhlll_u(t_data *data, int base, int mode);
char			*ft_conv_hhhlll(t_data *data);
char			*ft_plus(char *flag, t_data *data);
char			*ft_minus(char *flag, t_data *data);
char			*ft_sharp(int i, char *f, char *ret_flag, t_data *data);
char			*ft_ret_flag_sharp(char *ret_flag, char *f, int i);
char			*ft_width_minus(char *flag, t_data *data);
char			*ft_width_s(char *flags, t_data *data);
char			*ft_s_width(char *flag, char *ap, t_data *data);
char			*ft_width(char *flags, t_data *data);
char			*ft_width2(int width, t_data *data);

char			*ft_conv_f(t_data *data, char *flag);
char			*ft_conv_f2_2(t_float *ft, t_data *d, char *flag, int mode);
int				ft_accuracy_size(char *flags, t_data *data);
char			*ft_float_accuracy(t_data *d, char *flag, t_float *ft);
char			*ft_ffinal(t_float *ft, t_data *data, char *flag, int j);
void			ft_free(t_float *ft, int j, int m);
char			*ft_missing_zeros(int len, t_float *ft);

char			*ft_char(t_data *data);
char			*ft_conv_di(t_data *data);
char			*ft_octal(t_data *data);
char			*ft_conv_p(t_data *data);
char			*ft_string(char *flag, t_data *data, int mode);
char			*ft_string_mode1(char *flag, t_data *data);
char			*ft_conv_u(t_data *data);
char			*ft_hexa(t_data *data, int mode);

char			*ibmul(unsigned long long v, unsigned int b, int m, t_data *d);
char			*itoa_base_m(unsigned int v, unsigned int b, int m, t_data *d);
char			*itoa_b_m_ui(unsigned int v, unsigned int b, int m, t_data *d);
char			*ft_free_then_return(char *ap);

#endif
