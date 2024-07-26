#pragma once
#include <SFML/Audio.hpp>
#include <string>

class SoundEffects {
protected:
    sf::SoundBuffer buffer;
    sf::Sound sound;

    // Pasos abstractos
    virtual void loadSound() = 0;
    virtual void playSound() = 0;

    // Hook (método gancho) - puede ser sobrescrito por las subclases
    virtual void adjustVolume() {
        sound.setVolume(100); 
    }

public:
    // El método plantilla
    void playSoundEffect() {
        loadSound();
        adjustVolume();
        playSound();
    }
};

class AttackSoundEffect : public SoundEffects {
protected:
    void loadSound() override {
        if (!buffer.loadFromFile("Audios/stone_ok.ogg")) {
           throw std::runtime_error("Error en audio");
        }
        sound.setBuffer(buffer);
    }

    void playSound() override {
        sound.play();
    }

  
};

class HealSoundEffect : public SoundEffects {
protected:
    void loadSound() override {
        if (!buffer.loadFromFile("Audios/stone_ok.ogg")) {
            throw std::runtime_error("Error en audio");
        }
        sound.setBuffer(buffer);
    }

    void playSound() override {
        sound.play();
    }

    void adjustVolume() override {
        sound.setVolume(80); 
    }
};