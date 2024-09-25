#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Character
{
public:
	Character(string name, float health, float defense)
	{
		this->name = name;
		if (health > 0)
			this->health = health;
		if (defense > 0)
			this->defense = defense;
	}

	float getHealth() const
	{
		return this->health;
	}

	float getDefense() const
	{
		return this->defense;
	}

	const string& getName() const
	{
		return this->name;
	}

	void setHealth(const float health)
	{
		this->health = health;
	}

	void setDefense(const float defense)
	{
		this->defense = defense;
	}

	void setName(const string& name)
	{
		this->name = name;
	}

protected:
	float health;
	float defense;
	string name;
};

class Enemy : public Character
{
public:
	Enemy(const string& name, float health, float defense, float damage) : Character(name, health, defense)
	{
		this->name = name;
		if (health > 0)
			this->health = health;
		if (defense > 0)
			this->defense = defense;
		this->damage = damage;
	}
	float getDamage() const
	{
		return this->damage;
	}

	void setDamage(const float damage)
	{
		this->damage = damage;
	}

private:
	float damage;
};

class Ability
{
public:
	Ability(const string& name, const float damage)
	{
		this->name = name;
		this->damage = damage;
	}

	float getDamage() const
	{
		return this->damage;
	}

	void setDamage(const float damage)
	{
		this->damage = damage;
	}

	const string& getName() const
	{
		return this->name;
	}

	void setName(const string& name)
	{
		this->name = name;
	}

private:
	string name;
	float damage;

};

class Player : public Character
{
public:
	Player(const string& name, float health, float defense, const vector<Ability>& abilities) : Character(name, health, defense)
	{
		this->name = name;
		if (health > 0)
			this->health = health;
		if (defense > 0)
			this->defense = defense;
		this->abilities = abilities;
	}

	Player& addAbility(const Ability& ability)
	{
	    this->abilities.push_back(ability);
		return *this;
	}

	const vector<Ability>& getAbilities() const
	{
		return this->abilities;
	}

private:
	vector<Ability> abilities;
};

class PlayerHelper
{
public:
	static float getTotalPlayerDamage(const Player& player)
	{
		vector<Ability> help_vector = player.getAbilities();
		int size = player.getAbilities().size();
		float total_damage = 0;
		for (int i = 0; i < size; i++)
		{
			total_damage += help_vector.at(i).getDamage();
		}
		return total_damage;
	}
};

class Arena
{
public:
	static int currentEnemyIndex;

	static bool fight(Player& player, vector<Enemy>& enemies)
	{
		int flag = 1;
		bool player_status = true, enemies_status = true;
		while (player_status && enemies_status)
		{
			if (flag)
			{
				//player attack
				PlayerHelper help;
				float total_damage=help.getTotalPlayerDamage(player);

				if (enemies.at(currentEnemyIndex).getDefense() > 0)
				{
					float defense_damage = enemies.at(currentEnemyIndex).getDefense() - total_damage;
					if (defense_damage > 0)
					{
						enemies.at(currentEnemyIndex).setDefense(defense_damage);
					}
					else
					{
						enemies.at(currentEnemyIndex).setDefense(0);
					}
				}
				else
				{

					if (enemies.at(currentEnemyIndex).getHealth() > 0)
					{
						float health_damage = enemies.at(currentEnemyIndex).getHealth() - total_damage;
						if (health_damage > 0)
						{
							enemies.at(currentEnemyIndex).setHealth(health_damage);
						}
						else
						{
							enemies.at(currentEnemyIndex).setHealth(0);
							currentEnemyIndex ++;
							if (currentEnemyIndex == enemies.size())
								enemies_status = false;
						}
					}
				}

				flag = 0;
			}
			else
			{
				//enemy atack

				if (player.getDefense() > 0)
				{
					float defense_damage = player.getDefense() - enemies.at(currentEnemyIndex).getDamage();
					if (defense_damage > 0)
					{
						player.setDefense(defense_damage);
					}
					else
					{
						player.setDefense(0);
					}
				}
				else
				{

					if (player.getHealth() > 0)
					{
						float health_damage = player.getHealth() - enemies.at(currentEnemyIndex).getDamage();
						if (health_damage > 0)
						{
							player.setHealth(health_damage);
						}
						else
						{
							player.setHealth(0);
							player_status = false;
						}
					}
				}
				flag = 1;
			}
		}

		bool result = (player_status) ? 1 : 0;

		return result;
	}

};

int Arena::currentEnemyIndex = 0;

int main()
{
	ifstream Input_file;
	Input_file.open("input.txt", ios::in);
	if (Input_file.is_open())
	{
		string player_line;
		getline(Input_file, player_line);
		istringstream player_input(player_line);
		string player_name, ability_name;
		float player_health, player_defense, ability_damage;
		player_input >> player_name >> player_health >> player_defense;

		vector<Ability> abilities;
		int i = 0;

		while (player_input >> ability_name >> ability_damage)
		{
			abilities.at(i) = Ability(ability_name, ability_damage);
			i++;
		}

		Player player (player_name, player_health, player_defense, abilities);

		string enemy_line,enemy_name;
		float enemy_defense, enemy_damage,enemy_health;
		vector<Enemy> enemies;
		while (getline(Input_file, enemy_line))
		{

			istringstream enemy_input(enemy_line);
			enemy_input >> enemy_name >> enemy_health >> enemy_defense >> enemy_damage;
			enemies.push_back(Enemy(enemy_name, enemy_health, enemy_defense, enemy_damage));
		}

		Arena arena;

		ofstream Output_file;
		Output_file.open("output.txt", ios::out);
		if (Output_file.is_open())
		{
			if (arena.fight(player,enemies))
			{
				cout<< "Player health: " << player.getHealth() << endl;
				cout<< "Player defense: " << player.getDefense() << endl;
			}
			else
			{
				cout << "Enemy " << arena.currentEnemyIndex << " Health: " << enemies[arena.currentEnemyIndex].getHealth() << endl;
				cout << "Enemy " << arena.currentEnemyIndex << " Defense: " << enemies[arena.currentEnemyIndex].getDefense() << endl;
			}
		}

		Input_file.close();
		Output_file.close();
	}

	return 0;
}