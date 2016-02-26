#include <iostream>
#include <vector>

using namespace std;

int MAX_NUM=100002;
vector<int> parent(MAX_NUM, -1);
vector<int> rk(MAX_NUM, 0);

int f(int x){
    if(parent[x] == -1) return x;
    parent[x] = f(parent[x]);
    return parent[x];
}

bool u(int x, int y){
    int p_x = f(x);
    int p_y = f(y);
    if(p_x == p_y && p_x != -1) return false;
    if(rk[p_x]<rk[p_y]) parent[p_x] = p_y;
    else{
        parent[p_y] = p_x;
        if(rk[p_x] == rk[p_y]) rk[p_x]++;
    }
    return true;
}

int main(){
    int a, b, res=0;
    while(cin>>a){
        if(a == -1){
            cout<<res<<endl;
            fill(parent.begin(), parent.end(), -1);
            fill(rk.begin(), rk.end(), 0);
            res = 0;
            continue;
        };
        cin>>b;
        if(!u(a,b)) res++; 
    }
    return 0;
}