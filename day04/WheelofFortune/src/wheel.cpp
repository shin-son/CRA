#include <string>
#include <vector>

using std::string;
using std::vector;

class Wheel {
 public:
  int getPrice(vector<string> strs, string userdata) {
    int map[4][15] = {0};
    int conCnt = 0;
    int ffirst[4] = {0};

    int sum = 0;
    int chance[4] = {-1, -1, -1, -1};

    // �ϳ��� ó��
    // 26���� for ���鼭 ���� �����ڰ� �ϳ��� �õ��� �ϴ� ��
    for (int i = 0; i < 26; i++) {
      // 1. 2000 �޷� ������ ������� �˻�
      for (int y = 0; y < strs.size(); y++) {
        if (chance[y] != -1) {
          for (int x = 0; x < strs[chance[y]].size(); x++) {
            if (map[chance[y]][x] == 0 && strs[chance[y]][x] == userdata[i]) {
              // ȹ�� ������ 2000�޷��� ��´�.
              sum += 2000;
              break;
            }
          }
          chance[y] = -1;
        }
      }

      int flag = 0;
      int passCnt = 0;

      // 2�� for ���鼭 ���� ���ڿ��� �ϳ��� �˻��ؼ�
      // ���������ڰ� ���� ���ڰ� �����ϴ��� �˻�
      for (int y = 0; y < strs.size(); y++) {
        for (int x = 0; x < strs[y].size(); x++) {
          if (map[y][x] == 1) continue;

          // ���� ���������ڰ� ��û�� ���ڰ�,
          // ���乮�ڿ��� �����ϴٸ�
          if (strs[y][x] == userdata[i]) {
            // Let's First �������� Ȯ���Ѵ�.
            if (ffirst[y] == 0 && x == 0) {
              sum += 1000;
              ffirst[y] = 1;
              chance[y] = y;
            } else if (ffirst[y] == 0 && x != 0) {
              ffirst[y] = 1;
            }

            // used�迭
            map[y][x] = 1;

            // �ش� ���ڸ� _�� �ٲ������.
            strs[y][x] = '_';
            flag = 1;

            // ������ ���� ������ Counting�Ѵ�.
            passCnt++;
          }
        }
      }

      if (flag == 1) {
        conCnt++;
        sum += (conCnt * 100) * passCnt;
      } else {
        conCnt = 0;
        for (int i = 0; i < 4; i++) chance[i] = -1;
      }
    }

    return sum;
  }
};