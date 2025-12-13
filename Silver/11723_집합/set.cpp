#include <iostream>
#include <set>
#include <cstring>

using namespace std;

// 함수 선언
set<int> add (set<int> list, int number);      // number를 list에 추가
set<int> remove (set<int> list, int number);   // number를 list에서 제거
set<int> check (set<int> list, int number);    // number가 list에 있으면 1, 없으면 0 출력
set<int> toggle (set<int> list, int number);   // number가 list에 있으면 제거, 없으면 추가
set<int> all (set<int> list);                  // 1~20까지의 수를 모두 추가
set<int> empty (set<int> list);                // list을 비움


// 메인 함수
int main(void) {
    // 변수 선언
    set<int> list;
    int inputNum;

    string command;
    cin >> command;

    if (command.compare("add") == 0) {
        
    }
}