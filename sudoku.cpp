#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <cmath>
 
using namespace std;

#define N 9

bool unass(int grid[N][N], int row, int col) {
    for(row = 0; row < N; row++) {
        for(col = 0; col < N; col++) {
            if(grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool poderow(int grid[N][N], int row, int num) {
    for(int col = 0; col < N; col++) {
        if(grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool podecol(int grid[N][N], int col, int num) {
    for(int row = 0; row < N; row++) {
        if(grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool podebox(int grid[N][N], int boxsrow, int boxscol, int num) {
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            if(grid[row + boxsrow][col + boxscol] == num) {
                return true;
            }
        }
    }
    return false;
}

bool pode(int grid[N][N], int row, int col, int num) {
    return !poderow(grid, row, num) && !podecol(grid, col, num) && !podebox(grid, row - row%3, col - col%3, num) && grid[row][col] == 0;
}

bool solve(int grid[N][N]) {
    int row, col;
    if(!unass(grid,row,col)) {
        return true;
    }
    for(int num = 1; num <= 9; num++) {
        if(pode(grid,row,col,num)) {
            grid[row][col] = num;
            if(solve(grid)) {
                return true;
            } else {
                grid[row][col] = 0;
            }
        }
    }
    return false;
}

void printar(int grid[N][N]) {
    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {
            printf("%d ",grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int n,i,j,k;
    int grid[9][9];
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        for(j=0;j<9;j++) {
            for(k=0;k<9;k++) {
                scanf("%d",&grid[j][k]);
            }
        }
        if(solve(grid) == true) {
            printar(grid);
        } else {
            printf("No solution\n");
        }
    }
    return 0;
}