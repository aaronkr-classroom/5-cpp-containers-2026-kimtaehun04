// Student_info.cpp
#include "student_info.h"

//이름 비교하기
bool compare(const Student_info& a, const Student_info& b) {
	return a.name < b.name;
}

// 한 학생의 정보 읽기
istream&read(istream& is, Student_info& s) {
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}
//모든 과제 점수 읽기
istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		hw.clear(); //과제 점수 벡터 초기화

		double x;
		while (in >> x) //과제 점수 읽기
			hw.push_back(x);
		in.clear(); //스트림 상태 초기화
	}
	return in;
}
	


