#include <iostream>

//수도코드
//맵 초기화()
// 오브젝트
// enum Object
// {
//		OBJ_SPACE, 0
//		OBJ_WALL,  1
// }
// while()
//{
//		그리기()
//		if (게임종료())
//			break;
//			입력처리
//{

const char STAGE_DATA[] = "\
########\n\
# .. p #\n\
#      #\n\
########";

const int STAGE_WIDTH{ 8 };
const int STAGE_HEIGHT{ 5 };

enum Object
{
	OBJ_SPACE,
	OBJ_WALL,
	OBJ_GOAL,
	OBJ_BLOCK,
	OBJ_BLOCK_ON_GOAL,
	OBJ_PLAYER_ON_GOAL,

	OBJ_MAX
};

void Initialize(Object *stage, int w, int h, const char *stageData);
void Draw(const Object *stage, int w, int h);
void Update(Object *stage, char input, int w, int h);
bool IsClear(const Object*stage, int w, int h);

int main()
{
	Object *stage = new Object[STAGE_WIDTH * STAGE_HEIGHT];

	Initialize(stage, STAGE_WIDTH, STAGE_HEIGHT, STAGE_DATA);

	while (true)
	{
		Draw(stage, STAGE_WIDTH, STAGE_HEIGHT);

		if (IsClear(stage, STAGE_WIDTH, STAGE_HEIGHT))
		{
			std::cout << std::endl << "CLEAR!!!" << std::endl;
			break;
		}
	}

	char input{};
	std::cout << "W : up, A : left, S : down, D :right, input : ";
	std::cin >> input;

	Update(stage, input, STAGE_WIDTH, STAGE_HEIGHT);

	std::cout << "Check";
}