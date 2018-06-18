// basic calculator
#include <string>
#include <iostream>
#include <stack>

using namespace std;

int calc(string str) {
	stack<int> s;
	int res = 0; 
	int flag = 1;
	for(int i = 0; i < str.size(); i++) {
		int num = 0;
		while(isdigit(str[i])) {
			num = num * 10 + (str[i] - '0');
			i++;
		}
		res += flag * num;
		switch(str[i]) {
			case '+': 
				flag = 1; 
				break;
			case '-': 
				flag = -1; 
				break;
			case '(':
				s.push(res); res = 0;
				s.push(flag); flag = 1;
				break;
			case ')':
				res *= s.top(); s.pop();
				res += s.top(); s.pop();
				break;
			default: break;
		} 
	}
	return res;
}

int main() {
	cout<<calc("12 + (2 - ( 3 - 4))")<<endl;
	return 0;


}