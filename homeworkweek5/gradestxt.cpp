#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

// 학생 정보를 담을 구조체
struct Student {
    string name;
    int scores[8];
    int total;
    double average;
    char grade;
};

// 평균 점수를 바탕으로 학점을 계산하는 함수
char calculateGrade(double avg) {
    if (avg >= 90.0) return 'A';
    else if (avg >= 80.0) return 'B';
    else if (avg >= 70.0) return 'C';
    else if (avg >= 60.0) return 'D';
    else return 'F';
}

int main() {
    // 제공된 원본 데이터
    string rawData = R"(Moo 100 100 100 100 100 100 100 100
Moore 75 85 77 59 0 85 75 89
Norman 57 78 73 66 78 70 88 89
Olson 89 86 70 90 55 73 80 84
Peerson 47 70 82 73 50 87 73 71
Russel 72 87 88 54 55 82 69 87
Thomas 90 96 99 99 100 81 97 97
Vaughn 81 97 99 67 40 90 70 96
Westerly 43 98 96 79 100 82 97 96
Baker 67 72 73 40 0 78 55 70
Davis 77 70 82 65 70 77 83 81
Edwards 77 72 73 80 90 93 75 90
Franklin 47 70 82 73 50 87 73 71
Jones 77 82 83 50 10 88 65 80
Harris 97 90 92 95 100 87 93 91
Smith 87 92 93 60 0 98 75 90
Carpenter 47 90 92 73 100 87 93 91
Fail1 45 55 65 80 90 70 65 60
Fail2 55 55 65 50 55 60 65 60
Fail3 35 25 0 0 55 60 65 75)";

    stringstream ss(rawData);
    vector<Student> students;
    Student temp;

    // 데이터 파싱 및 계산
    while (ss >> temp.name) {
        temp.total = 0;
        for (int i = 0; i < 8; ++i) {
            ss >> temp.scores[i];
            temp.total += temp.scores[i];
        }
        temp.average = static_cast<double>(temp.total) / 8.0;
        temp.grade = calculateGrade(temp.average);

        students.push_back(temp);
    }

    // 결과 출력 디자인 (헤더)
    cout << "=========================================================================================\n";
    cout << left << setw(12) << "Name"
        << setw(5) << "S1" << setw(5) << "S2" << setw(5) << "S3" << setw(5) << "S4"
        << setw(5) << "S5" << setw(5) << "S6" << setw(5) << "S7" << setw(5) << "S8"
        << setw(8) << "Total" << setw(10) << "Average" << "Grade\n";
    cout << "=========================================================================================\n";

    // 개별 학생 데이터 출력
    cout << fixed << setprecision(2); // 평균을 소수점 둘째 자리까지 표기
    for (const auto& student : students) {
        cout << left << setw(12) << student.name;
        for (int i = 0; i < 8; ++i) {
            cout << setw(5) << student.scores[i];
        }
        cout << setw(8) << student.total
            << setw(10) << student.average
            << student.grade << "\n";
    }
    cout << "=========================================================================================\n";

    return 0;
}
