#ifndef SELECCION2_H
#define SELECCION2_H

#include "menu.h"
#include "GameFont.h"
#include <SFML/Graphics.hpp>

class Selection2:public Menu{
	
	public:
		Selection2(float width, float height) : Menu(width, height){
			font = GameFont::getFont();

			menu[0].setFont(font);
			menu[0].setFillColor(sf::Color::Blue);
			menu[0].setString("Ken");
			menu[0].setPosition(sf::Vector2f(1200, CalculateHeight1(height, 1)));
			menu[0].setCharacterSize(100);
			menu[0].setCharacterSize(32);
			
			menu[1].setFont(font);
			menu[1].setFillColor(sf::Color::White);
			menu[1].setString("Gun-devil");
			menu[1].setPosition(sf::Vector2f(1200, CalculateHeight1(height, 2)));
			menu[1].setCharacterSize(100);
			menu[1].setCharacterSize(32);

			menu[2].setFont(font);
			menu[2].setFillColor(sf::Color::White);
			menu[2].setString("Zena");
			menu[2].setPosition(sf::Vector2f(1200, CalculateHeight1(height, 3)));
			menu[2].setCharacterSize(100);
			menu[2].setCharacterSize(32);

			menu[3].setFont(font);
			menu[3].setFillColor(sf::Color::White);
			menu[3].setString("Power");
			menu[3].setPosition(sf::Vector2f(1200, CalculateHeight1(height, 4)));
			menu[3].setCharacterSize(100);
			menu[3].setCharacterSize(32);	
		}
		
		void draw(sf::RenderWindow &window){
			for(int i=0; i< MAX_NUMBER_OF_PERSONAJES; i++){
				window.draw(menu[i]);
			}	
		}
		
		void MoveDown(){
			if(selectedItemIndex + 1 < MAX_NUMBER_OF_PERSONAJES){
				menu[selectedItemIndex].setFillColor(sf::Color::White);
				selectedItemIndex++;
				menu[selectedItemIndex].setFillColor(sf::Color::Blue);
			}
		}
		
		void MoveUp(){
			if(selectedItemIndex - 1 >= 0){
				menu[selectedItemIndex].setFillColor(sf::Color::White);
				selectedItemIndex--;
				menu[selectedItemIndex].setFillColor(sf::Color::Blue);
			}
		}
		
		
};

#endif
