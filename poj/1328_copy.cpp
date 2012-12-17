#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct region {
	float left;
	float right;
}array[1000] = {0};
int cmp(const void* l, const void* r) {
	struct region *L = (struct region*)l;
	struct region *R = (struct region*)r;
	return L->left<R->left || (L->left==R->left && L->right < R->right) ? -1 : 1;
}
int caseNum = 1;
int	main ()	{
	//memset(region, 0, sizeof(region));
	int n, d, cnt, i, flag;
	float x, y;
	while (scanf("%d%d", &n, &d) != EOF) {
		if (n == 0 && d == 0)
			break;
		i = 0;
		flag = 1;
		while (i != n) {
			scanf("%f%f", &x, &y);
			if (y > d) {
				flag = 0;
			}
			array[i].left = x - sqrt(d*d - y*y);
			array[i].right = x + sqrt(d*d - y*y);
			i++;
		}
		if (flag) {
			cnt = 1;
			qsort(array, n, sizeof(struct region), cmp);
			int index = 1;
			struct region tempRegion = array[0];
			while (index < n) {
				if (tempRegion.right < array[index].left) {
					tempRegion.left = array[index].left;
					tempRegion.right = array[index].right;
					cnt++;
				}
				else {
					tempRegion.left = max(tempRegion.left, array[index].left);
					tempRegion.right = min(tempRegion.right, array[index].right);
				}
				index++;
			}
		}
		else
			cnt = -1;
		printf("Case %d: %d\n", caseNum++, cnt);
	}
	return 0; 
}
