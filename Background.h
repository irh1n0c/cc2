#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "DynamicArray.h"
#include <memory>



namespace std {
    template<class T> struct _Unique_if {
        typedef unique_ptr<T> _Single_object;
    };

    template<class T> struct _Unique_if<T[]> {
        typedef unique_ptr<T[]> _Unknown_bound;
    };

    template<class T, size_t N> struct _Unique_if<T[N]> {
        typedef void _Known_bound;
    };

    template<class T, class... Args>
        typename _Unique_if<T>::_Single_object
        make_unique(Args&&... args) {
            return unique_ptr<T>(new T(std::forward<Args>(args)...));
        }

    template<class T>
        typename _Unique_if<T>::_Unknown_bound
        make_unique(size_t n) {
            typedef typename remove_extent<T>::type U;
            return unique_ptr<T>(new U[n]());
        }

    template<class T, class... Args>
        typename _Unique_if<T>::_Known_bound
        make_unique(Args&&...) = delete;
}

class Create_Background {
public:
    Create_Background(sf::Sprite background1, sf::Sprite background2, sf::Sprite background3) {
        backgrounds = std::make_unique<sf::Sprite[]>(3);
        backgrounds[0] = std::move(background1);
        backgrounds[1] = std::move(background2);
        backgrounds[2] = std::move(background3);
    }

private:
    std::unique_ptr<sf::Sprite[]> backgrounds;
};

#endif
