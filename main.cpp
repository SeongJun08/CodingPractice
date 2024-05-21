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
# oo   #\n\
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
	OBJ_PLAYER,
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
		system( "cls" );
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

	std::cout << " Practice" << std::endl;
}

void Initialize(Object *stage, int w, int h, const char *stageData)
{
	const char *p = stageData;
	int x{}, y{};

	while (*p != '\0')
	{
		Object o;

		switch (*p)
		{
			case ' ':
				o = OBJ_SPACE;
				break;

			case '#':
				o = OBJ_WALL;
				break;

			case '.':
				o = OBJ_GOAL;
				break;

			case 'o':
				o = OBJ_BLOCK;
				break;

			case 'O':
				o = OBJ_BLOCK_ON_GOAL;
				break;

			case 'p':
				o = OBJ_PLAYER;
				break;

			case 'P':
				o = OBJ_PLAYER_ON_GOAL;
				break;

			case '\n':
				x = 0;
				y++;
				o = OBJ_MAX;
				break;

			default:
				o = OBJ_MAX;
				break;
		}
		++p;

		if (o != OBJ_MAX)
		{
			stage[y * w + x] = o;
			x++;
		}
	}
}

void Draw(const Object *stage, int w, int h)
{
	static const char font[]{ ' ', '#', '.', 'o', 'O', 'p', 'P' };


	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			Object o = stage[y * w + x];
			
			std::cout << font[o];
		}

		std::cout << std::endl;
	}
}

void Update(Object *stage, char input, int w, int h)
{
	//이동 변화량(delta) 구하기
	int dx{}, dy{};
	switch (input)
	{
		case 'w':
			dy = -1;
			break;

		case 'a':
			dx = -1;
			break;

		case 's':
			dy = 1;
			break;

		case 'd':
			dx = 1;
			break;
	}

	//플레이어 위치 찾기
	int i{};
	for (i = 0; i < w * h; ++i)
	{
		if (stage[i] == OBJ_PLAYER || stage[i] == OBJ_PLAYER_ON_GOAL)
		{
			break;
		}
	}

	int x = i % w;
	int y = i / w;
	
	int tx = x + dx;
	int ty = y + dy;

	//예외
	if (tx < 0 || ty < 0 || tx >= w || ty >= h)
	{
		std::cout << "(tx,ty) Unexpected position!!!" << std::endl;
		return;
	}

	// (x,y)가 (tx,ty)로 이동할 수 있느냐
	int p = y * w + x;
	int tp = ty * w + tx;

	if (stage[tp] == OBJ_SPACE || stage[tp] == OBJ_GOAL)
	{
		stage[tp] = (stage[tp] == OBJ_GOAL) ? OBJ_PLAYER_ON_GOAL : OBJ_PLAYER;
		stage[p] = (stage[p] == OBJ_PLAYER_ON_GOAL) ? OBJ_GOAL : OBJ_SPACE;
	}
	else if (stage[tp] == OBJ_BLOCK || stage[tp] == OBJ_BLOCK_ON_GOAL)
	{
		int tx2 = tx + dx;
		int ty2 = ty + dy;
		if (tx2 < 0 || ty2 < 0 || tx2 >= w || ty >= h)
		{
			std::cout << "(tx2,ty2) Unexpected position!!!" << std::endl;
			return;
		}

		int tp2 = ty2 * w + tx2;
		if (stage[tp2] == OBJ_SPACE || stage[tp2] == OBJ_GOAL)
		{
			stage[p] = (stage[p] == OBJ_PLAYER_ON_GOAL) ? OBJ_GOAL : OBJ_SPACE;
			stage[tp] = (stage[tp] == OBJ_BLOCK_ON_GOAL) ? OBJ_PLAYER_ON_GOAL : OBJ_PLAYER;
			stage[tp2] = (stage[tp2] == OBJ_GOAL) ? OBJ_BLOCK_ON_GOAL : OBJ_BLOCK;
		}
	}


}

bool IsClear(const Object *stage, int w, int h)
{
	for (int i = 0; i < w * h; i++)
	{
		if (stage[i] == OBJ_BLOCK)
		{
			return false;
		}
	}
	return true;
}
