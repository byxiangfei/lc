#include <string>
#include <iostream>

using namespace std;

string solveEquation(string equation) {
    int n = equation.size(), a = 0, b = 0, sign = 1, j = 0;
    for (int i = 0; i < n; ++i) {
        if (equation[i] == '+' || equation[i] == '-') {
            if (i > j) b += stoi(equation.substr(j, i - j)) * sign;
            j = i;  // +,- 也要带在 数字转换里
        } else if (equation[i] == 'x') {
            if (i ==  j || equation[i - 1] == '+') {
                a += sign;
            } else if (equation[i - 1] == '-') {
                a -= sign;
            } else {
                a += stoi(equation.substr(j, i - j)) * sign;
            }
            j = i + 1;
        } else if (equation[i] == '=') {
            if (i > j) b += stoi(equation.substr(j, i - j)) * sign;
            sign = -1;
            j = i + 1;
        }
    }
    if (j < n) b += stoi(equation.substr(j)) * sign;
    if (a == 0 && a == b) return "Infinite solutions";
    if (a == 0 && a != b) return "No solution";
    return "x=" + to_string(-b * 1.0 / a);
}

int main() {
    cout<<solveEquation("x+4-4x=0");

}
