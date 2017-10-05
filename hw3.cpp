#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

#define MaxiLength 3		//ÈçÏëÐÞ¸ÄÃÔ¹¬µÄ¹æ¸ñ£¬¿ÉÒÔÔÚ´ËÐÞ¸Ä
#define MiniLenght 0
#define NOTHING  0			//¶¨Òå²»Í¬ÀàÐÍµÄ·¿¼ä ´ËÎªÆÕÍ¨
#define MONSTER 1			//ÓÐmonsterÔÚµÄ·¿¼ä
#define PRINCESS 2			//ÓÐprincessÔÚµÄ·¿¼ä
#define EXIT 3				//³ö¿Ú
#define LOBBY 4				//¿ªÊ¼µã

void pause()				//Í£Ö¹
{
	getchar();
}

class Player				//Íæ¼Ò ¹²ÓÐÈý¸öÊôÐÔ Î»ÖÃ×ø±ê ºÍ ÊÇ·ñÕÒµ½¹«Ö÷
{
private:
	int x, y;				//Íæ¼ÒµÄ×ø±ê
	int withPrincess;		//ÊÇ·ñÕÒµ½¹«Ö÷
public:
	Player(int, int);		//³õÊ¼»¯Íæ¼ÒµÄÎ»ÖÃ
	~Player();				//Îö¹¹º¯Êý
	int isWithPrincess();	//ÊÇ·ñÒÑ¾­ÕÒµ½¹«Ö÷£¬Èç¹ûÕÒµ½·µ»Ø1
	void getPrincess();		//ÕÒµ½¹«Ö÷£¬iswithprincessÖÃ1
	int getX();				//ÏÖÔÚµÄxy×ø±ê
	int getY();
	void logIn();			//ÅÐ¶ÏÏÖÔÚµÄÎ»ÖÃÓÐÄÄÐ©·½Ïò¿ÉÒÔÒÆ¶¯,ÓÃup down west east ±íÊ¾
	int move(int, int);		//ÏòÄ³¸ö·½ÏòÒÆ¶¯
};

Player::Player(int PosX, int PosY):x(PosX), y(PosY), withPrincess(0) {};////³õÊ¼»¯Íæ¼ÒµÄÎ»ÖÃ
Player::~Player() {};
int Player::isWithPrincess()		//ÊÇ·ñÒÑ¾­ÕÒµ½¹«Ö÷£¬Èç¹ûÕÒµ½·µ»Ø1
{
	return withPrincess;
}
void Player::getPrincess()			//ÕÒµ½¹«Ö÷£¬iswithprincessÖÃ1
{
	withPrincess = 1;
}

int Player::getX()					//»ñµÃÍæ¼ÒÏÖÔÚµÄX×ø±ê
{
	return x;
}
int Player::getY()					//»ñµÃÍæ¼ÒÏÖÔÚµÄY×ø±ê
{
	return y;
}
void Player::logIn()		//ÅÐ¶ÏÏÖÔÚµÄÎ»ÖÃÓÐÄÄÐ©·½Ïò¿ÉÒÔÒÆ¶¯,²¢ÒÀ´ÎÊä³ö
{							//ÓÃup down west east ±íÊ¾
	string word = "";		//³õÊ¼»¯Îª¿Õ
	if (x > MiniLenght)
		word += "east, ";	//ÓÒÃæÈÔÓÐ¿ÕÎ»Ê±£¬¿ÉÒÔÏòÓÒ×ß
	if (y > MiniLenght)
		word += "up, ";	//ÉÏÃæÈÔÓÐ¿ÕÎ»Ê±£¬¿ÉÒÔÏòÉÏ×ß
	if (x < MaxiLength-1)			
		word += "west, ";	//×óÃæÈÔÓÐ¿ÕÎ»Ê±£¬¿ÉÒÔÏò×ó×ß
	if (y < MaxiLength-1)			
		word += "down, ";	//ÏÂÃæÈÔÓÐ¿ÕÎ»Ê±£¬¿ÉÒÔÏòÏÂ×ß

	cout << "Please choose from: " << word << "\n" << endl;
}
int Player::move(int offsetX, int offsetY)
{
	if (x + offsetX < MiniLenght || x + offsetX>= MaxiLength ||
		y + offsetY < MiniLenght || y + offsetY>= MaxiLength)
		return 1;					//Èç¹ûÒÆ¶¯¹ýºó³¬³öÁË·¶Î§ Ôò·µ»Ø1
	x += offsetX;
	y += offsetY;
	return 0;
}

class Room {						//·¿¼ä¹²Ò»¸öÊôÐÔ£¬¼´×ÔÉíÀàÐÍ
private:
	int type;
public:
	Room();							//¹¹Ôìº¯Êý
	~Room();						//Îö¹¹º¯Êý
	int login(Player &);			//ÓÃÓÚÏÔÊ¾ÏÖÔÚµÄ×´Ì¬
	void setType(int);				//ÉèÖÃ¸ñ×ÓµÄÀàÐÍ
	int getType();					//·µ»Ø´Ë¸ñ×´Ì¬ 
};

