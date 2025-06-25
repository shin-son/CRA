#include <algorithm>
#include <string>

#include <gtest/gtest.h>

using std::string;

namespace {

bool isDigits(const string& s) {
    return !s.empty() &&
           std::all_of(s.begin(), s.end(), [](unsigned char c) { return std::isdigit(c); });
}

string checkSum(const string& text) {
    auto plusPos = text.find('+');
    auto equalPos = text.find('=');
    if (plusPos == string::npos || equalPos == string::npos) return "ERROR";
    if (text.find('+', plusPos + 1) != string::npos) return "ERROR";
    if (text.find('=', equalPos + 1) != string::npos) return "ERROR";
    if (plusPos == 0 || plusPos >= equalPos - 1 || equalPos >= text.size() - 1) return "ERROR";

    auto a = text.substr(0, plusPos);
    auto b = text.substr(plusPos + 1, equalPos - plusPos - 1);
    auto c = text.substr(equalPos + 1);
    if (!isDigits(a) || !isDigits(b) || !isDigits(c)) return "ERROR";

    long n1 = std::stol(a);
    long n2 = std::stol(b);
    long n3 = std::stol(c);
    return (n1 + n2 == n3) ? "PASS" : "FAIL";
}

}  // namespace

TEST(StringSum, PassExample) { EXPECT_EQ("PASS", checkSum("25+61=86")); }
TEST(StringSum, LargeNumbers) { EXPECT_EQ("PASS", checkSum("12345+12345=24690")); }
TEST(StringSum, InvalidFormat1) { EXPECT_EQ("ERROR", checkSum("12345+=12345")); }
TEST(StringSum, InvalidFormat2) { EXPECT_EQ("ERROR", checkSum("5++5=10")); }
TEST(StringSum, CalculationFail) { EXPECT_EQ("FAIL", checkSum("10000+1=10002")); }

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
