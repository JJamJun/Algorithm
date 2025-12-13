#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

// 메인 함수
int main(void) {
    // 빠른 입출력
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 변수 선언
    int bitmask = 0;
    int loopNum;
    cin >> loopNum;

    // 메인 코드
    string command;
    int inputNum;
    for (int i = 0; i < loopNum; i++) {
        cin >> command;

        if (!command.compare("add")) {
            cin >> inputNum;
            bitmask |= (1 << inputNum - 1);
        }
        else if (!command.compare("remove")) {
            cin >> inputNum;
            bitmask &= ~(1 << inputNum - 1);
        }
        else if (!command.compare("check")) {
            cin >> inputNum;
            if (bitmask & (1 << inputNum - 1)) {
                cout << "1" << "\n";
            }
            else cout << "0" << "\n";
        }
        else if (!command.compare("toggle")) {
            cin >> inputNum;
            bitmask ^= (1 << inputNum - 1);
        }
        else if (!command.compare("all")) {
            bitmask = (1 << 20) - 1;
        }
        else if (!command.compare("empty")) {
            bitmask = 0;
        }
    }

    return 0;
}