#pragma once
#include "ChessPiece.h"
#include <string>
using std::string;

class Bishop: public ChessPiece
{
    public:
        Bishop(float x, float y, string i);
        void move();
};