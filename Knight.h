#pragma once
#include "ChessPiece.h"
#include <string>
using std::string;

class Knight: public ChessPiece
{
    public:
        Knight(float x, float y, string i);
        void move();
};