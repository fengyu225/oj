/*
http://poj.org/problem?id=1033
 */

#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

int stack[10001];
int top = 0;
int count;
int mv_ct = 0;
int arr[10000];
bool in_stack[10001];


void solve(){
    for(int i=0; i<count; i++){
        if(arr[i] == i+1 || arr[i] == 0) continue;
        memset(in_stack,false,sizeof(bool)*(count+1));
        memset(stack,0,sizeof(int)*(count+1));
        top = 1;
        int to_idx = arr[i]-1;
        in_stack[i] = true;
        stack[top++] = i;
        while(arr[to_idx] && !in_stack[to_idx]){
            in_stack[to_idx] = true;
            stack[top++]=to_idx;
            to_idx = arr[to_idx]-1;
        }
        bool is_cycle = false;
        if(arr[to_idx]){
            is_cycle = true;
            int e_idx = count-1;
            while(arr[e_idx]) e_idx--;
            arr[e_idx] = arr[stack[top-1]];
            printf("%d %d\n", stack[top-1]+1, e_idx+1);
            mv_ct += 1;
            stack[0] = e_idx;
        };
        if(!is_cycle){
            arr[to_idx] = arr[stack[top-1]];
            arr[stack[top-1]] = 0;
            printf("%d %d\n", stack[top-1]+1, to_idx+1);
            mv_ct += 1;
        }
        int end;
        if(is_cycle) end=0;
        else end=1;
        int from=top-2,to=top-1;
        for(;from>=end;to=from,from--){
            arr[stack[to]] = arr[stack[from]];
            printf("%d %d\n", stack[from]+1, stack[to]+1);
            mv_ct += 1;
        }
        arr[stack[to]] = 0;
    }
}


int main(){
    int k,tc=1;
    memset(arr,0,sizeof(arr));
    scanf("%d %d", &count, &k);
    for(int i=0; i<k; i++){
        int c;
        scanf("%d", &c);
        for(int j=0; j<c; j++,tc++){
            int a;
            scanf("%d", &a);
            arr[a-1] = tc;
        }
    }
    solve();
    if(!mv_ct)
        printf("No optimization needed\n");
    return 0;
}
