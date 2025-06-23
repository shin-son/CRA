#include<iostream>
#include<vector>

struct xyInfo {
	int x;
	int y;
};

class xyManager {
public:
	void add(xyInfo data) {
		arr.push_back(data);
	}

	void drawButton() {
		for (xyInfo o : arr) {
			std::cout << o.x << " " << o.y << std::endl;
		}
	}

private:
	std::vector<xyInfo> arr;
};

int main() {

	return 0;
}
