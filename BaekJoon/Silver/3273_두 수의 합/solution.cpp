#include <iostream>
#include <algorithm>

using namespace std;

// Declaration of functions
bool compare(int a, int b);

// Definition of Global variables

// Definition of Main function
int main(void) {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Get information
    int sizeofList;
    cin >> sizeofList;
    int* list = new int[sizeofList];

    for (int i = 0; i < sizeofList; i++) {
        cin >> *(list + i); // cin >> list[i]
    }

    int targetNum;
    cin >> targetNum;

    sort(list, list + sizeofList, compare);

    // Two Pointer Algorithm
    int i, j;
    i = 0; j = sizeofList - 1; // [0], [8]
    int result = 0;
    while (i < j) {
        int sum = *(list + i) + *(list + j); // list[i] + list[j]

        if (sum == targetNum) {
            result++;
            i++; j--;
        }
        else if (sum < targetNum) {
            i++;
        }
        else if (sum > targetNum) {
            j--;
        }
    }

    cout << result << "\n";

    delete[] list;
    
    return 0;
    // [!] When you finish using a pointer and list, free the allocated memory. <- 제발 신경써!!!
}

bool compare(int a, int b) {
    return a < b;
}