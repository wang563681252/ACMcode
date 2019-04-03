#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
struct NODE {
	int pos;
	int v;
}a[100005];

bool cmp(NODE q, NODE w)
{
	return q.pos < w.pos;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a[i].pos, &a[i].v);
	}
	sort(a + 1, a + 1 + n, cmp);
	int p = n;
	double MAX = 0;
	for(int i = n; i >= 1; i--)
	{
		if(a[i].v <= a[p].v) {
			p = i;
		}
		else {
			double t = a[i].v - a[p].v;
			double len = a[p].pos - a[i].pos;
			t = len / t;
			MAX = max(MAX, t);
		}
	}
	printf("%.6lf\n", MAX);
	return 0;
}
