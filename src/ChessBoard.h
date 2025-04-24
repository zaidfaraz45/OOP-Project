#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using std::string;

class ChessBoard 
{
    string image;

    public:
        ChessBoard(string i);
        void make(sf::RenderWindow& window);
};