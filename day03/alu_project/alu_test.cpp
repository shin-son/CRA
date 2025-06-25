#include "alu.cpp";

#include "gmock/gmock.h"
#include "result.cpp";

TEST(ALU, ADDTest) {
  ALU alu;
  alu.setOperand1(10);
  alu.setOperand2(20);
  alu.setOPCODE("ADD");

  Result ret;
  alu.enableSignal(&ret);

  EXPECT_EQ(30, ret.getResult());
  EXPECT_EQ(0, ret.getStatus());

  alu.setOperand1(-1);
  alu.setOperand2(20);
  alu.setOPCODE("ADD");

  alu.enableSignal(&ret);

  EXPECT_EQ(65535, ret.getResult());
  EXPECT_EQ(1, ret.getStatus());

  alu.setOperand1(10);
  alu.setOperand2(-1);
  alu.setOPCODE("ADD");

  alu.enableSignal(&ret);

  EXPECT_EQ(65535, ret.getResult());
  EXPECT_EQ(2, ret.getStatus());

  alu.setOperand1(10);
  alu.setOperand2(-1);
  alu.setOPCODE("merong");

  alu.enableSignal(&ret);

  EXPECT_EQ(65535, ret.getResult());
  EXPECT_EQ(3, ret.getStatus());
}

TEST(ALU, MULTest) {
  ALU alu;
  alu.setOperand1(10);
  alu.setOperand2(20);
  alu.setOPCODE("MUL");

  Result ret;
  alu.enableSignal(&ret);

  EXPECT_EQ(200, ret.getResult());
  EXPECT_EQ(0, ret.getStatus());

  alu.setOperand1(-1);
  alu.setOperand2(-1);
  alu.setOPCODE("MUL");

  alu.enableSignal(&ret);

  EXPECT_EQ(65535, ret.getResult());
  EXPECT_EQ(1, ret.getStatus());

  alu.setOperand1(1);
  alu.setOperand2(-1);
  alu.setOPCODE("MUL");

  alu.enableSignal(&ret);

  EXPECT_EQ(65535, ret.getResult());
  EXPECT_EQ(2, ret.getStatus());
}

TEST(ALU, SUBTest) {
  ALU alu;
  alu.setOperand1(10);
  alu.setOperand2(20);
  alu.setOPCODE("SUB");

  Result ret;
  alu.enableSignal(&ret);

  EXPECT_EQ(-10, ret.getResult());
  EXPECT_EQ(0, ret.getStatus());

  alu.setOperand1(-1);
  alu.setOperand2(20);
  alu.setOPCODE("SUB");

  alu.enableSignal(&ret);

  EXPECT_EQ(65535, ret.getResult());
  EXPECT_EQ(1, ret.getStatus());

  alu.setOperand1(10);
  alu.setOperand2(-1);
  alu.setOPCODE("SUB");

  alu.enableSignal(&ret);

  EXPECT_EQ(65535, ret.getResult());
  EXPECT_EQ(2, ret.getStatus());
}
