#pragma once
#include "ChessPiece.h"
#include <string>
using std::string;

class Queen: public ChessPiece
{
    public:
        Queen(float x, float y, string i);
        void move();
};