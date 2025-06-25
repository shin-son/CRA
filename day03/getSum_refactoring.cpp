
#include <iostream>
#include <string>
#include <vector>

#include "gmock/gmock.h"

using std::cout;
using std::string;
using std::vector;

class SplitSum {
 public:
  int splitAndSum(string text) {
    int result = 0;
    if (text.empty()) return 0;
    return getSum(toInts(split(text)));
  }

 private:
  int getSum(const vector<int>& nums) {
    int ret = 0;
    for (int num : nums) ret += num;
    return ret;
  }

  vector<int> toInts(const vector<string>& arr) const {
    vector<int> values;
    for (int i = 0; i < arr.size(); i++) {
      int temp = stoi(arr[i]);
      values.push_back(temp);
    }
    return values;
  }

  vector<string> split(string text) {
    vector<string> values;
    text += "-";
    // split
    int a = 0, b = 0;
    while (1) {
      b = text.find("-", a);
      if (b == -1) break;
      string temp = text.substr(a, b - a);
      values.push_back(temp);
      a = b + 1;
    }
    return values;
  }
};

TEST(TS, TC1) {
  SplitSum app;
  int ret = app.splitAndSum("100-10-20");
  EXPECT_EQ(ret, 130);
}

int main() {
  SplitSum app;
  cout << app.splitAndSum("100-10-20");

  testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}