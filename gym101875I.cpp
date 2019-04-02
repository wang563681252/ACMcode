#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
int l[200005], r[200005];
vector<int>G[200005];
int ind[200005];
int all = 0;

void dfs(int x)
{
	l[x] = ++all;
	for(int i = 0; i < G[x].size(); i++)
	{
		dfs(G[x][i]);
	}
	r[x] = all;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		int u;
		scanf("%d", &u);
		if(u == -1) continue;
		G[u].push_back(i - 1);
		ind[i - 1]++;
	}
	for(int i = 1; i <= n; i++)
	{
		if(ind[i - 1] == 0) dfs(i - 1);
	}
	for(int i = 1; i <= k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if(l[x] >= l[y] && r[y] >= l[x]) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
