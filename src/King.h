#pragma once
#include "ChessPiece.h"
#include <string>
using std::string;

class King: public ChessPiece
{
    public:
        King(float x, float y, string i);
        void move();
};