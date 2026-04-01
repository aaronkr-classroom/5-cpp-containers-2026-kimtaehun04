#pragma once
//frame.h
#ifndef GUARD_frame_h
#define GUARD_frame_h

#include <vector>
#include <string>

using std::vector; using std::string;

string::size_type width(const vector<string>&); //문자열 벡터에서 가장 긴 문자열의 길이를 반환하는 함수
vector<string> frame(const vector<string>&); //문자열 벡터를 입력받는 함수

#endif 

