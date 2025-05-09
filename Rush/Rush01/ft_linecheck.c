/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linecheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcalabri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 04:59:22 by rcalabri          #+#    #+#             */
/*   Updated: 2025/04/27 04:59:25 by rcalabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	top(int board[4][4], int x)
{
	int	result;

	result = 1;
	if (board[0][x] < board[1][x])
		result++;
	if (board[0][x] < board[2][x] && board[1][x] < board[2][x])
		result++;
	if (board[0][x] < board[3][x] &&
		board[1][x] < board[3][x] &&
		board[2][x] < board[3][x])
		result++;
	return (result);
}

int	bottom(int board[4][4], int x)
{
	int	result;

	result = 1;
	if (board[3][x] < board[2][x])
		result++;
	if (board[3][x] < board[1][x] && board[2][x] < board[1][x])
		result++;
	if (board[3][x] < board[0][x] &&
		board[2][x] < board[0][x] &&
		board[1][x] < board[0][x])
		result++;
	return (result);
}

int	left(int board[4][4], int y)
{
	int	result;

	result = 1;
	if (board[y][0] < board[y][1])
		result++;
	if (board[y][0] < board[y][2] && board[y][1] < board[y][2])
		result++;
	if (board[y][0] < board[y][3] &&
		board[y][1] < board[y][3] &&
		board[y][2] < board[y][3])
		result++;
	return (result);
}

int	right(int board[4][4], int y)
{
	int	result;

	result = 1;
	if (board[y][3] < board[y][2])
		result++;
	if (board[y][3] < board[y][1] && board[y][2] < board[y][1])
		result++;
	if (board[y][3] < board[y][0] &&
		board[y][2] < board[y][0] &&
		board[y][1] < board[y][0])
		result++;
	return (result);
}
