#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <iostream>
#include <stack>
using namespace std;
void DFS_rec(int num, int* visits, int** matrix, int len)//обход графа в глубину
{
	visits[num] = 1;
	printf("%d ", num);
	for (int i = 0; i < len; i++) {
		if (matrix[num][i] == 1 && visits[i] == 0) {
			DFS_rec(i, visits, matrix, len);
		}
	}
}
void DFS(int num, int* visits, int** matrix, int len)
{
	stack <int> s;
	s.push(num);
	visits[num] = 1;
	while (!s.empty())
	{
		int num = s.top();
		s.pop();
		printf("%d ", num);
		for (int i = len; i >= 0; --i)
		{
			if (matrix[num][i] == 1 && visits[i] == 0)
			{
				s.push(i);
				visits[i] = 1;
			}
		}
	}
}
int main(void)
{
	setlocale(LC_ALL, "Rus");
	int** a;
	int N;
	int* mass;
	printf("Введите N: ");
	scanf("%d", &N);
	a = (int**)malloc(N * sizeof(int));
	mass = (int*)malloc(N * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		int* b = (int*)malloc(N * sizeof(int));
		for (int j = 0; j < N; j++) {
			b[j] = 0;
		}
		a[i] = b;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				int num = rand() % 2;
				a[i][j] = num;
				a[j][i] = num;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
	int len = N;
	int* visits = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		visits[i] = 0;
	}
	printf("Введите вершину: ");
	scanf("%d", &N);
	DFS(N, visits, a, len);

}

