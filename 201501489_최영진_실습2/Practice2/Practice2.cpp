// 201501489 최영진

#include <iostream>
#include "PersonManager.h"

using namespace std;

int main()
{
    int n;
    cout << "학생의 수를 입력하세요 : ";
    cin >> n;

    PersonManager x(n);
    x.input();
    x.show();
    x.search();
    x.sort();
}


