#include "PersonManager.h"
#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

PersonManager::PersonManager(int n) {
	size = n;
	p = new Person[size];
}
PersonManager::~PersonManager() {
	delete [] p;
}
void PersonManager::input() {
	string info[3];
	cout << "이름, 학번, 성적을 입력해주세요" << endl;
	for (int i = 0; i < size; i++) {
		cout << "학생" << i + 1 << ">>";
		cin >> info[0] >> info[1] >> info[2];
		p[i].set(info[0], info[1], stod(info[2]));
	}
	cout << endl;
}
void PersonManager::show() {
	cout << "모든 학생의 정보를 출력합니다. " << endl;
	for (int i = 0; i < size; i++) {
		cout << p[i].getName() << " " << p[i].getId() << " " << p[i].getGpa() << endl;
	}
	cout << endl;
}
void PersonManager::search() {
	cout << "검색할 학생의 학번을 입력하세요>> ";
	string sin;
	cin >> sin;
	for (int i = 0; i < size; i++) {
		if (p[i].getId() == sin) {
			cout << "이름 : " << p[i].getName() << " " << "성적 : " << p[i].getGpa() << endl;
			break;
		}
		else if (i != size - 1) {
			continue;
		}
		else {
			cout << "일치하는 학번이 없습니다!" << endl;
		}
	}
	cout << endl;
}
void PersonManager::sort() {
	Person t;
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (p[j].getGpa() < p[j + 1].getGpa()) {
				t = p[j];
				p[j] = p[j + 1];
				p[j + 1] = t;
			}
			if (p[j].getGpa() == p[j + 1].getGpa()) {
				if (p[j].getId() > p[j + 1].getId()) {
					t = p[j];
					p[j] = p[j + 1];
					p[j + 1] = t;
				}
			}
		}
	}
	show();

}