#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// 주인공의 데미지는 max(1, 공격력 - 몬스터의 방어력)
// HR은 전투 승리시 HP 3 회복
// RE는 주인공 사망시 소멸하고 시작 지점에서 부활
// CO는 모든 전투에서 첫 공격시 데미지 2배
// EX는 얻는 경험치 1.2배 소수점은 버림
// DX는 가시 데미지가 1로 고정, CO 장신구와 함께 착용할 경우 첫 공격시 3배
// HU는 보스 몬스터와 전투 시 체력 최대치로 회복, 보스의 첫 공격 데미지 0
// CU는 깡통 장신구
typedef struct
{
	int X, Y, LEVEL, HP, MAX_HP, ATT, SWORD, DEF, ARMOR, EXP, CNT;
	bool HR, RE, CO, EX, DX, HU, CU;
}PLAYER;

typedef struct
{
	string NAME;
	int ATT;
	int DEF;
	int HP;
	int MAX_HP;
	int EXP;
}MONSTER;

typedef struct
{
	char TYPE;
	int STATUS;
	string EFFECT;
}BOX;

typedef struct
{
	MONSTER monster;
	BOX item;
}OBJECT;

vector <vector<pair<char, OBJECT>>> map;
int origin_x, origin_y;
int turn = 0, monster_cnt = 0, box_cnt = 0, N, M;

void init_map()
{
	for (int i = 1; i < map.size(); i++)
	{
		for (int j = 1; j < map[i].size(); j++)
		{
			cin >> map[i][j].first;
			if (map[i][j].first == '@')
			{
				origin_x = j;
				origin_y = i;
			}
			else if (map[i][j].first == '&' || map[i][j].first == 'M')
				monster_cnt++;
			else if (map[i][j].first == 'B')
				box_cnt++;
		}
	}
}

void init_player(PLAYER& player, int x, int y)
{
	player.X = x; player.Y = y; player.LEVEL = 1; player.HP = 20; player.MAX_HP = 20; player.CNT = 0;
	player.ATT = 2; player.SWORD = 0; player.DEF = 2; player.ARMOR = 0; player.EXP = 0;
	player.HR = false; player.RE = false; player.CO = false; player.EX = false;
	player.DX = false; player.HU = false; player.CU = false;
}

MONSTER create_monster(string name, int att, int def, int hp, int exp)
{
	MONSTER temp;
	temp.NAME = name; temp.ATT = att;
	temp.DEF = def; temp.HP = hp; temp.MAX_HP = hp;  temp.EXP = exp;
	return temp;
}

BOX create_item(char type, int status, string effect)
{
	BOX temp;
	temp.TYPE = type;
	if (type == 'O')
		temp.EFFECT = effect;
	else
		temp.STATUS = status;
	return temp;
}

void move(PLAYER& player, char dir)
{
	if (dir == 'R')
	{
		if (player.X + 1 <= M && map[player.Y][player.X + 1].first != '#')
		{
			if (map[player.Y][player.X].first != '^')
				map[player.Y][player.X].first = '.';
			player.X++;
		}
	}
	else if (dir == 'L')
	{
		if (player.X - 1 > 0 && map[player.Y][player.X - 1].first != '#')
		{
			if (map[player.Y][player.X].first != '^')
				map[player.Y][player.X].first = '.';
			player.X--;
		}
	}
	else if (dir == 'U')
	{
		if (player.Y - 1 > 0 && map[player.Y - 1][player.X].first != '#')
		{
			if (map[player.Y][player.X].first != '^')
				map[player.Y][player.X].first = '.';
			player.Y--;
		}
	}
	else if (dir == 'D')
	{
		if (player.Y + 1 <= N && map[player.Y + 1][player.X].first != '#')
		{
			if (map[player.Y][player.X].first != '^')
				map[player.Y][player.X].first = '.';
			player.Y++;
		}
	}
}

void get_item(PLAYER& player, BOX& item)
{
	if (item.TYPE == 'O')
	{
		if (player.CNT != 4)
		{
			if (item.EFFECT == "HR")
			{
				if (player.HR)
					player.CNT--;
				player.HR = true;
			}
			else if (item.EFFECT == "RE")
			{
				if (player.RE)
					player.CNT--;
				player.RE = true;
			}
			else if (item.EFFECT == "CO")
			{
				if (player.CO)
					player.CNT--;
				player.CO = true;
			}
			else if (item.EFFECT == "EX")
			{
				if (player.EX)
					player.CNT--;
				player.EX = true;
			}
			else if (item.EFFECT == "DX")
			{
				if (player.DX)
					player.CNT--;
				player.DX = true;
			}
			else if (item.EFFECT == "HU")
			{
				if (player.HU)
					player.CNT--;
				player.HU = true;
			}
			else if (item.EFFECT == "CU")
			{
				if (player.CU)
					player.CNT--;
				player.CU = true;
			}
			player.CNT++;
		}
	}
	else if (item.TYPE == 'W')
		player.SWORD = item.STATUS;
	else if (item.TYPE == 'A')
		player.ARMOR = item.STATUS;
}

