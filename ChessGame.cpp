#include "ChessGame.h"
#include <iostream>
using namespace std;

ChessGame::ChessGame()
{
    sf::RenderWindow window(sf::VideoMode({windowLength, windowWidth}), "Chess Game");
    window.setSize(sf::Vector2u(1080, 1080));

    for (int i = 0; i < 8; i++) 
    {
        whitePawns[i] = new Pawn(i * tileSize, 6 * tileSize, "src\\textures\\white_pawn.png");
        blackPawns[i] = new Pawn(i * tileSize, 1 * tileSize, "src\\textures\\black_pawn.png");
    }

    for (int i = 0; i < 2; i++) 
    {
        whiteRooks[i] = new Rook(i * 7 * tileSize, 7 * tileSize, "src\\textures\\white_rook.png");
        blackRooks[i] = new Rook(i * 7 * tileSize, 0 * tileSize, "src\\textures\\black_rook.png");

        whiteKnights[i] = new Knight((1 + i * 5) * tileSize, 7 * tileSize, "src\\textures\\white_knight.png");
        blackKnights[i] = new Knight((1 + i * 5) * tileSize, 0 * tileSize, "src\\textures\\black_knight.png");

        whiteBishops[i] = new Bishop((2 + i * 3) * tileSize, 7 * tileSize, "src\\textures\\white_bishop.png");
        blackBishops[i] = new Bishop((2 + i * 3) * tileSize, 0 * tileSize, "src\\textures\\black_bishop.png");
    }

    whiteQueen = new Queen(3 * tileSize, 7 * tileSize, "src\\textures\\white_queen.png");
    blackQueen = new Queen(3 * tileSize, 0 * tileSize, "src\\textures\\black_queen.png");

    whiteKing = new King(4 * tileSize, 7 * tileSize, "src\\textures\\white_king.png");
    blackKing = new King(4 * tileSize, 0 * tileSize, "src\\textures\\black_king.png");
}

void ChessGame::display()
{
    while (window.isOpen()) 
    {
        while (auto event = window.pollEvent()) 
        {
            if (event->is<sf::Event::Closed>()) 
            {
                window.close();
            }
        }

        window.clear();

        board->make(window);

        for (int i = 0; i < 8; i++)
        {
            whitePawns[i]->make(window);
            blackPawns[i]->make(window);
        }

        for (int i = 0; i < 2; i++)
        {
            whiteRooks[i]->make(window);
            blackRooks[i]->make(window);

            whiteKnights[i]->make(window);
            blackKnights[i]->make(window);

            whiteBishops[i]->make(window);
            blackBishops[i]->make(window);
        }

        whiteQueen->make(window);
        blackQueen->make(window);

        whiteKing->make(window);
        blackKing->make(window);

        window.display();
    }
}

ChessGame::~ChessGame()
{
    for (int i = 0; i < 8; i++)
    {
        delete whitePawns[i];
        delete blackPawns[i];
    }

    for (int i = 0; i < 2; i++)
    {
        delete whiteRooks[i];
        delete blackRooks[i];

        delete whiteKnights[i];
        delete blackKnights[i];

        delete whiteBishops[i];
        delete blackBishops[i];
    }

    delete whiteQueen;
    delete blackQueen;
    delete whiteKing;
    delete blackKing;
}


