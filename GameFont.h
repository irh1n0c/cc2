#ifndef GAME_FONT_H
#define GAME_FONT_H
#include <SFML/Graphics.hpp>

class GameFont {
public:
	GameFont() {} // Constructor privado para evitar instancias
    static sf::Font& getFont() {
        static sf::Font font; // Inicializar la fuente estática
        if (!font.loadFromFile("Fonts/Ancient Medium.ttf")) {
            // Manejar el fallo en la carga de la fuente
        }
        return font;
    }
    
};

#endif
//if(!font.loadFromFile("Fonts/Ancient Medium.ttf"))