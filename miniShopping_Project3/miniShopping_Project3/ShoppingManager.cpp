#include "ShoppingManager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#include "Product.h"



ShoppingManager::ShoppingManager(const string fn)
{

	ifstream fin(fn);
	if (!fin) {
		cout << "파일을 열 수 없습니다." << endl;
	}
	else {
		int i = 0;
		string line;
		string token;
		vector <string> v;
		while (getline(fin,line)) {
			stringstream ss(line);
			getline(ss,token,';');
			v.push_back(token);
			getline(ss,token,'\n');
			v.push_back(token);
			Product p(v[0], stoi(v[1]));
			productList.push_back(p);
			v.clear();
		}
		
	}

}

void ShoppingManager::mainMenu()
{
	int choice;
	while (true) {
		cout << "<< INU 쇼핑에 오신 것을 환영합니다! >>" << endl
			<< "[1] 쇼핑 관리자 모드" << endl
			<< "[2] 고객 모드" << endl
			<< "[3] 종료" << endl;
		cout << "입력 : ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			managerMode();
			break;
		case 2:
			customerMode();
			break;
		case 3:
			return;
		default:
			cout << "잘못된 입력입니다.";
			break;
		}
	}
	
}

void ShoppingManager::managerMode()
{
	int pw;
	int select;
	cout << endl <<"관리자 비밀번호를 입력하세요(메인 화면으로 돌아가려면 -1 입력) : ";
	cin >> pw;
	cout << endl;
	if (pw == -1) {
		return;
	}
	else if (pw == 1234) {
		while (true) {
			cout << endl << "< 쇼핑 관리자 모드> " << endl;
			cout << "[1] 상품추가" << endl
				<< "[2] 상품삭제" << endl
				<< "[3] 모든 상품 출력" << endl
				<< "[4] 돌아가기" << endl;
			cout << "입력 : ";
			cin >> select;
			cout << endl;
			switch (select)
			{
			case 1:
				addProduct();
				cout << endl;
				break;
			case 2:
				deleteProduct();
				cout << endl;
				break;
			case 3:
				print(productList);
				cout << endl << "총 " << productList.size() << "가지의 상품" << endl;
				break;
			case 4:
				return;
			default:
				cout << "잘못된 입력입니다.";
				break;
			}
		}		
	}
	else {
		cout << "비밀번호가 틀립니다!"<< endl;
		managerMode();
	}
}

void ShoppingManager::customerMode()
{
	int choose;
	while (true) {
		cout << endl << "< 고객 모드 >" << endl;
		cout << "[1] 상품 보기" << endl
			<< "[2] 상품 검색" << endl
			<< "[3] 장바구니 모드" << endl
			<< "[4] 돌아가기" << endl;
		cout << "입력 : ";
		cin >> choose;
		cout << endl;
		switch (choose)
		{
		case 1:
			print(productList);
			cout << endl << "총 " << productList.size() << "가지의 상품" << endl;
			break;
		case 2:
			search();
			break;
		case 3 :
			cartMode();
			break;
		case 4 : 
			return;
		default:
			cout << "잘못된 입력입니다. " << endl;
			break;
		}
	}

}

void ShoppingManager::addProduct()
{
	Product pp("", 0);
	cout << "새로운 상품을 추가합니다. 상품 이름 입력 시 no를 입력하면 빠져나갑니다." << endl;
	cout << endl;
	while (true) {
		cin >> pp;
		if (pp.getName() != "no") {
			for (int i = 0; i < productList.size(); i++) {
				if (productList[i].getName() == pp.getName()) {
					cout << "이미 존재하는 상품입니다." << endl;
					cout << endl;
					break;
				}
				else if (i == productList.size() - 1) {
					productList.push_back(pp);
					cout << pp.getName() << "을(를) 목록에 등록했습니다." << endl;
					cout << endl;
					break;
				}
				else {
					continue;
				}
			}
		}
		else {
			cout << endl;
			return;
		}		
		continue;
	}

	
}

