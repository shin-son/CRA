#include <iostream>
#include <vector>

//UML 동사 + 명사
void stayOneDay(std::vector<int>& rooms) {
  for (int roomNumber = 0; roomNumber < rooms.size(); roomNumber++) {
    if (rooms[roomNumber] == 0) continue;
    rooms[roomNumber] = rooms[roomNumber] - 1;
  }
}

int main() { return 0; }
