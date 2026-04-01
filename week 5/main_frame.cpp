//main_frame.cpp
#include <iostream>
#include <string>
#include "frame.h"
#include <vector>

using namespace std;

int main() {
	string s;
	vector<string> v;
	//문자열을 한 행씩 입력받아 벡터에 저장
	while (getline(cin, s)) {
		v.push_back(s);
	}
	//벡터 v에 저장한 문자열을 프레임으로 감싸서 출력
	vector<string> f = frame(v);
	for (vector<string>::size_type i = 0; i != f.size(); i++) {
		cout << f[i] << endl;
	}
	return 0;
}
