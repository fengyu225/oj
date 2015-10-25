#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


char maze[41][41];
int n;
int w,h;
int l,r,s;

int left[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool move(int x, int y, int direction){
    l++;
    if(maze[h-1-y][x] == 'E'){
        return true;
    }
    int orig_l = l;
    bool r;
    int direction_d[4] = {1, 0, 3, 2};
    int direction_idx[4] = {0, 3, 2, 1};
    int next_x, next_y;
    for(int i=0; i<4; i++){
        l = orig_l;
        next_x = x+left[(direction+direction_idx[i])%4][0];
        next_y = y+left[(direction+direction_idx[i])%4][1];
        printf("maze[%d][%d]=%c, current: (%d,%d), direction: %d, next: (%d,%d), %d\n", h-1-y, x, maze[h-1-y][x], x, y, direction, next_x, next_y, i);
        if(next_x>=0 && next_x<w && next_y>=0 && next_y<h && (maze[h-1-next_y][next_x] == '.'|| maze[h-1-next_y][next_x] == 'E')){
            r=false;
            r=move(next_x, next_y, (direction+direction_d[i])%4);
            if(r)
                return true;
        }
    }
    return false;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &w, &h);
        int s_x, s_y, e_x, e_y;
        for(int j=0; j<h; j++){
            scanf("%s", maze[j]);
            for(int k=0; k<w; k++){
                if(maze[j][k] == 'S'){
                    s_x = k;
                    s_y = h-1-j;
                }
                if(maze[j][k] == 'E'){
                    e_x = k;
                    e_y = h-1-j;
                }
            }
        }
        printf("S: (%d,%d), E: (%d,%d)\n", s_x, s_y, e_x, e_y);
        l=0;
        int d;
        if(s_x==0)
            d=3;
        else if(s_x==w-1)
            d=1;
        else if(s_y==0)
            d=0;
        else
            d=2;
        move(s_x, s_y,d);
        printf("l is %d\n", l);
    }
    return 0;
}
