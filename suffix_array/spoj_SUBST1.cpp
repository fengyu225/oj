#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <limits.h>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <math.h>
#include <assert.h>

using namespace std;

#define max_len 50001

int suffix_arr[max_len], rk[max_len], height[max_len];
int working_a[max_len], working_b[max_len], cnt[max_len];
char str[max_len];

void build_suffix_arr(int s_len, int uniq_cnt){
    //suffix_arr[i] is the starting index of the suffix with order i
    int i, j, p=0;
    int *x=working_a, *y=working_b;
    for(i=0; i<s_len; i++) x[i]=str[i];
    for(i=0; i<uniq_cnt; i++) cnt[i]=0;
    for(i=0; i<s_len; i++) cnt[x[i]]++;
    for(i=1; i<uniq_cnt; i++) cnt[i] += cnt[i-1];
    for(i=s_len-1; i>=0; i--) suffix_arr[--cnt[x[i]]] = i;
    for(j=1; p<s_len; j*=2,uniq_cnt=p){
        p=0;
        for(i=s_len-j; i<s_len; i++){
            y[p++] = i;
        }
        for(i=0; i<s_len; i++) 
            if(suffix_arr[i]>=j)
                y[p++] = suffix_arr[i]-j;
        //y[i] is the index of first key when second key has order i
        for(i=0; i<uniq_cnt; i++) cnt[i] = 0;
        for(i=0; i<s_len; i++) cnt[x[y[i]]]++;
        for(i=1; i<uniq_cnt; i++) cnt[i] += cnt[i-1];
        for(i=s_len-1; i>=0; i--)
            suffix_arr[--cnt[x[y[i]]]] = y[i];
        int* temp = x;
        x = y;
        y = temp;
        //calculating rank which is array x in following
        x[suffix_arr[0]] = 0;
        i = p = 1;
        for(;i<s_len;i++){
            if(y[suffix_arr[i-1]] == y[suffix_arr[i]] && y[suffix_arr[i-1]+j] == y[suffix_arr[i]+j])
                x[suffix_arr[i]] = p-1;
            else{
                x[suffix_arr[i]] = p;
                p++;
            }
        }
    } 
}

void build_height(int s_len){
    //height[i] is length of longest common prefix of suffix suffix_arr[i] and suffix_arr[i-1]
    //height[rk[i]]>=height[rk[i-1]]-1
    int i, k=0;
    for(i=0; i<s_len; i++) rk[suffix_arr[i]] = i;
    for(i=0; i<s_len; i++){
        //k is height[rk[i-1]]
        if(rk[i] == 0) height[rk[i]] = k = 0;
        else{
            if(k) k--;
            else k=0;
            while(str[i+k] == str[suffix_arr[rk[i]-1]+k]) k++;
            height[rk[i]] = k;
        }
    }
}

int main(){
    int T;  
    long long res = 0;  
    scanf("%d",&T);  
    while(T--){  
        scanf("%s",str);  
        //use long long to handle string with 50000 length
        long long n = strlen(str);  
        build_suffix_arr(n+1, 256);  
        build_height(n+1);  
        res = n*(n+1)/2;
        for(long i=0;i<=n;i++)  
            res -= height[i];
        cout<<res<<endl;
    }  
    return 0;  
} 
