#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct dominot {
	int leftdots;
	int rightdots;
	dominot(int left = 0, int right = 0) {
		leftdots = left;
		rightdots = right;
	}
};

void input(dominot& dmnt) {
	cin >> dmnt.leftdots;
	cin >> dmnt.rightdots;
}
void print(dominot dmnt) {
	cout << dmnt.leftdots << "|" << dmnt.rightdots <<" - ";
}
bool FormsDominoChain(vector<dominot>& dominos,int l,int r) {
	if (l == r) {
		for (int i = 0; i < (dominos.size()-1); i++) {
			if (dominos[i].rightdots != dominos[i + 1].leftdots) {
				return false;
			}
		}
		return true;
	}
	else {
		for (int i = l; i <= r; i++) {
			swap(dominos[l], dominos[i]);
			if (FormsDominoChain(dominos, l + 1, r) == true)
				return true;
			swap(dominos[l], dominos[i]);
		}
		return false;
	}
}
int main() {
	int N_dominos = 0;
	cout << "Enter the number of dominos" << endl;
	cin >> N_dominos;
	vector<dominot>dominos(N_dominos);
	for (int i = 0; i < N_dominos; i++) {
		input(dominos[i]);
	}
	int l = 0,r=N_dominos-1;
	if (FormsDominoChain(dominos, l, r) == true) {
		cout << "valid dominos" << endl;
		for (int i = 0; i < N_dominos - 1; i++) {
			print(dominos[i]);
		}
		cout << dominos[N_dominos - 1].leftdots << "|" << dominos[N_dominos - 1].rightdots << endl;
	}
	else
		cout << "not valid" << endl;
	
}

