#pragma once
#include "ChessPiece.h"
#include <string>
using std::string;

class Rook: public ChessPiece
{
    public:
        Rook(float x, float y, string i);
        void move();
};