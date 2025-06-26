
#include "wheel.cpp"

#include "gmock/gmock.h"

TEST(WheelofFortune, Price1) {
  vector<string> strs = {"BUILDLEV", "EATREALROBOT"};
  string userdata = "ERABCDFGHIJKLMNOPQSTUVWXYZ";
  Wheel app;
  int expected = 6500;

  int actual = app.getPrice(strs, userdata);

  EXPECT_EQ(expected, actual);
}

TEST(WheelofFortune, Price2) {
  vector<string> strs = {"ABS", "ABS", "AAAAAKBA"};
  string userdata = "XASBKQDJHMNPTLVUCGEWFORIYZ";
  Wheel app;
  int expected = 9500;

  int actual = app.getPrice(strs, userdata);

  EXPECT_EQ(expected, actual);
}

TEST(WheelofFortune, Price3) {
  vector<string> strs = {"TDABS", "ARDTBS", "AAAAASDFSDFKBA"};
  string userdata = "TXADSQWESBKQDJHMNPTLVUCGEWFORIYZ";
  Wheel app;
  int expected = 7500;

  int actual = app.getPrice(strs, userdata);

  EXPECT_EQ(expected, actual);
}
