#include<bits/stdc++.h>
using namespace std;

#define lower_range 1
#define upper_range	10000


#define ll	long long

int AI(ll _random) {
	ll s = lower_range, e = upper_range;
	ll computer_count = 0;

	while (s <= e) {
		ll mid = s + (e - s) / 2;

		if (mid == _random) {
			break;
		}
		else if (mid > _random) {
			e = mid - 1;
			computer_count++;
		} else if (mid < _random) {
			s = mid + 1;
			computer_count++;
		}
	}

	cout << "Computer got to the target in\t" << computer_count << " tries" << endl;

	return computer_count;
}

int main() {
	srand(time(0));
	ll _random = lower_range + (rand() % upper_range); // generating the number to be searched for
	cout << "Random number =\t" << _random << endl;

	// for computer inputs ----------
	int computer_count = AI(_random);


	// for human inputs -------------
	ll x, human_count = 0; cin >> x;
	bool flag = true;

	if (x == _random) 
	{
		cout << human_count << endl;
		flag = false;
	}
	else if (x < _random) {
		cout << "The number which you are looking for is\t bigger than\t" << x << endl; 
		human_count++;
	}
	else {
		cout << "The number which you are looking for is\t smaller than\t" << x << endl; 
		human_count++;
	}

	if (flag) {
		while (x != _random) 
		{
			cin >> x;
			
			if (x == _random) {
				break;
			}
			else if (x < _random) { 
				cout << "The number which you are looking for is\t bigger than\t" << x << endl; 
				human_count++; 
			}
			else { 
				cout << "The number which you are looking for is\t smaller than\t" << x << endl; 
				human_count++;
			}
		}
		cout << "You got to the target in\t" << human_count << "tries" << endl;
	}

	if (human_count < computer_count) {
		cout << "You won the game" << endl;
	} else if (computer_count < human_count) {
		cout << "Computer won the game" << endl;
	} else {
		cout << "Draw" << endl;
	}
}
