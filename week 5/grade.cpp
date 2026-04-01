//grade.cpp
#include <vector>
#include "Student_info.h"
#include "grade.h"
#include <stdexcept>
#include "median.h"
#include <list>

// 중간고사 점수, 기말고사 점수, 과제 점수의 벡터로 학생의 종합
// 점수를 구함. 이 함수는 인수를 복사하지 않고 median 함수가
// 해당 작업을 실행
using std::list;
using std::vector;
double grade(double mid, double fin, const vector<double>& hw) {
	if (hw.size() == 0) {
		throw domain_error("Student has done no homework!");
	}
	// return 0.2 * mid + 0.4 * fin + 0.4 * (hw1 + hw2 ...) / hw.size())
	// NEW grade() 함수
	return grade(mid, fin, median(hw));
}

// 계산하는 grade() 함수
double grade(double midterm, double final, double homework) {
	return midterm * 0.2 + final * 0.4 + homework * 0.4;
}

//Student_info 계산
double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);

}

double
bool fgrade(const Student_info& s){
	return grade(s) < 60;
}
	
vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> fails;
	//vector<Student_info>::size_type i = 0;
	vector<Student_info>::iterator iter = students.begin();

	// 불변성: students qorxjdml [0,i) 범위에 있는
	// 요소들은 과목을 통과한 학생들의 정보
	
	while (iter != students.end()) {
		//if (grade(students[i]) < 60) {
		if (fgrade(*iter)) {
			//fails.push_back(students[i]);
			fails.push_back(*iter); // 학생이 과목을 통과하지 못한 경우, fails 벡터에 학생 정보 추가
			//students.erase(students.begin() + i); // i번째 제거// students 벡터에서 i번째 요소 제거
			iter = students.erase(iter); // 학생이 제거되었으므로 iter는 다음 요소를 가리키도록 업데이트
			// 학생이 제거되었으므로 i는 증가하지 않음
		} else {
			//++i;
			++iter; // 학생이 과목을 통과한 경우, iter는 다음 요소를 가리키도록 업데이트
		}
	}
	return fails;
}

list<Student_info> extract_fails(list<Student_info>& students) {
	list<Student_info> fails;
	list<Student_info>::iterator iter = students.begin();


	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fails.push_back(*iter); 
			iter = students.erase(iter);
		}
		else {

			++iter;
		}
	}
	return fails;



