#pragma once
#include "ChessPiece.h"
#include <string>
using std::string;

class Pawn: public ChessPiece
{
    public:
        Pawn(float x, float y, string i);
        void move();
};