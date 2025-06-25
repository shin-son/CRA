#include <string>

#include "result.cpp"

class ALU {
  int operand1 = -1;
  int operand2 = -1;
  std::string OPCODE = "";

 public:
  void setOperand1(int operand1) { this->operand1 = operand1; }

  void setOperand2(int operand2) { this->operand2 = operand2; }

  void setOPCODE(std::string OPCODE) { this->OPCODE = OPCODE; }

  void enableSignal(Result* r) {
    if (OPCODE == "ADD") {
      if (isOperandsVaild(r)) {
        int result = operand1 + operand2;
        r->setResult(result);
        r->setStatus(0);
      }
    } else if (OPCODE == "MUL") {
      if (isOperandsVaild(r)) {
        int result = operand1 * operand2;
        r->setResult(result);
        r->setStatus(0);
      }
    } else if (OPCODE == "SUB") {
      if (isOperandsVaild(r)) {
        int result = operand1 - operand2;
        r->setResult(result);
        r->setStatus(0);
      }
    } else {
      r->setResult(65535);
      r->setStatus(3);
    }
  }

  bool isOperandsVaild(Result* r) {
    if (operand1 == -1) {
      r->setResult(65535);
      r->setStatus(1);
      return false;
    } else if (operand2 == -1) {
      r->setResult(65535);
      r->setStatus(2);
      return false;
    } else {
      return true;
    }
  }
};