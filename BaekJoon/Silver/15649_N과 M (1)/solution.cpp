#include <iostream>

using namespace std;

// 변수 선언
bool visited[9];
int result[9];
int depth;

// 함수 선언
void dfs(int depth, int N, int M);

int main(void) {
    // 빠른 입출력
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // 숫자의 범위, 뽑는 개수?
    int *visited = new int[M];

    cin >> N >> M;

    dfs(0, N, M);
}

void dfs(int depth, int N, int M) {
    if (depth == M) {
        for (int i = 1; i <= M; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";

        return;
    }

    else {
        for (int i = 1; i <= N; i++) {
            if (visited[i]) continue;
            else {
                visited[i] = true;
                result[depth + 1] = i;
                dfs(depth + 1, N, M);
                visited[i] = false;
            }
        }
    }
}