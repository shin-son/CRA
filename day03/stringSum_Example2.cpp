#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "gmock/gmock.h"

using namespace testing;
using std::cout;
using std::string;
using std::vector;

class sumFixture : public Test {
 public:
  string checkEquation(const string& text) {
    plusPos = text.find('+');
    equalPos = text.find('=');

    if (plusPos == string::npos || equalPos == string::npos) return "FAIL";
    if (text.find('+', plusPos + 1) != string::npos) return "FAIL";
    if (text.find('=', equalPos + 1) != string::npos) return "FAIL";
    if (plusPos == 0 || plusPos >= equalPos - 1 || equalPos >= text.size() - 1)
      return "FAIL";

    return text;
  }

  string checkSum(const string& text) {
    if (text == "FAIL") return "FAIL";

    auto num1String = text.substr(0, plusPos);
    auto num2String = text.substr(plusPos + 1, equalPos - plusPos - 1);
    auto sumString = text.substr(equalPos + 1);
    if (!isDigits(num1String) || !isDigits(num2String) || !isDigits(sumString))
      return "FAIL";

    long num1 = stol(num1String);
    long num2 = stol(num2String);
    long sum = stol(sumString);

    return (num1 + num2 == sum) ? "PASS" : "FAIL";
  }

  bool isDigits(const string& num) {
    return !num.empty() &&
           std::all_of(num.begin(), num.end(),
                       [](unsigned char c) { return std::isdigit(c); });
  }

 private:
  std::string::size_type plusPos;
  std::string::size_type equalPos;
};

TEST_F(sumFixture, TC1) {
  EXPECT_EQ("PASS", checkSum(checkEquation("25+61=86")));
}

TEST_F(sumFixture, TC2) {
  EXPECT_EQ("PASS", checkSum(checkEquation("12345+12345=24690")));
}

TEST_F(sumFixture, TC3) {
  EXPECT_EQ("FAIL", checkSum(checkEquation("12345+=12345")));
}

TEST_F(sumFixture, TC4) {
  EXPECT_EQ("FAIL", checkSum(checkEquation("5++5=10")));
}

TEST_F(sumFixture, TC5) {
  EXPECT_EQ("FAIL", checkSum(checkEquation("10000+1=10002")));
}

int main() {
  cout << "Goole Unit Test Starts\n";

  testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}
