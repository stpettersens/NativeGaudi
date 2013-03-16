#include <iostream>
#include <string>
#include <vector>
using namespace std;

string* bubbleSort(int poss[], string found[], int n);

string* bubbleSort(int poss[], string found[], int n) {
	bool swapped = true;
	int j = 0;
	int tmp;
	string stmp;
	while(swapped) {
		swapped = false;
		j++;
		for(int i = 0; i < n - j; i++) {
			if(poss[i] > poss[i + 1]) {
				tmp = poss[i];
				poss[i] = poss[i + 1];
				poss[i + 1] = tmp;
				stmp = found[i];
				found[i] = found[i + 1];
				found[i + 1] = stmp;
				swapped = true;
			}
		}
	}
	return found;
}

int main() {
	string string_with_cats = "Persian, Siamese, Shorthair, Siamese, Mr. Mittens, Tomcat, Tortoise-shell";
	vector<string> cats(0);
	vector<string> found(0);
	vector<int> poss(0);
	cats.push_back("Siamese");
	cats.push_back("Persian");
	cats.push_back("Shorthair");
	cats.push_back("Tortoise-shell");
	cats.push_back("Tomcat");

	int i = 0;
	while(i < cats.size()) {
		int pos = string_with_cats.find(cats[i]);
		if(pos != string::npos) {
			found.push_back(cats[i]);
			poss.push_back(pos);
		}
		i++;
	}
	int *aposs = &poss[0];
	string *afound = &found[0];
	afound = bubbleSort(aposs, afound, poss.size());
	for(int i = 0; i < found.size(); i++)
		cout << afound[i] << endl;

	return 0;
}
