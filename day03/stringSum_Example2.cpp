#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "gmock/gmock.h"

using std::cout;
using std::string;
using std::vector;

TEST_F(sumFixture, TC1) {
  EXPECT_EQ("PASS", checkSum(checkEquation("25+61=86")));
}

TEST_F(sumFixture, TC2) {
  EXPECT_EQ("PASS", checkSum(checkEquation("12345+12345=24690")));
}

class sumFixture {
 public:
 private:
  std::string::size_type plusPos;
  std::string::size_type equalPos;

  string checkEquation(const string text) {
    plusPos = text.find('+');
    equalPos = text.find('=');

    if (plusPos == string::npos || equalPos == string::npos) return "ERROR";
    if (text.find('+', plusPos + 1) != string::npos) return "ERROR";
    if (text.find('=', equalPos + 1) != string::npos) return "ERROR";
    if (plusPos == 0 || plusPos >= equalPos - 1 || equalPos >= text.size() - 1)
      return "ERROR";

    return text;
  }

  string checkSum(const string& text) {
    auto num1String = text.substr(0, plusPos);
    auto num2String = text.substr(plusPos + 1, equalPos - plusPos - 1);
    auto sumString = text.substr(equalPos + 1);
    if (!isDigits(num1String)) || !isDigits(num2String) || !isDigits(sumString)) return "ERROR";

    long num1 = stol(num1String);
    long num2 = stoI(num2String);
    long sum = stol(sumString);

    return (num1 + num2 == sum) ? "PASS" : "FAIL";
  }

  bool isDigits(const string& num) {
    return !num.empty() &&
           std::all_of(num.begin(), num.end(),
                       [](unsigned char c) { return std::isdigit(c); });
  };

  int main() {
    cout << "hello2\n";
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
  }
