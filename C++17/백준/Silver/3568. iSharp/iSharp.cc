#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);

    string init;
    vector<string> v;
    string temp;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {  // 공통된 변수형
            init = temp;
            temp.clear();
            continue;
        } 
        else if (s[i] == ',') {  // 하나의 추가 변수형 + 변수 이름의 끝
            v.push_back(temp);
            i++;  // 다음 문자로 이동
            temp.clear();
        } 
        else if (s[i] == ';') {  // 끝
            v.push_back(temp);
            temp.clear();
        } 
        else {
            temp += s[i];
        }
    }

    for (int i = 0; i < v.size(); i++) {
        int idx = -1;

        // 추가적인 변수형 유무 파악
        for (int j = 0; j < v[i].size(); j++) {
            if (!((v[i][j] >= 'a' && v[i][j] <= 'z') || (v[i][j] >= 'A' && v[i][j] <= 'Z'))) {
                idx = j;
                break;
            }
        }

        cout << init;

        // 추가적인 변수형이 없는 경우
        if (idx == -1) {
            cout << " " << v[i];
        } 
        // 추가적인 변수형이 있는 경우
        else {
            // 추가적인 변수형 역순으로 출력
            for (int j = v[i].size() - 1; j >= idx; j--) {
                if (v[i][j] == ']') {
                    cout << "[]";
                    j--;  // 대괄호 맞추기
                    continue;
                }
                cout << v[i][j];
            }

            cout << " ";

            // 변수 이름 출력
            for (int j = 0; j < idx; j++) {
                cout << v[i][j];
            }
        }

        cout << ";\n";
    }

    return 0;
}
