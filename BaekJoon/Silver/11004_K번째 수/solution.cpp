#include <iostream>
#include <algorithm>

using namespace std;

int compare(const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    // 빠른 입출력
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int loopNum, inputNum;

    cin >> loopNum >> inputNum;
    int * list = new int[loopNum];
    for (int i = 0; i < loopNum; i++) {
        cin >> list[i];
    }

    qsort(list, loopNum, sizeof(int), compare);

    cout << list[inputNum - 1];
    return 0;
}