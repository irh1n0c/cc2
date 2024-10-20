#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "personaje.h"


class Player {
private:
	sf::RectangleShape body;
	float movementSpeed;
	int row;
	Animation animation;
	int typeofplayer;



public:
	int cont = 0;
	int cont2 = 0;

	Player() {
	}


	void complete(Texture* texture, Vector2u imageCount, float switchTime, int typeofplayer,float movementSpeed) {
		this->typeofplayer = typeofplayer;
		this->movementSpeed = movementSpeed;
		animation.complete(texture, imageCount, switchTime);

		if (typeofplayer == 1) {
			row = 1;
			body.setSize(sf::Vector2f(300.0f, 400.0f));

			body.setPosition(200.0f, 260.0f);
			body.setTexture(texture);
		}

		if (typeofplayer == 2) {
			row = 0;
			body.setSize(sf::Vector2f(300.0f, 400.0f));
			// body.setPosition(1250.0f,560.0f);
			body.setPosition(800.0f, 260.0f);
			body.setTexture(texture);
		}

	}

	~Player() {
	}



	void Update(float deltaTime) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && typeofplayer == 1)
		{
			this->body.move(-this->movementSpeed, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && typeofplayer == 1)
		{
			this->body.move(this->movementSpeed, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && typeofplayer == 2)
		{
			this->body.move(-this->movementSpeed, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && typeofplayer == 2)
		{
			this->body.move(this->movementSpeed, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && typeofplayer == 1) {
			while (cont < 100) {
				row = 5;
				cont++;
				animation.Update(row, deltaTime);

				body.setTextureRect(animation.uvRect);
				return;
			}
			if (cont >= 100) {
				cont = 0;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && typeofplayer == 2) {
			while (cont < 100) {
				row = 2;
				cont++;
				animation.Update(row, deltaTime);
				body.setTextureRect(animation.uvRect);
				return;
			}
			if (cont >= 100) {
				cont = 0;
			}
		}



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && typeofplayer == 2) {
			while (cont < 100) {
				row = 4;
				cont++;
				animation.Update(row, deltaTime);
				body.setTextureRect(animation.uvRect);
				return;
			}
			if (cont >= 100) {
				cont = 0;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && typeofplayer == 1) {
			while (cont < 100) {
				row = 3;
				cont++;
				animation.Update(row, deltaTime);
				body.setTextureRect(animation.uvRect);
				return;
			}
			if (cont >= 100) {
				cont = 0;
			}
		}

		if (typeofplayer == 1) {
			row = 1;
			animation.Update(row, deltaTime);
			body.setTextureRect(animation.uvRect);
		}

		if (typeofplayer == 2) {
			row = 0;
			animation.Update(row, deltaTime);
			body.setTextureRect(animation.uvRect);
		}


	}

	void Draw(sf::RenderWindow& window) {
		window.draw(body);
	}


};

#endif