void fight(PLAYER& player, MONSTER& monster)
{
	if (map[player.Y][player.X].first == 'M' && player.HU)
		player.HP = player.MAX_HP;
	if (player.CO)
	{
		if (player.DX)
			monster.HP -= max(1, (player.ATT + player.SWORD)*3 - monster.DEF);
		else
			monster.HP -= max(1, (player.ATT + player.SWORD) * 2 - monster.DEF);
	}
	else
		monster.HP -= max(1, ((player.ATT + player.SWORD) - monster.DEF));
	if (monster.HP <= 0)
		return;
	int hit = monster.HP / max(1, (player.ATT + player.SWORD) - monster.DEF) + 1;
	if (monster.HP % (max(1, (player.ATT + player.SWORD) - monster.DEF)) == 0)
		hit--;
	if (player.HU && map[player.Y][player.X].first == 'M')
		hit--;
	if (hit > 0)
		player.HP -= (max(1, monster.ATT - (player.DEF+player.ARMOR)) * hit);
}

void ending(PLAYER& player, string credit)
{
	for (int i = 1; i < map.size(); i++)
	{
		for (int j = 1; j < map[i].size(); j++)
			cout << map[i][j].first;
		cout << '\n';
	}
	cout << "Passed Turns : " << turn << '\n';
	cout << "LV : " << player.LEVEL << '\n';
	cout << "HP : " << player.HP << '/' << player.MAX_HP << '\n';
	cout << "ATT : " << player.ATT << '+' << player.SWORD << '\n';
	cout << "DEF : " << player.DEF << '+' << player.ARMOR << '\n';
	cout << "EXP : " << player.EXP << '/' << player.LEVEL * 5 << '\n';
	cout << credit << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x, y, hp, att, def, exp, status;
	char type;
	string commend, name, effect;
	PLAYER player;
	cin >> N >> M;
	map = vector<vector<pair<char, OBJECT>>>(N + 1, vector<pair<char, OBJECT>>(M + 1));
	init_map();
	init_player(player, origin_x, origin_y);
	cin >> commend;
	for (int i = 0; i < monster_cnt; i++)
	{
		cin >> y >> x >> name >> att >> def >> hp >> exp;
		map[y][x].second.monster = create_monster(name, att, def, hp, exp);
	}
	for (int i = 0; i < box_cnt; i++)
	{
		cin >> y >> x >> type;
		if (type == 'O')
		{
			cin >> effect;
			map[y][x].second.item = create_item(type, 0, effect);
		}
		else
		{
			cin >> status;
			map[y][x].second.item = create_item(type, status, "");
		}
	}

	for (int i = 0; i < commend.size(); i++)
	{
		move(player, commend[i]);
		turn++;
		if (map[player.Y][player.X].first == 'B')
		{
			get_item(player, map[player.Y][player.X].second.item);
			map[player.Y][player.X].first = '@';
		}
		else if (map[player.Y][player.X].first == '&' || map[player.Y][player.X].first == 'M')
		{
			MONSTER m = map[player.Y][player.X].second.monster;
			fight(player, m);
			if (player.HP > 0)
			{
				if (player.EX)
					player.EXP += (int)(m.EXP * 1.2);
				else
					player.EXP += m.EXP;
				if (player.EXP >= player.LEVEL * 5)
				{
					player.LEVEL++;
					player.ATT += 2;
					player.DEF += 2;
					player.MAX_HP += 5;
					player.HP = player.MAX_HP;
					player.EXP = 0;
				}
				else
				{
					if (player.HR)
					{
						player.HP += 3;
						if (player.HP > player.MAX_HP)
							player.HP = player.MAX_HP;
					}
				}
				if (map[player.Y][player.X].first == 'M')
				{
					map[player.Y][player.X].first = '@';
					ending(player, "YOU WIN!");
					return 0;
				}
				else
					map[player.Y][player.X].first = '@';
			}
			else
			{
				if (player.RE)
				{
					player.RE = false;
					player.X = origin_x;
					player.Y = origin_y;
					player.HP = player.MAX_HP;
					m.HP = m.MAX_HP;
					map[player.Y][player.X].first = '@';
				}
				else
				{
					player.HP = 0;
					ending(player, "YOU HAVE BEEN KILLED BY " + m.NAME + "..");
					return 0;
				}
			}
		}
		else if (map[player.Y][player.X].first == '^')
		{
			if (player.DX)
				player.HP -= 1;
			else
				player.HP -= 5;
			if (player.HP <= 0)
			{
				if (player.RE)
				{
					player.RE = false;
					player.X = origin_x;
					player.Y = origin_y;
					player.HP = player.MAX_HP;
					map[player.Y][player.X].first = '@';
				}
				else
				{
					player.HP = 0;
					ending(player, "YOU HAVE BEEN KILLED BY SPIKE TRAP..");
					return 0;
				}
			}
		}
	}
	map[player.Y][player.X].first = '@';
	ending(player, "Press any key to continue.");
	return 0;
}