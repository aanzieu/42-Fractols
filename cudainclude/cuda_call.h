/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuda_call.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:47:02 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/23 14:34:32 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUDA_CALL_H
# define CUDA_CALL_H

#include "../include/fractol.h"

#ifdef __cplusplus

extern "C"

#endif

void cuda_call_mandelbrot(unsigned int* a_h, unsigned int size, t_env *e, int end);

#ifdef __cplusplus

extern "C"

#endif

void cuda_call_julia(unsigned int* a_h, unsigned int size, t_env *e, int end);

#endif
