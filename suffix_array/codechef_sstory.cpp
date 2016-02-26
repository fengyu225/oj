/*
 * https://www.codechef.com/problems/SSTORY
 */

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

#define max_len 500003

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
    scanf("%s", str);
    int len_0 = strlen(str);
    str[len_0] = 'Z';
    scanf("%s", str+len_0+1);
    int t_len = strlen(str);
    str[t_len++] = 'A';
    int len_1 = t_len-len_0-2;
    cout<<str<<endl;
    build_suffix_arr(t_len, 256);
    build_height(t_len);
    string ss(str);
    for(int i=0; i<t_len; i++) cout<<ss.substr(suffix_arr[i])<<endl;
    cout<<endl;
    for(int i=0; i<t_len; i++) cout<<height[i]<<" ";
    cout<<endl;
    int s = -1, res = 0;
    int j;
    for(int i=len_0+1; i<t_len-1; i++){
        j = suffix_arr[rk[i]-1];
    //    cout<<i<<" "<<j<<endl;
        if(j>=len_0) continue;
        if(height[rk[i]]>res){
            res = height[rk[i]];
            s = i;
        }
    }    
    for(int i=0; i<len_0; i++){
        j = suffix_arr[rk[i]-1];
    //    cout<<i<<" "<<j<<endl;
        if(j<=len_0) continue;
        if(height[rk[i]]>res){
            res = height[rk[i]];
            s = i;
        }
    }

    if(res == 0) cout<<0<<endl;
    else{
        char temp[max_len];
        strncpy(temp, str+s, res);
        cout<<temp<<endl<<res<<endl;
    }
    return 0;  
} 