void ShoppingManager::deleteProduct()
{
	string dp;
	vector<Product>::iterator it;
	
	cout << "삭제하실 상품의 이름을 입력하세요 : ";
	cin.ignore();
	getline(cin,dp);
	for (it = productList.begin(); it != productList.end();it++) {
		Product n = *it;
		if (n.getName() == dp) {
			it = productList.erase(it);
			cout << n.getName() << "을(를) 삭제합니다. " << endl;
			return;
		}
		else if (it == productList.end() - 1) {
			cout << "입력하신 상품은 목록에 없습니다. " << endl;
			return;
		}
	}

}

void ShoppingManager::print(vector<Product> pList)
{
	for (int i = 0; i < pList.size(); i++) {
		cout << pList[i];
	}
}

void ShoppingManager::search()
{
	string sn;
	cout << "상품명을 입력하세요 : ";
	cin.ignore();
	getline(cin ,sn);
	for (int j = 0; j < productList.size(); j++) {
		if (productList[j].getName() == sn) {
			cout << productList[j] << endl;
			return;
		}
		else if (j == productList.size()-1) {
			cout << "입력하신 상품은 현재 등록되어 있지 않습니다." << endl;
			return;
		}
	}
}

void ShoppingManager::cartMode()
{
	vector<Product> cart;
	int cartin;
	while (true) {
		cout << endl << "< 장바구니 모드 >" << endl;
		cout << "[1] 상품보기" << endl
			<< "[2] 장바구니에 담기" << endl
			<< "[3] 장바구니 출력" << endl
			<< "[4] 계산하기" << endl;
		cout << "입력 : ";
		cin >> cartin;
		cout << endl;
		switch (cartin)
		{
		case 1:
			print(productList);
			cout << endl << "총 " << productList.size() << "가지의 상품" << endl;
			break;
		case 2:
		{
			addToCart(cart);
			break;
		}
		case 3 :
			print(cart);
			cout << endl << "총 " << cart.size()<<"가지의 상품" << endl;
			break;
		case 4 :
			calculate(cart);
			cout << "장바구니 모드를 종료합니다." << endl << endl;
			return;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}

}

vector<Product> ShoppingManager::addToCart(vector<Product>&cart)
{
	string cn;
	int cprice;
	int yang;
	cin.ignore();
	while (true) {
		cout << "구매하고자 하는 상품 이름 입력(장바구니 담기 종료는 no 입력) : ";		
		getline(cin, cn);
		if (cn != "no") {
			for (int j = 0; j < productList.size(); j++) {
				if (productList[j].getName() == cn) {
					cout << "담을 수량 입력(" << cn << "의 남은 재고 : "
						<< productList[j].getStock() << ") : ";
					cin >> yang;
					cin.ignore();
					cprice = productList[j].getPrice();
					if (yang <= productList[j].getStock()) {
						Product cp(cn,cprice,yang);
						if (cart.size() != 0) {
							for (int q = 0; q < cart.size(); q++) {
								if (cart[q].getName() == cn) {
									cart[q].setCartStock(yang);
									break;
								}
								else if (q == cart.size() - 1) {
									cart.push_back(cp);
									break;
								}
							}
						}
						else {
							cart.push_back(cp);
						}

						productList[j].setStock(yang);
						cout << cn << " " << yang << " 개를 장바구니에 담았습니다." << endl;
						cout << endl;
					}
					else {
						cout << "담을 수 있는 수량을 초과했습니다. " << endl << endl;
					}
					break;
				}
				else if (j == productList.size() - 1) {
					cout << "입력하신 상품은 현재 등록되어 있지 않습니다." << endl;
					break;
				}
			}
		}
		else {
			break;
		}
	}
	return vector<Product>();
}

void ShoppingManager::calculate(const vector<Product> &cart)
{
	int sum = 0;
	if (cart.size() != 0) {
		for (int k = 0; k < cart.size(); k++) {
			int gap = 0;
			cout << cart[k];
			gap += cart[k].getPrice() * cart[k].getStock();
			sum += gap;
		}
		cout << endl << "총 " << cart.size() << "가지의 상품" << endl;
		cout << "총 " << sum << "원 결제 완료되었습니다." << endl;
	}
	else {
		cout << "장바구니에 아무것도 없습니다." << endl;
		return;
	}
}
