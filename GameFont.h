#ifndef GAME_FONT_H
#define GAME_FONT_H

#include <SFML/Graphics.hpp>

class GameFont {
private:
    GameFont() {} // Constructor privado para evitar instancias
    GameFont(const GameFont&) = delete; 
    GameFont& operator=(const GameFont&) = delete; // Sobrecargamos el operador "=" de asignación

public:
    static sf::Font& getFont() {
        static sf::Font font; // Inicializar la fuente 
        if (!font.loadFromFile("Fonts/Ancient Medium.ttf")) {
            // Manejar el fallo en la carga de la fuente
            throw std::runtime_error("Failed to load font");
        }
        return font;
    }
};

#endif