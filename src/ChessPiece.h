#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using std::string;

class ChessPiece
{
    protected:   
        float posX;
        float posY;
        string image;

    public:
        ChessPiece(float x, float y, string i); 
        void make(sf::RenderWindow &window);
};