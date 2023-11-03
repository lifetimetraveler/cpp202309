#include<iostream>//주석 처리된 라인은 소수점까지 나오도록 해봤습니다.
using namespace std;

int ccc;//섭씨 온도를 받기 위한 변수 선언
//int b;
//double cal(double a)
//{
//	return (a * 9 / 5) + 32;
//}
int main()
{
	//cin >> b;
	cin >> ccc;//섭씨온도 입력
	cout << "섭씨온도:" << ccc <<endl;//결과 출력
	cout << "화씨온도 = ";
	cout << (ccc*9/5)+32 << endl;//(섭씨온도°C * 9 / 5) + 32 = 화씨온도°F
	//cout << cal(b) << endl;
	return 0;

}
//소수점까지 나오게 하고 싶어서 함수를 써봤습니다.
//그런데 double반환형 함수에 double 매개변수를 쓰면 소수점도 나오는데 int매개변수를 넣으면 소수점까지 나오지 않았습니다.
//알고보니 int형을 넣으면 정수 형태로 계산을 해서 나눗셈을 하는 과정에서 차이가 발생하는 것이였습니다.
//static_cast<원하는자료형>(그 대상)을 써서 double형으로 계산할 수 있음을 알았지만, 저의 이해를 넘는 부분이여서 매개변수를 double로 바꾸는 것이 더 합리적임을 알았습니다.

//애초에 함수 없이 ccc변수를 double로 선언하면 소수점 계산도 가능함을 알게 되었습니다.


