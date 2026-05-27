//grade.cpp
// 이 파일은 UTF-8 인코딩으로 저장되어야 합니다.
// Visual Studio에서 "다른 이름으로 저장" > "인코딩 포함" > "UTF-8" 선택

#include <vector>
#include "Student_info.h"
#include "grade.h"
#include <stdexcept>
#include "median.h"
#include <list>
#include <algorithm> //find() 알고리즘 사용

using std::list;
using std::vector;

double grade(double mid, double fin, const vector<double>& hw) {
	if (hw.size() == 0) {
		throw domain_error("Student has done no homework!");
	}
	return grade(mid, fin, median(hw));
}

double grade(double midterm, double final, double homework) {
	return midterm * 0.2 + final * 0.4 + homework * 0.4;
}

double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}

// 기존 fgrade 함수와 충돌을 피하기 위해 함수명을 변경
static bool fgrade_struct(const Student_info& s) {
    return grade(s) < 60;
}

// pgrade도 fgrade_struct를 사용하도록 수정
bool pgrade_struct(const Student_info& s) {
    return !fgrade_struct(s);
}

// Student_info 클래스에 homework 벡터에 대한 getter 추가
public:
    // ... 기존 코드 ...
    const vector<double>& getHomework() const { return homework; }


// 기존 struct 기반 Student_info와 class 기반 Student_info가 혼재되어 발생하는 문제 해결
// 클래스 기반 Student_info에 맞게 did_all_hw 함수 수정

bool did_all_hw(const Student_info& s) {
    // 클래스의 homework 멤버에 접근하려면 public getter 필요
    // Student_info 클래스에 getHomework() const 멤버 함수가 없으므로, 추가 필요
    // 임시로 friend 선언 또는 public 멤버로 변경하거나, getter 추가 후 아래처럼 사용
    // return find(s.getHomework().begin(), s.getHomework().end(), 0) == s.getHomework().end();

    // 만약 getter가 없다면, 아래처럼 Student_info.h에 추가 필요:
    // const vector<double>& getHomework() const { return homework; }

    return find(s.getHomework().begin(), s.getHomework().end(), 0) == s.getHomework().end();
}

vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> fails;
	vector<Student_info>::iterator iter = students.begin();
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fails.push_back(*iter);
			iter = students.erase(iter);
		} else {
			++iter;
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
		} else {
			++iter;
		}
	}
	return fails;
}



