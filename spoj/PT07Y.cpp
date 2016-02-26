#include <iostream>
#include <vector>

using namespace std;

vector<int> parent(10001, -1);
vector<int> rk(10001, 0);

int f(int x){
    if(parent[x] == -1) return x;
    parent[x] = f(parent[x]);
    return parent[x];
}

void u(int x, int y, int& res){
    int x_p = f(x);
    int y_p = f(y);
    if(x_p == y_p && x_p != -1) return;
    if(rk[x_p]<rk[y_p]) parent[x_p] = y_p;
    else{
        parent[y_p] = x_p;
        if(rk[x_p] == rk[y_p]) rk[x_p]++;
    }
    res--;
}

int main(){
    int v, e, res;
    cin>>v>>e;
    if(v!=e+1){
        cout<<"NO"<<endl;
        return 0;
    }
    res = v;
    for(int i=0; i<e; i++){
        int a, b;
        cin>>a>>b;
        u(a,b,res);
    }
    if(res == 1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
