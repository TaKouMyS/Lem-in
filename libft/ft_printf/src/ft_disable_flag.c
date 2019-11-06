/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disable_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:46:37 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/23 20:43:29 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_disable_flag2: disable flags after our ft_printf dealed with a % cases.
*/

static void			ft_disable_flag2(t_data *d)
{
	d->f &= ~F_BIG_L;
	d->f &= ~F_BIG_X;
	d->f &= ~F_AP_0;
	d->f &= ~F_X_0;
	d->f &= ~F_X;
	d->f &= ~F_O;
	d->f &= ~F_W_P_0;
}

/*
** ft_disable_flag: disable flags after our ft_printf dealed with a % cases.
*/

void				ft_disable_flag(t_data *d)
{
	d->f &= ~F_ZERO;
	d->f &= ~F_PLUS;
	d->f &= ~F_MINUS;
	d->f &= ~F_SHARP;
	d->f &= ~F_SPACE;
	d->f &= ~F_WIDTH;
	d->f &= ~F_PRECIS;
	d->f &= ~F_W_P;
	d->f &= ~B_DONE;
	d->f &= ~F_PLUS_MINUS;
	d->f &= ~F_H;
	d->f &= ~F_HH;
	d->f &= ~F_L;
	d->f &= ~F_LL;
	d->f &= ~AP_NEG;
	d->f &= ~F_UNSIGNED;
	d->f &= ~ONLY_CONV;
	d->f &= ~F_PERCENT;
	d->f &= ~F_S;
	d->f &= ~F_C_0;
	d->f &= ~F_S_0;
	d->f &= ~F0;
	d->f &= ~TMP_S_M;
	ft_disable_flag2(d);
}
