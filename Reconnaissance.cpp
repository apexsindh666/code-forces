#include <stdio.h>
#include <algorithm>
using namespace std;

long long countWays(int a[], int n, int d)
{
    sort(a, a + n);

    long long ans = 0;
    int r = 0;

    for(int l = 0; l < n; l++)
    {
        while(r < n && a[r] - a[l] <= d)
            r++;

        ans += (r - l - 1);
    }

    return ans * 2; 
}

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);

    int a[1005];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("%lld\n", countWays(a, n, d));

    return 0;
}