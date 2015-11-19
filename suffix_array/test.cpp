#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int N = 1e3 + 3;

int sa[N],rk[N],rk2[N],height[N],cnt[N],*x,*y;

/*
    * a radix_sort which is based on the y[].
    * how ? ahhhh, the last reverse for is the solution.
    * and the adjacant value of sa[] might have the same rk.
*/
void radix_sort(int n,int sz)
{
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)
        cnt[ x[ y[i] ] ]++;
    for(int i=1;i<sz;i++)
        cnt[i] += cnt[i-1];
    for(int i=n-1;i>=0;i--)
        sa[ --cnt[ x[ y[i] ] ] ] = y[i];
}

/*
    * sa[i] represents the ith suffix string is which one.
    * rk[i] represents the suffix string [i,n]'s rk.
    * sz is the max_rk of text in that time.
    * x[] represents the true pointer of rk[] in that time and it may be not unique.
    * y[] is the location of text[] which is sorted by 2nd key in that time before swap(x,y).
*/
void get_sa(char text[],int n,int sz=128)
{
    x = rk, y = rk2;
    for(int i=0;i<n;i++)
        x[i] = text[i], y[i] = i;
    radix_sort(n,sz);
    for(int len=1;len<n;len<<=1)
    {
        int yid = 0;
        for(int i=n-len;i<n;i++)
            y[yid++] = i;
        for(int i=0;i<n;i++)
            if(sa[i] >= len)
                y[yid++] = sa[i] - len;
        radix_sort(n,sz);
        swap(x,y);
        x[ sa[0] ] = yid = 0;
        for(int i=1;i<n;i++)
        {
            if(y[ sa[i-1] ]==y[ sa[i] ] && sa[i-1]+len<n && sa[i]+len<n && y[ sa[i-1]+len ]==y[ sa[i]+len ])
                x[ sa[i] ] = yid;
            else
                x[ sa[i] ] = ++yid;
        }
        sz = yid + 1;
        if(sz >= n)
            break;
    }
    for(int i=0;i<n;i++)
        rk[i] = x[i];
}

/*
    * height[] represents the longest common prefix of suffix [i-1,n] and [i,n].
    * height[ rk[i] ] >= height[ rk[i-1] ] - 1.
    ..... let's call [k,n] is the suffix which rk[k] = rk[i-1] - 1,
    ...=> [k+1,n] is a suffix which rk[k+1] < rk[i]
    ..... and the lcp of [k+1,n] and [i,n] is height[ rk[i] ] - 1.
    ..... still unknow ? height[ rk[i] ] is the max lcp of rk[k] and rk[i] which rk[k] < rk[i].
*/
void get_height(char text[],int n)
{
    int k = 0;
    for(int i=0;i<n;i++)
    {
        if(rk[i] == 0)
            continue;
        k = max(0,k-1);
        int j = sa[ rk[i]-1 ];
        while(i+k<n && j+k<n && text[i+k]==text[j+k])
            k++;
        height[ rk[i] ] = k;
    }
}

char str[N];

int main()
{
    //freopen("in.ads","r",stdin);
    //freopen("out.ads","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        int n = strlen(str);
        get_sa(str,n);
        get_height(str,n);
        int ans = 0;
        for(int i=0;i<n;i++)
            ans += n - sa[i] - height[i];
        printf("%d\n",ans);
    }
    return 0;
}
