/*
// https://leetcode.com/discuss/interview-question/476340/google-onsite-hard-problem
Given a matrix of direction with L, R, U, D,
at any point you can move to the direction which is written over the cell [i, j].
We have to tell minimum number of modifications to reach from [0, 0] to [N - 1, M - 1] .

Example :-
R R D
L L L
U U R
Answer is 1, we can modify cell [1, 2] from L To D.
*/

// 路径有可能走不到，要修改具体的某个值才行。
// 这种题目第一感觉还是典型的回溯方法。
