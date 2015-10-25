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

/*
如果存在这么一条直线,使得所有线段都在该直线上投影,且投影部分有公共点,那么就等于存在该直线的垂线,该垂线与每一条线段都相交了. 且你可以通过先平移该垂线,然后再旋转该垂线,使得该”垂线”(旋转之后就不能叫垂线了)与之前所有的线段中至少正好相交于两个端点.
其实上面的结论是充分必要的: 线段投影有公共部分充要条件存在一条由所有线段中的两个端点确定的直线,该直线与每一条线段都相交(可能交于端点).
那么接下来我们只要枚举两两端点对,看该两端点构成的直线是否与每条直线都相交即可.
注意如果两个点的x与y坐标之差都<=1e-8,那么这两个点就应看成一个点.且精度值eps也应取1e-8.
*/

int n, num_lines;

int dcmp(double a, double b);

class Point{
    public:
        double x,y;
        Point():x(0.0),y(0.0){}
        Point(double x_val, double y_val):x(x_val),y(y_val){}
        bool operator== (Point& p){
            return dcmp(this->x, p.x) == 0 && dcmp(this->y, p.y) == 0;
        }
};

class Segment{
    public:
        Point* l, *r;
        Segment(Point* l, Point* r):l(l),r(r){}
        Segment():l(NULL),r(NULL){}
};

int dcmp(double a, double b){
    if(fabs(a-b)<=1e-8) return 0;
    return a<b?-1:1;
}

bool check(Point* a, Point* b, Point* c, Point* d){
    // return true if c is on right of a->b
    double l_c = (b->x - a->x)*(c->y - a->y) - (b->y - a->y)*(c->x - a->x);
    double r_c = (b->x - a->x)*(d->y - a->y) - (b->y - a->y)*(d->x - a->x);
    return dcmp(l_c, 0.0)*dcmp(r_c, 0.0)<=0;
}

Segment segments[110];
Point* points[220];

bool solve(){
    for(int i=0; i<2*num_lines; i++){
        for(int j=i; j<2*num_lines; j++){
            if(*points[i] == *points[j]) continue;
            int x = 0;
            for(;x<num_lines;x++){
                if(check(points[i], points[j], segments[x].l, segments[x].r)) continue;
                else break;
            }
            if(x == num_lines) return true;
        }
    } 
    return false;
}

int main(){
    scanf("%d\n", &n);
    for(int i=0; i<n; i++){
        scanf("%d\n", &num_lines);
        for(int j=0; j<num_lines; j++){
            Point* l = new Point();
            Point* r = new Point();
            scanf("%lf %lf %lf %lf\n", &l->x, &l->y, &r->x, &r->y);
            segments[j].l = l;
            segments[j].r = r;
            points[2*j] = l;
            points[2*j+1] = r;
        }
        if(solve()) cout<<"Yes!"<<endl;
        else cout<<"No!"<<endl;
    }
    return 0;
}