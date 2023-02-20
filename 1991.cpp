// 이진 트리를 입력받아 preorder traversal, inorder traversal, postorder traversal한 결과를 출력하는 프로그램
#include <iostream>

using namespace std;

int N; // 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)
pair<char, char> arr[26];

void preorder(char x);
void inorder(char x);
void postorder(char x);
int main(){
    // 노드 개수 입력 받기
    cin >> N;
    // N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다.
    // 노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다.
    // 자식 노드가 없는 경우에는 .으로 표현한다.
    for (int i=1; i<=N; i++){
        char root, left, right;
        cin >> root >> left >> right;
        arr[(root-'A')].first = left;
        arr[(root-'A')].second = right;
    }

    // 첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.
    preorder('A');
    cout << '\n';

    inorder('A');
    cout << '\n';

    postorder('A');
    cout << '\n';

    return 0;
}

void preorder(char x){
    // 전위 순회(preorder)한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
    // 트리가 비어 있지 않다면 
    if (x!='.'){
        cout << x;
        preorder(arr[x-'A'].first);
		preorder(arr[x-'A'].second);
    }
}
void inorder(char x){
    // 중위 순회(inorder)한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
    if (x!='.'){
        inorder(arr[x-'A'].first);
        cout << x;
        inorder(arr[x-'A'].second);
    }
}
void postorder(char x){
    // 후위 순회(postorder)한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)
    if (x!='.'){
        postorder(arr[x-'A'].first);
        postorder(arr[x-'A'].second);
        cout << x;
    }
}