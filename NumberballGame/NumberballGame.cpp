#include <iostream>
#include <random>

int main()
{
	//숫자 야구 게임
	// 질문자 A가 3자리 숫자를 정하고 상대 B가 3자리 숫자를 맞추는 게임
	// 3자리 숫자는 0~9까지의 숫자를 한번만 사용한다
	// A는 B가 말한 숫자에 대해 다음과 같이 이야기해줘야한다
	// 스트라이크 : 자리수도 맞고 숫자도 맞음
	// 볼 : 숫자는 맞는데 자리수는 다름
	// 아웃 : 숫자도 자리수도 틀림
	// Ex) A : 390		->		B : 307		-> A : 1S 1B 1O


	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 9);

	int chosenNumbers[3];
	int count = 0;
	int numbercount = 3;
	//4자리 숫자야구를 할 수도 있으니 상수로 변환

	while (count < numbercount)
	{
		int randNumber = dis(gen);
		bool isDuplicate = false;

		for (int i = 0; i < count; i++)
		{
			if (chosenNumbers[i] == randNumber)
			{
				isDuplicate = true;
				break;
			}
		}

		if (!isDuplicate)
		{
			chosenNumbers[count] = randNumber;
			++count;
		}
	}

	for (int i = 0; i < numbercount; i++)
	{
		std::cout << chosenNumbers[i] << " ";
	}

	std::cout << "숫자 야구 게임에 오신 것을 환영합니다 이 게임은 3자리 숫자 야구 게임이며 연속된 숫자는 사용하실 수 없습니다 3자리 숫자 중 맞추신 숫자에 따라 다음과 같이 안내해드리고 있습니다\
		Strike : 숫자도 자리수도 맞다 Ball : 숫자는 맞으나 자리수가 틀리다 Out : 숫자도 자리수도 틀리다 재미있게 플레이해주세요";

	int strike = 0;
	int ball = 0;
	int out = 3;

	while (true)
	{
		int guessNum[3];
		for (int i = 0; i < numbercount; i++)
		{
			std::cin >> guessNum[i];
		}

		for (int i = 0; i < numbercount; i++)
		{
			for (int j = 0; j < numbercount; j++)
			{
				if (chosenNumbers[i] == guessNum[i])
				{
					++strike;
					break;
				}
				else if (chosenNumbers[i] == guessNum[j])
				{
					++ball;
					break;
				}
			}
		}
		out = out - (strike + ball);
		if (strike > 0)
		{
			std::cout << strike << "Strike" << " ";
		}
		if (ball > 0)
		{
			std::cout << ball << "Ball" << " ";
		}
		if (out > 0)
		{
			std::cout << out << "Out" << " ";
		}
		if (strike == 3)
		{
			std::cout << "Congratulation" << std::endl;
			break;
		}

		strike = 0;
		ball = 0;
		out = 3;
		
	}
}
