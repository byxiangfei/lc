#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isValid(vector<vector<char>>& grid , int row, int col) {
	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0 ; j < grid[i].size() ; j++) {
			if(grid[i][j] == 'Q' && ( row == i  ||  col == j || abs(i-row) == abs(j-col))) return false;
		}
	}
	return true;
}


void nQueenHelper(vector<vector<char>>& grid, int col) {
	if(col == grid[0].size()) {
		print(grid);
		cout<<endl;
		return;
	}
	for(int row = 0; row < grid.size(); row++) {
		if(isValid(grid, row, col)) {
			grid[row][col] = 'Q';
			nQueenHelper(grid, col + 1);
			grid[row][col] = '.';
		}
	}
}
void print(vector<vector<char>>& grid) {
	for(auto row : grid) {
		for(auto col : row) {
			cout<<col<<" ";
		}
		cout<<endl;
	}
}

bool isValid(vector<vector<char>>& grid , int row, int col) {
	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0 ; j < grid[i].size() ; j++) {
			if(grid[i][j] == 'Q' && ( row == i  ||  col == j || abs(i-row) == abs(j-col))) return false;
		}
	}
	return true;
}


void nQueenHelper(vector<vector<char>>& grid, int col) {
	if(col == grid[0].size()) {
		print(grid);
		cout<<endl;
		return;
	}
	for(int row = 0; row < grid.size(); row++) {
		if(isValid(grid, row, col)) {
			grid[row][col] = 'Q';
			nQueenHelper(grid, col + 1);
			grid[row][col] = '.';
		}
	}
}

int main() {
	vector<vector<char>> grid(4, vector<char>(4, '.'));
	nQueenHelper(grid, 0);
}