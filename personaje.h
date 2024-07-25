#ifndef PersonajeCLASS_H
#define PersonajeCLASS_H
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "player.h"
#include <memory>

using namespace std;
using namespace sf;

//Implementation of make_unique in C++11 metaprogramacion with smart pointers
// template<typename T, typename... Args>
// std::shared_ptr<T> make_unique(Args&&... args) {
//     return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
// }

//Class Personaje
class Personaje {

private:

	string type;
	string advantage1;
	string advantage2;
	string resistance1;
	string resistance2;
	string resistance3;
	float damageattack;
	float health;
	string name;
	//sf::
	Texture skin;
	unsigned int typeofplayer;
public:

	//The Observer
	Player p1;

	RectangleShape player;

	//Constructors
	Personaje() {
	}

	Personaje(float health, float damageattack, string type, string advantage1, string advantage2, string resistance1, string resistance2, string resistance3, string name) {
		this->type = type;
		this->advantage1 = advantage1;
		this->advantage2 = advantage2;
		this->health = health;
		this->damageattack = damageattack;
		this->name = name;

	}
	//Constructor with name and typeofplayer(1 or 2)
	Personaje(string name, int typeofplayer) {
		this->name = name;
		this->typeofplayer = typeofplayer;

		/*float posx, posy;
		if(typeofplayer==1) posx = 400.0f;
		if(typeofplayer==2) posx = 1250.0;*/

		shared_ptr<float> posx = make_shared<float>(400.0f);

		if (typeofplayer == 2)
			*posx = 1250.0f;


		if (name == "Chainsaw-man") {
			this->type = "Hielo";
			this->advantage1 = "Hielo";
			this->advantage2 = "Magia";
			this->resistance1 = "Lucha";
			this->resistance2 = "Lucha";
			this->resistance3 = "Ground";
			this->health = 393;
			this->damageattack = 55;
			this->skin.loadFromFile("Images/chainsaw-man.png");
			this->player.setSize(Vector2f(300.0f, 400.0f));
			this->player.setTexture(&skin);
			this->player.setPosition(*posx, 560.0f);
			this->p1.complete(&skin, Vector2u(4, 6), 0.2f, typeofplayer, 10.f * 0.15);
		}
		else if (name == "Gun-devil") {
			this->type = "Ground";
			this->advantage1 = "Ice";
			this->advantage2 = "Mage";
			this->resistance1 = "Electric";
			this->resistance2 = "Phisical";
			this->resistance3 = "Rock";
			this->health = 465;
			this->damageattack = 53;
			this->skin.loadFromFile("Images/gun-devil.png");
			this->player.setSize(Vector2f(300.0f, 400.0f));
			this->player.setTexture(&skin);
			this->player.setPosition(*posx, 560.0f);
			this->p1.complete(&skin, Vector2u(4, 6), 0.2f, typeofplayer, 10.f * 0.15);

		}
		else if (name == "Makima") {
			this->type = "Ground";
			this->advantage1 = "";
			this->advantage2 = "Fire";
			this->resistance1 = "Electric";
			this->resistance2 = "Poison";
			this->resistance3 = "Rock";
			this->health = 465;
			this->damageattack = 53;
			this->skin.loadFromFile("Images/MAKIMA.png");
			this->player.setSize(Vector2f(300.0f, 400.0f));
			this->player.setTexture(&skin);
			this->player.setPosition(*posx, 560.0f);
			this->p1.complete(&skin, Vector2u(4, 6), 0.2f, typeofplayer, 10.f * 0.15);

		}
		else if (name == "Power") {
			this->type = "Ground";
			this->advantage1 = "Electric";
			this->advantage2 = "Fire";
			this->resistance1 = "Electric";
			this->resistance2 = "Poison";
			this->resistance3 = "Rock";
			this->health = 465;
			this->damageattack = 53;
			this->skin.loadFromFile("Images/POWER_.png");
			this->player.setSize(Vector2f(300.0f, 400.0f));
			this->player.setTexture(&skin);
			this->player.setPosition(*posx, 560.0f);
			this->p1.complete(&skin, Vector2u(4, 6), 0.2f, typeofplayer, 10.f * 0.15);
		}
	}


	//Getters

	float getDamageattack() {
		return damageattack;
	}

	float getHealth() {
		return health;
	}

	string getAdvantage1() {
		return advantage1;
	}

	string getAdvantage2() {
		return advantage2;
	}

	string getType() {
		return type;
	}

	string getName() {
		return name;
	}

	string getResistance1() {
		return resistance1;
	}

	string getResistance2() {
		return resistance2;
	}

	string getResistance3() {
		return resistance3;
	}

	Texture getTexture() {
		return this->skin;
	}

	RectangleShape getRectangleShape() {
		return this->player;
	}



	int getTypeOfPlayer() {
		return typeofplayer;
	}


	//Setters

	void setType(string type) {
		this->type = type;
	}

	void setDamageattack(float damageattack) {
		this->damageattack = damageattack;
	}

	void setHealth(float health) {
		this->health = health;
	}

	void setAdvantage1(string advantage1) {
		this->advantage1 = advantage1;
	}

	void setAdvantage2(string advantage2) {
		this->advantage2 = advantage2;
	}

	void setName(string name) {
		this->name = name;
	}

	void setResistance1() {
		this->resistance1 = resistance1;
	}

	void setResistance2() {
		this->resistance2 = resistance2;
	}

	void setResistance3() {
		this->resistance3 = resistance3;
	}
	//Functions

	void heal() {

		srand(time(NULL));
		float random_number = (rand() % 170) + 1;
		health += random_number;
		//cout<<"\nYour Personaje has gotten health. Your new Personaje's health is -> " <<health;

	}

	void attack(Personaje& p2) {

		//cout<<"\nYour First Personaje's health is: " <<p1.getHealth()<<endl;
		if (advantage1 == p2.getType() || advantage1 == p2.getType()) {

			//	cout<<"\nA Personaje is attacking with a CRITICAL ATTACK other Personaje! "<<endl;
			p2.health -= damageattack * 2;
			//	cout<<(p1.getDamageattack())*2<<" of DAMAGE!"<<endl;

		}

		else if (type == p2.getResistance1() || type == p2.getResistance2() || type == p2.getResistance3()) {
			//	cout<<"\nA Personaje is attacking other Personaje with a low attack"<<endl;
			p2.health -= damageattack / 2;
			//	cout<<(p1.getDamageattack())/2<<" of damage"<<endl;
		}

		else {

			//	cout<<"\nA Personaje is attacking other Personaje! "<<endl;
			p2.health -= damageattack;
			//	cout<<p1.getDamageattack()<<" of damage!"<<endl;

		}
		//cout<<"\nYour Second Personaje's health now is: " <<p2.getHealth()<<endl;


	}


};

#endif