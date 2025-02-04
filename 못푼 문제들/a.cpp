//백준 개미문제 3048
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	int N1 = 0,N2 = 0,T;
	cin >> N1 >> N2 >> T;
	string right, left;
	cin >> right >> left;
	reverse(right.begin(), right.end());
	string ant = right + left;
	int time = 0;
	while (time < T) {
		for (int i = 0; i < N1 + N2 - 1;i++) {
			if (right.find(ant[i]) != string::npos && left.find(ant[i + 1]) != string::npos) {
				swap(ant[i], ant[i + 1]);
				i++;
			}
		}
		time += 1;
	}
	cout << ant;
	
	return 0;
}