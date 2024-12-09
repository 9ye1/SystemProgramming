//자료구조 과제 1 미로찾기 풀이 
#include <stdio.h>

int N; //총 문제 수 
int R, C; //Row, Column
int arr[100][100];
long long int memo[100][100];

int init(){
    for (int r=0; r<100; r++){
        for(int c=0; c<100; c++){
            arr[r][c]=-1;
            memo[r][c]=-1;
        }
    }
}

long long int solve(int r, int c){//path의 개수 반환
    if(memo[r][c]!=-1){
        return memo[r][c];
    }
    
    if(r==R-1 && c==C-1) {
        memo[r][c] = 1;
        return memo[r][c];
    }
    
    long long int ret = 0;
    
    if(c+1 < C-1 && arr[r][c+1]==1) ret += solve(r,c+1);
    if(r+1 < R-1 && arr[r+1][c]==1) ret += solve(r+1,c);
    
    memo[r][c] = ret;
    return memo[r][c]; 
}

int main(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);

    for(int n=0; n<N; n++){
        scanf("%d %d", &R, &C);
        init();
        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){
                scanf("%d", &arr[r][c]);
            }
        }
        printf("%lld",solve(0,0));
    }
    return 0;
}
