#pragma once
#include <SFML/Graphics.hpp>

class ChessGame
{
    Pawn *pawn;

    public:
        ChessGame()
        void renderWindow();
        void setup();
        void display();
}