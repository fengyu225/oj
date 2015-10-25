#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<list>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<set>
#include<limits.h>
#include<algorithm>
#include<utility>
#include<iostream>
#include<math.h>
#include<assert.h>

using namespace std;

pair<int,int> partitions[5010];
pair<int,int> toys[5010];
int res[5010];
int num_partitions, num_toys;
int x_1, y_1, x_2, y_2;

bool on_right(int a1, int a2, int b1, int b2, int c1, int c2){
    //ab*bc is positive iff c is on right of ab, negative iff on left
    return (b1-a1)*(c2-b2) - (b2-a2)*(c1-b1) > 0;
}

void solve(){
    memset(res, 0, sizeof(res));
    sort(partitions,partitions+num_partitions);
    for(int i=0; i<num_toys; i++){
        int l = 0, r = num_partitions-1;
        while(l<r){
            int m = (l+r)/2;
            if(on_right(partitions[m].first, y_1, partitions[m].second, y_2, toys[i].first, toys[i].second)) l = m+1;
            else r=m;
        }
        if(on_right(partitions[l].first, y_1, partitions[l].second, y_2, toys[i].first, toys[i].second)) res[l+1]++;
        else res[l]++;
    }
    map<int,int> m;
    for(int i=0; i<=num_partitions; i++) m[res[i]]++;
    cout<<"Box"<<endl;
    for(map<int,int>::iterator iter = m.begin(); iter != m.end(); iter++)
        if(iter->first) cout<<iter->first<<": "<<iter->second<<endl;
}

int main(){
    while(scanf("%d %d %d %d %d %d\n", &num_partitions, &num_toys, &x_1, &y_1, &x_2, &y_2) > 1){
        for(int i=0; i<num_partitions; i++) cin>>partitions[i].first>>partitions[i].second;
        for(int i=0; i<num_toys; i++) cin>>toys[i].first>>toys[i].second;
        solve();
    }
    return 0;
}