#include<iostream>
#include<vector>

void run(std::vector<int>& theVector) {
	for (int t = 0; t < theVector.size(); t++) {
		if (theVector[t] == 0) continue;
		theVector[t] = theVector[t] - 1;
	}
}

int main() {

	return 0;
}
