//main.cpp
//중간고사 , 기말고사, 그리고 과제 점수 몇개를 받고
//마지막 평균 결과 점수를 계산하는 프로그램.
#include <algorithm>
#include <fstream> // 파일 읽기 위해 필요
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <stdexcept>
#include <vector>


#include "grade.h"
#include "Student_info.h"
#include "median.h"
#include "split_str.h"

using namespace std;

int main() {
	//파일 스트림 만들고 "txt'파일 읽기
	ifstream student_info("students.txt");

	Student_info std;
	string::size_type maxlen = 0; //학생 이름의 최대 길이

	//모든 과제를 제출한 학생과 그렇지 않은 학생을 저장할 벡터
	vector<Student_info> did, didnt;
	
	// 학생 이름과 모든 점수를 읽어 저장하고
	//가장 긴 학생 이름을 찾음
	while (read(student_info, std)) {
		//cin을 사용하면 직접 사용자 입력만 받을 수 있다.
		//student_file은 ifstream 객체로 파일에서 데이터를 읽어올 수 있다.
		maxlen = max(maxlen, std.name.size());
		if (did_all_hw(std)) {
			did.push_back(std);
		} else {
			didnt.push_back(std);
			// 두 집단에 데이터가 있는지 각각 확인하여 분석할 필요가 있는지 확인
		if (did.empty()) {
			cout << "No student did all the homework!" << endl;
			return 1; //오류 코드 1 반환
		}
		if (didnt.empty()) {
			cout << "Every student did all the homework!" << endl;
		}
		return 0;
	}
}
