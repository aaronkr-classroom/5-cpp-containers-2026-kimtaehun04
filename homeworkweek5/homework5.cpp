/*문제 해결 알고리즘
회전 집단 생성 : 각 행을 읽고 단어 단위로 분리한 뒤, 모든 단어가 한 번씩 첫 번째 위치에 오도록 문자열을 회전시킵니다.
구분 및 저장 : 회전된 문자열을 '기준 단어 이전 부분'과 '기준 단어를 포함한 뒷부분' 두 가지로 나누어 구조체에 저장합니다.
정렬 : 구조체에 저장된 '뒷부분' 문자열을 기준으로 알파벳 순(대소문자 구분 없이)으로 정렬합니다.
포맷팅 출력 : 출력 열을 맞추기 위해 '앞부분' 문자열 중 가장 긴 길이를 찾은 뒤, 그에 맞춰 여백을 추가하여 출력합니다*/




#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <iomanip>

using namespace std;

// 2단계: 원래 구문과 회전된 구문을 명확히 구분하기 위한 구조체
struct Rotation {
    string left;  // 인덱스 기준 단어의 앞부분
    string right; // 인덱스 기준 단어부터 끝까지
};

// 3단계: 대소문자 구분 없이 정렬하기 위한 비교 함수
bool compareNoCase(const Rotation& a, const Rotation& b) {
    string strA = a.right;
    string strB = b.right;

    // 소문자로 변환하여 비교
    transform(strA.begin(), strA.end(), strA.begin(), ::tolower);
    transform(strB.begin(), strB.end(), strB.begin(), ::tolower);

    return strA < strB;
}

int main() {
    // 테스트용 입력 데이터
    vector<string> lines = {
        "The quick brown fox",
        "jumped over the fence"
    };

    vector<Rotation> rotations;

    // 1단계: 각 행을 읽고 회전 집단 만들기
    for (const string& line : lines) {
        vector<string> words;
        stringstream ss(line);
        string word;

        // 공백을 기준으로 단어 분리
        while (ss >> word) {
            words.push_back(word);
        }

        // 각 단어를 기준으로 회전 집단(Rotation) 생성
        for (size_t i = 0; i < words.size(); ++i) {
            Rotation rot;

            // 기준 단어 앞부분 (왼쪽 출력 파트)
            for (size_t j = 0; j < i; ++j) {
                rot.left += words[j];
                if (j < i - 1) rot.left += " "; // 단어 사이 공백 추가
            }

            // 기준 단어부터 문장 끝까지 (오른쪽 출력 파트)
            for (size_t j = i; j < words.size(); ++j) {
                rot.right += words[j];
                if (j < words.size() - 1) rot.right += " "; // 단어 사이 공백 추가
            }
            rotations.push_back(rot);
        }
    }

    // 3단계: 회전 집단 정렬 (대소문자 무시)
    sort(rotations.begin(), rotations.end(), compareNoCase);

    // 4단계: 알맞은 형태로 출력하기 위해 왼쪽 문자열의 최대 길이 계산
    size_t maxLeftLength = 0;
    for (const auto& rot : rotations) {
        maxLeftLength = max(maxLeftLength, rot.left.length());
    }

    // 결과 출력 (오른쪽 정렬을 위해 setw 활용)
    for (const auto& rot : rotations) {
        // setw()를 사용하여 왼쪽 여백을 자동으로 맞추고 출력
        cout << setw(maxLeftLength) << rot.left
            << "   " << rot.right << endl;
    }

    return 0;
}
