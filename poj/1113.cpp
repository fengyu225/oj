#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

//reference http://www.bubuko.com/infodetail-318561.html

struct P
{
    int x,y;
    P() {}
    P(int x, int y) : x(x), y(y) {}
};

P points[1050];
int sz, l;
P st[1050];
P result[1050];

bool cmp(P l, P r){
    if(l.x<r.x) return true;
    else if(l.x>r.x) return false;
    return l.y<r.y;
}

double distance(int x1, int y1, int x2, int y2){
    return sqrt(double((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}

int dot_prod(P a, P b, P c){
    return (b.x-a.x)*(c.y-b.y) - (c.x-b.x)*(b.y-a.y);
}

void granham_convex(){
    //sort(points.begin(), points.begin()+sz, cmp());
    sort(points, points+sz, cmp);
    st[0]=points[0];
    st[1] = points[1];
    int s_curr = 1;
    for(int curr = 2; curr<sz; curr++){
        while(s_curr>0 && dot_prod(st[s_curr-1], st[s_curr], points[curr])<0) s_curr--;
        st[++s_curr] = points[curr];
    }
    int res_end = 0;
    for(; res_end<=s_curr; res_end++) result[res_end] = st[res_end];
    st[0]=points[sz-1];
    st[1] = points[sz-2];
    s_curr = 1;
    for(int curr=sz-3; curr>=0; curr--){
        while(s_curr>0 && dot_prod(st[s_curr-1], st[s_curr], points[curr])<0) s_curr--;
        st[++s_curr] = points[curr];
    }
    for(int i=0; i<=s_curr; i++) result[i+res_end] = st[i];
    res_end += s_curr+1;
    int xxx = 0;
    double output = 0.0;
    while(xxx+1<res_end){
        double temp = distance(result[xxx].x, result[xxx].y, result[xxx+1].x,result[xxx+1].y);
        output+=temp;
        xxx++;
    }
    output += 2*3.14159265358979323846*l;
    //printf("%.0lf\n", output); //WA!!!
    printf("%.0f\n", output);
}

int main(){
    scanf("%d %d", &sz, &l);
    int x, y;
    for(int i=0; i<sz; i++){
        scanf("%d %d", &x, &y);
        points[i].x = x;
        points[i].y =y;
    }
    granham_convex(); 
    return 0;
}