#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<vector>
#include<list>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<deque>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<limits.h>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<math.h>
#include<assert.h>

using namespace std;

int wsf[1000], sa[1000], rk[1000], wa[1000], wb[1000], wv[1000], height[1000];

int cmp(int *r, int a, int b, int k){
    return r[a] == r[b]&&r[a + k] == r[b + k];
}

void getsa(int *r, int *sa, int n, int m){
    int i, j, p, *x = wa, *y = wb, *t;  
    for(i = 0;i < m;i++) wsf[i] = 0;
    for(i = 0;i < n;i++) wsf[x[i] = r[i]]++;
    for(i = 1;i < m;i++) wsf[i] += wsf[i - 1];
    for(i = n - 1;i >= 0;i--) sa[--wsf[x[i]]] = i;
//      基基排序。（基数排序）
//
//      X[i]数组记录的是一开始的r[i]的值。 
//
//      Wsf[i]数组记录的是值为i和小于i的元素有几个。
//
//      最后一个循环则是记录排第几的数的位置。
    j = 1; p = 1;
    for(;p < n;j *= 2, m = p){
        for(p = 0, i = n - j;i < n;i++) y[p++] = i;
        for(i = 0;i < n;i++) if(sa[i] >= j) y[p++] = sa[i] - j;

//      Y[i]记录的是排名为i的第二要素的第一要素位置。
//      Sa[i]记录的是上一次排序的元素排名第i的元素的位置。
//      因为是二倍增排序，j就是第二要素据第一要素的距离，所以n-j第一元素的第二元素都为零，所以排名直接从零开始。
//      第二个for循环就是单纯的记录第二要素的排名。至于为什么sa[i]>=j是因为j前面的元素不肯能作为第二元素。
        for(i = 0;i < n;i++) wv[i] = x[y[i]];
        for(i = 0;i < m;i++) wsf[i] = 0;
        for(i = 0;i < n;i++) wsf[wv[i]]++;
        for(i = 1;i < m;i++) wsf[i] += wsf[i - 1];
        for(i = n - 1;i >= 0;i--) sa[--wsf[wv[i]]] = y[i];
//    与一开始一样 是基基排序。至于第一个for循环则是根据第二元素进行了排序然后赋值。因为最后一个for循环是从后往前的所以先扫到的排名低，所以要构成一个新的数列。
//
//    同样的 因为第一个for循环 所以最后一个for循环就是=y[i].因为y[i]表示的是第二元素排名第i位的第一元素的位置.而sa[i]数组记录的是排名第i位的原数组的位置。
        t = x;
        x = y;
        y = t;
        x[sa[0]] = 0;
        for(i = 1, p = 1;i < n;i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1: p++;
    }
}

//    数组交换.
//
//    因为一开始人为的加入了x[末尾+1] = 0;而0肯定是排在第0位的，所以x[sa[0]] = 0;只是再加一遍而已。这里p 的值表示的是不同关键值得数量。

void getheight(int *r, int n){
    int i, j, k = 0;
    for(i = 1; i <= n;i++) rk[sa[i]] = i;
//    求出rank数组，rank[i]的意思是位置为i的后缀的排名,与sa[i]数组正好互逆。
    for(i = 0; i < n;i++){
        if(k) k--;
        else k = 0;
        j = sa[rk[i] - 1];
        while(r[i + k] == r[j + k])
            k++;
        height[rk[i]] = k;
    }
}
 //     J是位置为i的后缀排名前一名的位置。如果这两个字符相等边加一。
int main(){
    cout<<"hello"<<endl;
    return 0;
}