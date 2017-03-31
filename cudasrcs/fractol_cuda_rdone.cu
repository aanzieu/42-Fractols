/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_cuda_rdone.cu                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:41:44 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/17 11:20:31 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cudainclude/cuda_call.h"

__global__ void rdone_2(unsigned int* a_d, int constw, int consth, double xmin, double xmax, double ymin, double ymax, double zoom, float offx, float offy, float cr, float ci, float max, int power)
{
	int x = (blockIdx.x * blockDim.x) + threadIdx.x;
	int y = (blockIdx.y * blockDim.y) + threadIdx.y;
	int index = y * constw + x;
	if(y >= constw || x >= consth || index >= N) return;
	x = (((double)x / constw) * (xmax - xmin)) * zoom + xmin + offx;
	y = (((double)y / consth) * (ymax - ymin)) * zoom + ymin + offy;
	x = abs(x);
	y = abs(y);
	int i = 0;
	while ((x >0 || y > 0) && i < max)
	{
		if (x % 3 == 1 && y % 3 == 1)
		{
			a_d[index] = 0;
			return;
		}
		x /= 3;
		y /= 3;
		i++;
	}
	a_d[index] = i;
}
extern "C" void cuda_call_rdone(unsigned int* a_h, unsigned int size, t_env *e, int end)
{
	unsigned int *a_d = NULL;
	static dim3 blockDim(16, 16);
	static dim3 gridDim(WIN_WIDTH / blockDim.x, WIN_HEIGTH / blockDim.y);

	e->view.xmin = -2.0f;
	e->view.xmax = 2.0f;
	e->view.ymin = -2.0f;
	e->view.ymax = 2.0f;
	cudaMalloc((void**) &a_d, size*sizeof(unsigned int));
	rdone_2 <<< gridDim, blockDim >>> (a_d, WIN_WIDTH, WIN_HEIGTH, e->view.xmin, e->view.xmax, e->view.ymin, e->view.ymax, e->plan.zoom, e->plan.offx, e->plan.offy, e->plan.cr, e->plan.ci, e->plan.i_max, e->plan.power);
	cudaMemcpy(a_h, a_d, size*sizeof(unsigned int), cudaMemcpyDeviceToHost);
	cudaFree(a_d);
	if(end == 1)
		cudaDeviceReset();
}
