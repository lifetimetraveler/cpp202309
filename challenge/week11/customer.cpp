#include<iostream>
#include<string>
#include<vector>//벡터를 사용하기 위해 
using namespace std;

int main()
{
	int maxPeople = 0;//총인원수 
	cout << "총 고객의 수를 입력하라: ";
	cin >> maxPeople;

	//이름과 나이를 받을 벡터를 선언
	vector<string>names;
	vector<int>ages;

	//벡터에 넣을 값을 위한 스트링과 인트형 변수 선언
	string name;
	int age;

	//push_back을사용하지 않고 바로 names[a]와 같이 접근하였더니 없는 벡터라 에러.

	for (int a = 0; a < maxPeople; a++)//총 인원 수 만큼 아래 구문들을 반복
	{
		cout << "이름을 입력하세요: ";//이름 입력받고, 나이 입력 받음
		cin >> name;                   //입력받은 값들을 벡터에 넣어준다.
			names.push_back(name);
		cout << "나이를 입력하세요: ";
		cin >> age;
		ages.push_back(age);
	}

	int ageThreshold;//나이 입력받기 위한 변수
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요 : ";
	cin >> ageThreshold;//나이를 입력받음

	cout << ageThreshold << "세 이상인 고객들:\n";
	int k = 0;
		for (int a = 0; a < maxPeople; a++)//인원 수만큼 아래 구문을 반복
		{
			if (ages[a] > ageThreshold)//배열을 하나씩 보면서 입력한 나이보다 많으면
			{
				cout << names[a]<<" \n";//그 배열과 인덱스 숫자가 같은 이름을 출력함
				k++;//이 if문이 실행되면 1을 올려서 몇명이 더 기준보다 높은지 체크
			}
			
		}
		if (k == 0)//k가 0일 경우는 위의 if문이 실행되지 않았음을 뜻함. 따라서, 아무도 없다는것을 뜻함
		{
			cout <<ageThreshold<< "세 보다 나이가 많은 고객이 존재 하지 않습니다.";//그럴 경우에 이것을 출력
		}


	return 0;
}