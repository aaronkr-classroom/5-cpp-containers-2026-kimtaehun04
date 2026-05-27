#pragma once
//grade.h

#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <list>
#include "Student_info.h"
#include <vector>


double grade(double mid, double fin, const std::vector<double>&);
double grade(double, double, double);
double grade(const Student_info&);

double fgrade(const Student_info&);
double pgrade(const Student_info&);
double did_all_hw(const Student_info&);

vector<Student_info> extract_fails(vector<Student_info>&);

#endif 
