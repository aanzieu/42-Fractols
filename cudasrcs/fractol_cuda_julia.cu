/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_cuda_julia.cu                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:41:44 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/17 11:20:31 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cudainclude/cuda_call.h"

__global__ void julia_2(unsigned int* a_d, int constw, int consth, double xmin, double xmax, double ymin, double ymax, double zoom, float offx, float offy, float cr, float ci, float max, int power)
{
	int x = (blockIdx.x * blockDim.x) + threadIdx.x;
	int y = (blockIdx.y * blockDim.y) + threadIdx.y;
	int index = y * constw + x;
	if(y >= constw || x >= consth || index >= N) return;
	float zr = (((double)x / constw) * (xmax - xmin)) * zoom + xmin + offx;
	float zi = (((double)y / consth) * (ymax - ymin)) * zoom + ymin + offy;
	float tmpr;
	float tmpi;
	int		i = 0;
	
	while (zr * zr + zi * zi < 4  && i < max)
	{
		tmpr = zr * zr - zi * zi + cr;
		tmpi = zr * zi * power + ci;
		zr = tmpr;
		zi = tmpi;
		i++;
	}
	a_d[index] = i;
}
extern "C" void cuda_call_julia(unsigned int* a_h, unsigned int size, t_env *e, int end)
{
	unsigned int *a_d = NULL;
	static dim3 blockDim(16, 16);
	static dim3 gridDim(WIN_WIDTH / blockDim.x, WIN_HEIGTH / blockDim.y);
	
	e->view.xmin = -2;
	e->view.xmax = 2;
	e->view.ymin = -2;
	e->view.ymax = 2;
	cudaMalloc((void**) &a_d, size*sizeof(unsigned int));
	julia_2 <<< gridDim, blockDim >>> (a_d, WIN_WIDTH, WIN_HEIGTH, e->view.xmin, e->view.xmax, e->view.ymin, e->view.ymax, e->plan.zoom, e->plan.offx, e->plan.offy, e->plan.cr, e->plan.ci, e->plan.i_max, e->plan.power);
	cudaMemcpy(a_h, a_d, size*sizeof(unsigned int), cudaMemcpyDeviceToHost);
	cudaFree(a_d);
	if(end == 1)
		cudaDeviceReset();
}
