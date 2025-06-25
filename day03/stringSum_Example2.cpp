#include <iostream>
#include <string>
#include <vector>

#include "gmock/gmock.h"

using std::cout;
using std::string;
using std::vector;

TEST(TS, TC1) {
  int ret = 130;
  EXPECT_EQ(ret, 130);
}

int main() {
  // 25+61=100
  // 1 ~ 5자리수 덧셈 수식이 맞는지 확인하는 프로그램
  // 띄어쓰기 없음

  string str = "25+61=86";  // PASS
  // string str = "12345+12345=24690"; //PASS
  // string str = "12345+=12345"; // ERROR
  // string str = "5++5=10"; //ERROR
  // string str = "10000+1=10002"; //FAIL

  int flag1 = 0;
  int cnt1 = 0;
  int cnt2 = 0;
  int p1, p2 = 0;
  //+와 = 개수 확인
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '+') {
      cnt1++;
      p1 = i;
    } else if (str[i] == '=') {
      cnt2++;
      p2 = i;
    } else if (!(str[i] >= '0' && str[i] <= '9')) {
      flag1 = 1;
      break;
    }
  }

  int flag2 = 0;
  if (cnt1 == 1 && cnt2 == 1 && p1 < p2 - 1 && flag1 == 0) {
    if (p1 >= 1 && p2 >= 3 && p2 < str.length() - 1) {
      flag2 = 1;
      string num1 = str.substr(0, p1);
      string num2 = str.substr(p1 + 1, p2 - p1 - 1);
      string num3 = str.substr(p2 + 1);

      int n1 = stoi(num1);
      int n2 = stoi(num2);
      int n3 = stoi(num3);

      if (n1 + n2 == n3) {
        cout << "PASS";
      } else
        cout << "FAIL";
    }
  } else {
    cout << "ERROR";
    flag2 = 1;
  }

  if (flag2 == 0) {
    cout << "ERROR";
  }

  cout << "hello\n";

  testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}
