#include <iostream>
#include <string>
#include <vector>
#include "gmock/gmock.h"

using namespace std;

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
