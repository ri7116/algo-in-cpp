#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<long long, long long>> v;

int n;
long long a, b;
long long st, ed;
long long cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back(make_pair(a, b)); // 벡터에 넣기
    }
    sort(v.begin(), v.end()); // 정렬

    /*cout << endl;
    for (auto a : v) {
        cout << a.first << " " << a.second << endl;
    }
    cout << endl;*/

    st = v[0].first;
    ed = v[0].second;
    /*cout << "1번째 점 할당 하겠습니다" << endl;*/
    
    for (int i = 1; i < n; i++) {
        if (i == n - 1) {// 마지막 선분
            if (st <= v[i].first and v[i].second < ed) {// 기존선 가운데 있을때
                //cout << "마지막 선분이 낑겨 있습니다" << endl;
                cnt += ed - st;
            }

            else if (v[i].first <= ed and ed <= v[i].second) {//x는 왼쪽 Y는 오른쪽에 있을때
                ed = v[i].second;
                //cout << "y가 새롭게 갱신되었습니다 마지막 선분을 처리합니다" << "ed는" << ed << "입니다" << endl;
                cnt += (ed - st);
            }

            else {// 새로운 선을 만났을때
                cnt += (ed - st);
                st = v[i].first;
                ed = v[i].second;
                cnt += (ed - st);
                //cout << "기존 길이를 계산하고 마지막 선을 처리하겠습니다" << endl;

            }
         }

        else if (st <= v[i].first and v[i].second<ed) {// 기존선 가운데 있을때
            //cout << "가운데 선에 있습니다" << endl;
            continue;
        }

        else if ( v[i].first <=ed and ed <= v[i].second) {//x는 왼쪽 Y는 오른쪽에 있을때
            ed = v[i].second;
            //cout << "y가 새롭게 갱신되었습니다" <<"ed는"<<ed<<"입니다" << endl;
            
        }

        else {//x오른쪽 y오른쪽
            cnt += (ed - st);
            st = v[i].first;
            ed = v[i].second;
            //cout << "기존 길이를 계산하고 새로운 선을 할당하겠습니다" << endl;
        }

    }
    if (v.size() == 1) {
        cnt += ed - st;
    }
    cout << cnt << endl;
}