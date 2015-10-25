#include<stdlib.h>
#include<stdio.h>

using namespace std;

int count_bits(int x)  
{  
    x=(x & 0x55555555) + ((x >>1 ) & 0x55555555);  
    x=(x & 0x33333333) + ((x >>2 ) & 0x33333333);  
    x=(x & 0x0F0F0F0F) + ((x >>4 ) & 0x0F0F0F0F);  
    x=(x & 0x00FF00FF) + ((x >>8 ) & 0x00FF00FF);  
    x=(x & 0x0000FFFF) + ((x >>16) & 0x0000FFFF);  
    return x;  
} 

#define MAX 3000150

int l_child[MAX];
int r_child[MAX];
int l[MAX];
int r[MAX];
int color[MAX];

int construct_seg_tree(int l_bound, int r_bound, int& pos){
    if(r_bound<l_bound) return -1;
    l[pos]=l_bound;
    r[pos]=r_bound;
    color[pos]=1;
    int curr = pos;
    if(r_bound == l_bound){
        l_child[pos]=-1;
        r_child[pos]=-1;
        pos++;
    }
    else{
        int m = (l_bound+r_bound)>>1;
        pos++;
        l_child[curr] = construct_seg_tree(l_bound,m,pos);
        r_child[curr] = construct_seg_tree(m+1,r_bound,pos);
    }
    return curr;
}

int get_color(int curr, int a, int b){
    int c = color[curr];
    if(c>0 && (c & (c-1)) == 0)
        return c;
    int m = (l[curr]+r[curr])>>1;
    if(b<=m)
        return get_color(l_child[curr], a, b);
    else if(a>m)
        return get_color(r_child[curr], a, b);
    else{
        int res = get_color(l_child[curr], a, m) | get_color(r_child[curr], m+1, b);
        return res;
    }
}

void add_color(int curr, int a, int b, int c){
    int cl = 1<<(c-1);
    if(a == l[curr] && b == r[curr]){
        color[curr] = cl;
        return;
    }
    int temp = color[curr];
    if(temp>0 && (temp & (temp-1)) == 0){
        if(temp == cl) return;
        color[curr] = 0;
        color[l_child[curr]] = color[r_child[curr]] = temp;
    }
    int m = (l[curr]+r[curr])>>1;
    if(b<=m)
        add_color(l_child[curr], a, b, c);
    else if(a>m)
        add_color(r_child[curr], a, b, c);
    else{
        add_color(l_child[curr], a, m, c);
        add_color(r_child[curr], m+1, b, c);
    }
}

int main(){
    int L, T, O;
    while(scanf("%d %d %d\n", &L, &T, &O)!=EOF){
        int pos = 0;
        construct_seg_tree(1,L,pos);
        char op;
        for(int i=0; i<O; i++){
            scanf("%c", &op);
            if(op == 'C'){
                int a,b,c;
                scanf("%d %d %d\n", &a,&b,&c);
                add_color(0, a<=b?a:b, a<=b?b:a, c);
            }
            if(op == 'P'){
                int a,b;
                scanf("%d %d\n", &a,&b);
                int temp = count_bits(get_color(0, a<=b?a:b, a<=b?b:a));
                printf("%d\n", temp);
            }
        }
    }
    return 0;
}
