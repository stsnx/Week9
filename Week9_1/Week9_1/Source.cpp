#include<iostream>
#include<math.h>
using namespace std;

struct ip {
	int dec[4];
	int cidr;
	char slash;
} Data[20], tempdat;
int callbimimus(int data, int node, int minus) {
	int temp[8];
	int tempdat = data;
	for (int i = 7; i >= 0; i--) {

		if (tempdat > 0) {
			temp[i] = tempdat % 2;
			tempdat /= 2;
		}
		else temp[i] = 0;
	}
	for (int i = minus + 1; i <= 8; i++) {
		temp[i - 1] = 0;
	}
	int conduc = 1, sum = 0;
	for (int i = 7; i >= 0; i--) {

		sum += (temp[i] * conduc);
		conduc *= 2;
	}

	return sum;
}
void callsub(int n) {
	for (int i = 0; i < n; i++) {
		if (Data[i].slash == '/') {
			int node = Data[i].cidr / 8;
			int minus = Data[i].cidr % 8;
			int res;
			for (int j = node; j < 4; j++) {
				if (j == node) {
					res = callbimimus(Data[i].dec[j], node, minus);
					Data[i].dec[j] = res;
				}
				else Data[i].dec[j] = 0;
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) cin >> Data[i].dec[j];
		cin >> Data[i].slash >> Data[i].cidr;
	}
	callsub(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cout << Data[i].dec[j];
			if (j != 3) cout << '.';
		}
		cout << endl;
	}
}