Room::Room() :type(0) {};			//Ô­Ê¼×´Ì¬£¬Ã¿Ò»¸ñ×ÓµÄ³õÊ¼×´Ì¬Îª0£¬¼´ÎÞÌØÊâÇé¿ö
Room::~Room() {};					//Îö¹¹º¯Êý
int Room::login(Player & player)
{
	switch (type)
	{
	case MONSTER:
		cout << "¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡öMonster!¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö" << endl;
		cout << "¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡öYou die!¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö"<<endl;
		return 1;
		break;
	case PRINCESS:
		if(!player.isWithPrincess())
		cout << "¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡öYou find the princess!¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö" << endl;
		player.getPrincess();
		break;
	case EXIT:
		if (player.isWithPrincess())
		{
			cout << "¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡öYou win!¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö" << endl;
			return 1;
		}
		else
			cout << "¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡öYou are at the exit!¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö\n¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡öPlease find the princess first!¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö" << endl;
		break;
	case LOBBY:
		cout << "¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡öWelcome to lobby!¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö" << endl;
		break;
	case NOTHING:
		cout<<"¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡öContinue~¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö"<<endl;
		break;
	default:
		break;
	}
	return 0;
}

void Room::setType(int i)			//ÉèÖÃ·¿¼äÀàÐÍÎªÈýÖÖÖ®Ò»
{
	type = i;
}
int Room::getType()					//·µ»Ø·¿¼äÀàÐÍ
{
	return type;
}


class Castle
{
private:
	vector<vector<Room>> map;		//¶þÎ¬Êý×é µ±×÷³Ç±¤µÄ·¿¼ä
	int size;
	void RandomChoose(int);
public:
	Castle();
	~Castle();
	void gaming();					//±£³ÖÓÎÏ·½øÐÐÖÐµÄÑ­»·×´Ì¬Ö±µ½Ê¤Àû»òÓöµ½¹ÖÊÞ
};

Castle::Castle()
{
	srand((unsigned int)(time(NULL)));
	map.resize(MaxiLength);			//ÉèÖÃÃÔ¹¬µÄ´óÐ¡
	for (vector<vector<Room>> ::iterator ri = map.begin(); ri != map.end(); ri++)
	{
		for (int i = 0; i < MaxiLength; i++)	//Ë³ÐòÎª[0][0] [0][1] [0][2] [1][0] [1][1]... 
		{
			Room room;
			ri->push_back(room);
		}
	}
	map[1][1].setType(LOBBY);			//¿ªÊ¼µÄÎ»ÖÃÉè¶¨Îªlobby
	RandomChoose(MONSTER);				//Ëæ»úÖ¸¶¨Ò»¸ö²»Îªprincess¡¢exitºÍlobbyµÄ¸ñ×ÓÎªmonster
	RandomChoose(PRINCESS);				//Ëæ»úÖ¸¶¨Ò»¸ö²»Îªmonster¡¢exitºÍlobbyµÄ¸ñ×ÓÎªprincess
	RandomChoose(EXIT);					//Ëæ»úÖ¸¶¨Ò»¸ö²»Îªprincess¡¢monsterºÍlobbyµÄ¸ñ×ÓÎªexit
}

Castle::~Castle() {};
void Castle::RandomChoose(int type)
{
	while (1)
	{
		int x = rand() % MaxiLength;		//È¡Ëæ»úÊý£¬¶Ô×î´ó·½¸ñÊýÇóÄ££¬Ö®ºó×÷ÎªxµÄ×ø±ê
		int y = rand() % MaxiLength;		//È¡Ëæ»úÊý£¬¶Ô×î´ó·½¸ñÊýÇóÄ££¬Ö®ºó×÷ÎªyµÄ×ø±ê
		if (map[x][y].getType() == NOTHING)	//Èç¹û´Ë¸ñ»¹Î´ÓÐ¹¦ÄÜ
		{
			map[x][y].setType(type);		//¸³Óè¹¦ÄÜ
			break;
		}
	}
}

void Castle::gaming()
{
	Player player(1, 1);
	while (1)
	{
		int x = player.getX();
		int y = player.getY();
		if (map[x][y].login(player)==1)			//Óöµ½monsterÊ±»á·µ»Ø1
		{
			cout << "¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡öGame over!¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö" << endl;
			pause();
			return;
		}
		player.logIn();							//Êä³öÏÖÔÚ¿ÉÄÜµÄ·½Ïò
		int offsetX = 0, offsetY = 0;			//ÔË¶¯·½Ïò³õÊ¼»¯ÎªÁã
		while (1)
		{
			cout << "Input the command:" << endl;
			string go, pos;
			cin >> go >> pos;
			if (go != "go")
			{
				cout << "Invalid command!" << endl;
				continue;
			}
			if (pos == "east")						//Ïò¶«×ßµÈÐ§ÓÚXÖµ¼õÒ»
				offsetX = -1;
			else if (pos == "west")					//ÏòÎ÷×ßµÈÐ§ÓÚXÖµ¼ÓÒ»
				offsetX = 1;
			else if (pos == "up")					//ÏòÉÏ×ßµÈÐ§ÓÚyÖµ¼õÒ»
				offsetY = -1;
			else if (pos == "down")					//ÏòÏÂ×ßµÈÐ§ÓÚyÖµ¼ÓÒ»
				offsetY = 1;
			if (player.move(offsetX, offsetY))		//ÅÐ¶ÏÔË¶¯¹ýºóÊÇ·ñ»¹ÔÚÃÔ¹¬µÄ¸ñ×Ó·¶Î§ÄÚ
			{
				cout << "Invalid move!" << endl;
				continue;
			}
			break;
		}
	}
}


int main()
{
	Castle castle;
	castle.gaming();
	pause();
	return 0;
}
