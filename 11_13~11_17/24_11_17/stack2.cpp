//백준 28278 스택2
#include <iostream>
#include <stack>

using namespace std;

stack<int> myStack;

void solution(int n) {
    switch (n) {
    case 1:
        int num;
        scanf("%d", &num);
        myStack.push(num);
        break;
    case 2:
        if (!myStack.empty()) {
            printf("%d\n", myStack.top());
            myStack.pop();
        }
        else {
            printf("-1\n");
        }
        break;
    case 3:
        printf("%d\n", myStack.size());
        break;
    case 4:
        if (!myStack.empty()) {
            printf("0\n");
        }
        else {
            printf("1\n");
        }
        break;
    case 5:
        if (!myStack.empty()) {
            printf("%d\n", myStack.top());
        }
        else {
            printf("-1\n");
        }
        break;
    default:
        break;
    }
}

int main() {
    int N;
    int order;
    scanf("%d", &N);

    while (N--) {
        scanf("%d", &order);
        solution(order);
    }

    return 0;
}