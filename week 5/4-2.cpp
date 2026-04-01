//4-2.cpp
//C++에서 setw는 **"Set Width"**의 약자로, 콘솔에 데이터를 출력할 때 출력할 공간의 너비를 지정해 주는 I/O 조작자(Manipulator)입니다.
//주로 표를 그리거나 데이터를 일정한 간격으로 깔끔하게 정렬해서 출력하고 싶을 때 사용합니다.
#include <iostream>
#include <iomanip> //setw를 사용하기 위해 필요한 헤더 파일

using namespace std;

int main() {
	for (int i= 1; i <= 100; i++) {
		cout << setw(3) << i << " : " << setw(6) << i * i << endl;
	}
	return 0;
}
