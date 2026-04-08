#pragma once
//frame.h
//작성해주신 frame.h 헤더 파일은 여러 줄의 문자열(텍스트) 테두리에 액자(Frame) 모양의 장식을 만들어주는 프로그램의 '설계도(인터페이스)' 역할을 합니다.
#ifndef GUARD_frame_h
#define GUARD_frame_h

#include <vector>
#include <string>

using std::vector; using std::string;

string::size_type width(const vector<string>&); //문자열 벡터에서 가장 긴 문자열의 길이를 반환하는 함수
vector<string> frame(const vector<string>&); //문자열 벡터를 입력받는 함수

#endif 

