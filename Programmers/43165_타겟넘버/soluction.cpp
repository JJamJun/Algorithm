#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 변수 선언
int totalResult = 0;

// DFS 함수 선언
void dfs(vector<int> numbers, int target, int count, int total);

// 메인? 함수
int solution(vector<int> numbers, int target) {
    int answer = 0;

	dfs(numbers, target, 0, 0);
	
	answer = totalResult;

    return answer;
}

void dfs(vector<int> numbers, int target, int count, int total) {
    if (numbers.size() == count) {
        if (total == target) {
            totalResult++;
            return;
        }
        else return;
    }

    dfs(numbers, target, count + 1, total + numbers[count]);
    dfs(numbers, target, count + 1, total - numbers[count]);

    return;
}