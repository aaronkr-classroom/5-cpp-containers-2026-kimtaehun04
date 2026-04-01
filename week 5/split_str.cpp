//split_str.cpp
#include<iostream>
#include<string>
#include<vector>
#include<cctype>//자료형의 함수 여러 개 있다
//isspace: 공백이면 참 값을 반환	


using namespace std;

vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size; //string::size_type은 문자열의 길이를 나타
	string_size i = 0;

	// 불변성: 지금까지 [원래의 i, 현재의 i) 범위에 있는 문자들을 처리
	while (i != s.size()) {
		// 선행하는 공백들을 무시
		// 불변성: 지금까지 [원래의 i, 현재의 i) 범위에 있는 문자들은 모두 공백 (isspace())
		while (i != s.size() && isspace(s[i]))
			++i;

		// 순서상 다음 단어의 끝을 찾음
		string_size j = i;
		// 불변성: 지금까지 [원래의 j, 현재의 j) 범위에 있는 문자들은 모두 공백 (!isspace())
		while (j != s.size() && !isspace(s[j]))
			++j;

		// 공백이 아닌 문자들을 찾았을 때
		if (i != j) {
			// i에서부터 j-1개의 문자들을 s에 복사
			ret.push_back(s.substr(i, j - i));
			i = j; // j인덱스가 i인덱스로 이동
		}
	}

	return ret;
}


