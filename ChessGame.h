#pragma once
#include "global.h"
#include "ChessBoard.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include <SFML/Graphics.hpp>

class ChessGame
{
    sf::RenderWindow window;

    ChessBoard *board;

    Pawn* whitePawns[8];
    Pawn* blackPawns[8];

    Rook* whiteRooks[2];
    Rook* blackRooks[2];

    Knight* whiteKnights[2];
    Knight* blackKnights[2];

    Bishop* whiteBishops[2];
    Bishop* blackBishops[2];

    Queen* whiteQueen;
    Queen* blackQueen;

    King* whiteKing;
    King* blackKing;

    public:
        ChessGame();
        void display();
        ~ChessGame();
};