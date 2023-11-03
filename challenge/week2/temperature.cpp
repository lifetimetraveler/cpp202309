#include<iostream>
using namespace std;

int main()
{
	//화씨 온도를 받기 위한 변수. 소수점 계산을 위하여 double 사용
	double fire;

	//화씨 온도를 입력받기 위한 변수
	cout << "화씨온도 = ";
	cin >> fire;
	
	//화씨온도를 출력하고 섭씨온도를 계산하여 출력한다.
	cout << "화씨온도:" << fire<<endl;
	cout << "섭씨온도 = " << (5.0 / 9.0) * (fire - 32) << endl;
	return 0;
}