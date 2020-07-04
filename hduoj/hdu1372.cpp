#include<cstdio>
#include<queue>

using namespace std;

int BFS(int sx, int sy, int ex, int ey)
{
	if (sx==ex && sy==ey)
	{
		return 0;
	}
	sx -= 'a';
	ex -= 'a';
	sy -= '1';
	ey -= '1';
	queue<int> qx, qy, qs;
	qx.push(sx);
	qy.push(sy);
	qs.push(0);
	int move[8][8] = {{0}};
	while (!qx.empty())
	{
		int x = qx.front();qx.pop();
		int y = qy.front();qy.pop();
		int s = qs.front();qs.pop();//printf("%d %d %d\n", x, y, s);
		if (x==ex && y==ey)
		{
			return s;
		}
		if (x<0 || x>7 || y<0 || y>7 || move[x][y]!=0)
		{
			continue;
		}
		move[x][y]=s;
		qx.push(x+2);qy.push(y+1);qs.push(s+1);
		qx.push(x+1);qy.push(y+2);qs.push(s+1);
		qx.push(x-1);qy.push(y+2);qs.push(s+1);
		qx.push(x-2);qy.push(y+1);qs.push(s+1);
		qx.push(x-2);qy.push(y-1);qs.push(s+1);
		qx.push(x-1);qy.push(y-2);qs.push(s+1);
		qx.push(x+1);qy.push(y-2);qs.push(s+1);
		qx.push(x+2);qy.push(y-1);qs.push(s+1);
	}
	return -1;
}

int main(void)
{
	char be[5], en[5];
	while (scanf("%s%s", be, en)!=EOF)
	{
		printf("To get from %s to %s takes %d knight moves.\n", be, en,
		 BFS(be[0], be[1], en[0], en[1]));
	}

    return 0;
}
