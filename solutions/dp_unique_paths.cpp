#include "headers\dp_unique_paths.hpp"
#include <iostream>
#include <vector>


// Leetcode 63: Unique Paths (https://leetcode.com/problems/unique-paths/)
// Given the two integers m and n, return the number of possible unique paths that the robot can take 
// to reach the bottom-right corner, moving only right and down.
// Useful Constraints:
//      1 <= m, n <= 100


// This question is the same as to ask how many ways there are to arrange m D's and n R's.
// can be solved using the equation (m+n-2)!/(m-1)!(n-1)!, HOWEVER this is not easy to compute.
// Given the restrict {m,n<=100}, we would have to be able to compute 99!*99! which far exceeds even usinged long long
// Instead we opt for a dp solution.

// Subproblem:
//  M(m,n) = M(m-1,n) + M(m,n-1)
// Base case:
//  Anytime we hit the right side or bottom there is only 1 possible solution
    
int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0)); // Initialize with zeros

    for(int i=0; i<n; i++)
        matrix[m-1][i] = 1;
    for(int i=0; i<m; i++)
        matrix[i][n-1] = 1;

    for(int i=m-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            matrix[i][j] = matrix[i+1][j] + matrix[i][j+1];
        }
    }

    return matrix[0][0];
}

// From Leetcode Discuccion:
//   The space effeciency of the solution above can be improved
//   Note that we only ever need to consider 2 rows at a time, hence there is not need to store the whole matrix
//   Infact you can even reduce it to just a single row (Think about it)