/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:10:06 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/04 13:35:09 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*  select left pivot and right pivot in stack a within r elements 
 *  assign selected pivots in array pivot: pivot[0] = lp, pivot[1] = rp
 */
void    select_pivots(t_stack *a, int r, int pivot[])
{

}

void	intarr_sort(int arr[], int begin, int end)
{
	int	pivotidx;

	if (begin < end)
	{
		pivotidx = partition(arr, begin, end);
		intarr_sort(arr, begin, pivotidx);
		intarr_sort(arr, pivotidx + 1, end);
	}
}

int	partition(int arr[], int begin, int end)
{
	int	pivotidx;
	int	partidx;
	int	i;
	int	temp;

	pivotidx = end;
	partidx = begin - 1;
	i = begin;
	while (i < end)
	{
		if (arr[i] < arr[pivotidx])
		{
			temp = arr[i];
			arr[i] = arr[partidx];
			arr[partidx] = temp;
			partidx++;
		}
		i++;
	}
	temp = arr[partidx + 1];
	arr[partidx + 1] = arr[pivotidx];
	arr[pivotidx] = temp;
	return (partidx + 1);
}



def A_to_B(r)
	if r < 3
		적절히 정렬
		return
	스택A 원소 중에서 "적절한" 피봇을 2개 선택한다
	tmp = 스택A의 top # 연산할 대상
	for r개의 원소에 대해서
		if tmp >= 피봇[큰것]
			ra명령으로 뒤로 넘긴다
			ra호출횟수++
		else
			pb명령으로 b로 보낸다
			pb호출횟수++
			if tmp >= 피봇 [작은것]
				rb명령으로 뒤로 넘긴다
				rb호출횟수++
	for ra호출횟수, rb호출횟수
		rrr호출 #[3]과 [2]를 스택 앞으로 가져온다
	A_to_B(ra호출 횟수) #[3]
	B_to_A(rb호출 횟수) #[2]
	B_to_A(pb호출 횟수 - rb 호출 횟수) #[1]


def B_to_A(r)
	if r < 3
		적절히 정렬/pa로 보내기
		return
	스택B 원소 중에서 "적절한" 피봇을 2개 선택한다
	tmp = 스택B의 top # 연산할 대상
	for r개의 원소에 대해서
		if tmp < 피봇[작은것]
			rb명령으로 뒤로 넘긴다
			rb호출횟수++
		else
			pa명령으로 a로 보낸다
			pa호출횟수++
			if tmp < 피봇 [큰것]
				ra명령으로 뒤로 넘긴다
				ra호출횟수++
	A_to_B(pa호출횟수 - ra호출횟수) #[3]
	for ra호출횟수, rb호출횟수
		rrr호출 #[1]과 [2]를 스택 앞으로 가져온다
	A_to_B(ra호출횟수) #[2]
	B_to_A(rb호출횟수) #[1]