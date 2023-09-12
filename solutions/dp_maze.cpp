#include "headers\dp_maze.hpp"
#include <iostream>
#include <vector>

// Problem: Given and NxM grid, in how many ways can you go from the top-left
// to the bottom-right corner moving only down or right.

// Naive recursive approach
int maze_paths_naive(int N, int M){
    if(N == 1 || M == 1) // If we hit an edge there is only one way to solve it
        return 1;

    return maze_paths_naive(N-1, M) + maze_paths_naive(N, M-1);
}

unsigned long long int maze_paths_dp(int N, int M){
    std::vector<std::vector<unsigned long long int>> memo(N, std::vector<unsigned long long int>(M, 0));

    // give edges a value of 1
    for(auto i=0; i<N; i++)
        memo[i][0] = 1;
    for(auto j=0; j<M; j++)
        memo[0][j] = 1;

    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++){
    //         printf("%i | ", memo[i][j]);
    //     }
    //     printf("\n");
    // }

    // for each non-edge grid, add the adjacent grid values to itself
    for(auto i=1; i<N; i++){
        for(auto j=1; j<M; j++){
            memo[i][j] = memo[i-1][j] + memo[i][j-1];
        }
    }

    return memo[N-1][M-1];
}
