#include "student_info.h"

//이름 비교하기
bool compare(const Student_info& a, const Student_info& b) {
	return a.name < b.name;
}

// 한 학생의 정보 읽기 함수 시그니처 및 구현 수정
istream& read(istream& is, Student_info& s) {
    // 학생 이름, 중간고사, 기말고사 점수 읽어 저장
    is >> s.name >> s.midterm >> s.final;
    return is;
}
