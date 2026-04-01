#pragma once
// Student_info.h

#ifndef GUARD_Studnet_info_h
#define GUARD_Studnet_info_h

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student_info {
	string name;
	double midterm, final;
	vector<double> homework;
};

// 함수 원형 정의
istream& read_(istream&, Student_info); // 한 학생의 정보 알기
istream& read(istream&, vector<double>&);
istream& read_hw(istream&, vector<double>&); // 모든 과제 점수 읽기
#endif
