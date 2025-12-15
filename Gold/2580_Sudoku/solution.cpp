#include <iostream>
#include <vector>

using namespace std;

/* 입력 <- push 할 때 삭제 할 것 .
0 3 5 4 6 9 2 7 8
7 8 2 1 0 5 6 0 9
0 6 0 2 7 8 1 3 5
3 2 1 0 4 6 8 9 7
8 0 4 9 1 3 5 0 6
5 9 6 8 2 0 4 1 3
9 1 7 6 5 2 0 8 0
6 0 3 7 0 1 9 5 2
2 5 8 3 9 4 7 6 0
*/ 

// 함수 선언
void solveSudoku(int row, int col);

// 변수 선언
int sudoku[9][9];
vector<pair<int, int>> emptySquare; // 0인 칸 index 저장
bool checkRow[9]; // [row][] 체크용
int checkCol[9]; // [][col] 체크용
int checkSquare[9]; // [row/3][col/3] 체크용
int changed = 0; // 음.. 함수 재귀 돌릴 때 횟수 느낌..?? idk lol

int main(void) {
    // 빠른 입출력
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0) emptySquare.push_back({i, j});
        }
    }

    // @@@@@@@@@@@@ 0 인 칸들 제대로 받았는 지 디버깅 @@@@@@@@@@@@
    // for (auto pos : emptySquare) {
    //     cout << pos.first << " " << pos.second << "\n";
    // }

    // solveSudoku(emptySquare.front().first, emptySquare.front().second); <- 레전드 저급한 코드
    solveSudoku(emptySquare[changed].first, emptySquare[changed].second);
    
    cout << "■■■스도쿠 풀이!■■■\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "■■■■■■■■■■■■■■■■■\n";
    return 0;
}

void solveSudoku(int row, int col) {
    // @@@@@@@@@@@@@ 디버깅 @@@@@@@@@@@@@@@@
    cout << "\n";
    cout << "현재 변경 횟수: " << changed << "\n";

    // 종료 구문
    if (changed >= emptySquare.size()) {
        return;
    }

    // 초기화 구문
    fill(begin(checkRow), end(checkRow), false);
    fill(begin(checkCol), end(checkCol), false);
    fill(begin(checkSquare), end(checkSquare), false);


    cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
    cout << "■ 해결할 빈칸 인덱스: " << row << ", " << col << " ■"<< "\n";
    cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";

    // row 체크
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == 0) continue; // 예외처리 (0이면 패스함)
        checkRow[sudoku[row][i] - 1] = true; // 해당 숫자 존재하면 그 숫자를 인덱스로 true 처리함.
    }
    // -> 예상결과 ※ 인덱스 + 1 이 숫자임.
    //    [0] = false
    //    [1] = true
    //    [2] = true
    //    [3] = true
    //    [4] = true
    //    [5] = true
    //    [6] = true
    //    [7] = true
    //    [8] = true

    // 없는 숫자 체크
    for (int i = 0; i < 9; i++) {
        if (!checkRow[i]) {
            cout << "Row에 없는 숫자: " << i + 1 << "\n";
        }
    }

    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == 0) continue; // 예외처리 (0이면 패스함)
        checkCol[sudoku[i][col] - 1] = true; // 해당 숫자 존재하면 그 숫자를 인덱스로 true 처리함.
    }
    // -> 예상 결괴 ※ 인덱스 + 1 이 숫자임.
    //    [0] = false
    //    [1] = true
    //    [2] = true
    //    [3] = false
    //    [4] = true
    //    [5] = true
    //    [6] = true
    //    [7] = true
    //    [8] = true

    // 없는 숫자 체크
    cout << "Col에 없는 숫자: ";
    for (int i = 0; i < 9; i++) {
        if (!checkCol[i]) {
            cout << i + 1 << ", ";
        }
    }
    cout << "\n";

    // 3*3 square 체크
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (sudoku[i][j] == 0) continue; // 예외처리 (0이면 패스함)
            checkSquare[sudoku[i][j] - 1] = true;
        }
    }

    // 없는 숫자 체크
    cout << "Square에 없는 숫자: ";
    for (int i = 0; i < 9; i++) {
        if (!checkSquare[i]) {
            cout << i + 1 << ", ";
        }
    }
    cout << "\n";

    for (int i = 0; i < 9; i++) {
        if (!checkRow[i] && !checkCol[i] && !checkSquare[i]) {
            sudoku[row][col] = i + 1;
            cout << row << " " << col << " 에 " << i + 1 << " 삽입\n";
        }
    }

    changed++;
    solveSudoku(emptySquare[changed].first, emptySquare[changed].second);
}