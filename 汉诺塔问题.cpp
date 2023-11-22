#include<bits/stdc++.h>

using namespace std;

void move(char pos1, char pos2)
{
	printf(" %c->%c ", pos1, pos2);
}
//     n:盘子个数 pos1:起始位置 pos2:中转位置 pos3:最终位置
void Hanoi(int n, char pos1, char pos2, char pos3)
{
	//如果只有一个盘子，只需要将盘子从起始位置移动到目的位置上
	if (n == 1)
	{
		move(pos1, pos3);
	}
	//如果有n(n>=2)个盘子，则需要将n个盘子通过中转位置移动到目的位置上
	else
	{
		//将n-1个盘子通过中转位置移动到目的位置上
		Hanoi(n - 1, pos1, pos3, pos2);
		//将第n个移动到目的位置上
		move(pos1, pos3);
		//将n-1个盘子通过中转位置移动到目的位置上
		Hanoi(n - 1, pos2, pos1, pos3);
	}
}
int main()
{
	Hanoi(1, 'A', 'B', 'C');
	printf("\n");
	Hanoi(2, 'A', 'B', 'C');
	printf("\n");
	Hanoi(3, 'A', 'B', 'C');
	printf("\n");
	return 0;
}