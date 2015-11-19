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

void print_arr(int* arr, int sz){
    for(int i=0; i<sz; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void getsa(int *r, int *sa, int n, int m){
    int i, j, p, *x = wa, *y = wb, *t;  
    for(i = 0;i < m;i++) wsf[i] = 0;
    for(i = 0;i < n;i++) wsf[x[i]=r[i]]++;
    for(i = 1;i < m;i++) wsf[i] += wsf[i - 1];
    for(i = n - 1;i >= 0;i--) sa[--wsf[x[i]]] = i;
    j = 1; p = 1;
    for(;p < n;j *= 2, m = p){
        cout<<"m:"<<m<<endl;
        cout<<"sa:"<<endl;
        print_arr(sa, n);
        for(p = 0, i = n - j;i < n;i++) y[p++] = i;
        for(i = 0;i < n;i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        cout<<"y:"<<endl;
        print_arr(y, n);
        cout<<"x:"<<endl;
        print_arr(x, n);
        cout<<"p="<<p<<endl;
        for(i = 0;i < n;i++) wv[i] = x[y[i]];
        for(i = 0;i < m;i++) wsf[i] = 0;
        for(i = 0;i < n;i++) wsf[wv[i]]++;
        for(i = 1;i < m;i++) wsf[i] += wsf[i - 1];
        for(i = n - 1;i >= 0;i--) sa[--wsf[wv[i]]] = y[i];
        cout<<"sa:"<<endl;
        print_arr(sa, n);
        cout<<"wsf:"<<endl;
        print_arr(wsf, m);
        t = x;
        x = y;
        y = t;
        x[sa[0]] = 0;
        for(i = 1, p = 1;i < n;i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1: p++;
        cout<<endl;
    }
}
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
    //int s[] = {'m', 'i', 's', 's', 'i', 's', 's', 'i', 'p', 'p', 'i', 0};
    int s[] = {'a', 'b', 'a', 'b', 'c'};
    int n = sizeof(s)/sizeof(s[0]);
    getsa(s, sa, n, 256);
    for(int i=0; i<n; i++) cout<<sa[i]<<" ";
    cout<<endl;
    return 0;
}