#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

const int windowLength = 1000;
const int windowWidth = 1000;
const float tileSize = windowWidth / 8.0f;

class chessBoard 
{
    string image;

public:
    chessBoard(string i) : image(i) {}

    void make(sf::RenderWindow& window)
    {
        sf::Texture texture(image);
        sf::Sprite sprite(texture);
        sprite.setPosition(sf::Vector2f(0, 0));

        window.draw(sprite);
    }
};

class ChessPiece
{
    protected:   
        float posX;
        float posY;
        string image;

    public:
        ChessPiece(float x, float y, string i): posX(x), posY(y), image(i) {}  

        void make(sf::RenderWindow &window)
        {  
            sf::Texture texture(image);
            sf::Sprite sprite(texture);
            sprite.setPosition(sf::Vector2f(posX + tileSize / 4, posY + tileSize / 4));
            float scaleX = tileSize / texture.getSize().x / 2;
            float scaleY = tileSize / texture.getSize().y / 2;
            sprite.setScale(sf::Vector2f(scaleX, scaleY));

            window.draw(sprite);
        }
};

class WhitePawn: public ChessPiece
{
    public:
        WhitePawn(float x, float y, string i): ChessPiece(x, y, i) {}
};

class BlackPawn: public ChessPiece
{
    public:
        BlackPawn(float x, float y, string i): ChessPiece(x, y, i) {}
};

class WhiteRook: public ChessPiece
{
    public:
        WhiteRook(float x, float y, string i): ChessPiece(x, y, i) {}
};

class BlackRook: public ChessPiece
{
    public:
        BlackRook(float x, float y, string i): ChessPiece(x, y, i) {}
};

class WhiteKnight: public ChessPiece
{
    public:
        WhiteKnight(float x, float y, string i): ChessPiece(x, y, i) {}
};

class BlackKnight: public ChessPiece
{
    public:
        BlackKnight(float x, float y, string i): ChessPiece(x, y, i) {}
};

class WhiteBishop: public ChessPiece
{
    public:
        WhiteBishop(float x, float y, string i): ChessPiece(x, y, i) {}
};

class BlackBishop: public ChessPiece
{
    public:
        BlackBishop(float x, float y, string i): ChessPiece(x, y, i) {}
};

class WhiteQueen: public ChessPiece
{
    public:
        WhiteQueen(float x, float y, string i): ChessPiece(x, y, i) {}
};

class BlackQueen: public ChessPiece
{
    public:
        BlackQueen(float x, float y, string i): ChessPiece(x, y, i) {}
};

class WhiteKing: public ChessPiece
{
    public:
        WhiteKing(float x, float y, string i): ChessPiece(x, y, i) {}
};

class BlackKing: public ChessPiece
{
    public:
        BlackKing(float x, float y, string i): ChessPiece(x, y, i) {}
};

int main() 
{
    sf::RenderWindow window(sf::VideoMode({windowLength, windowWidth}), "Chess Game");

    chessBoard board("chess_board.png");

    WhitePawn* whitePawns[8];
    BlackPawn* blackPawns[8];

    WhiteRook* whiteRooks[2];
    BlackRook* blackRooks[2];

    WhiteKnight* whiteKnights[2];
    BlackKnight* blackKnights[2];

    WhiteBishop* whiteBishops[2];
    BlackBishop* blackBishops[2];

    WhiteQueen* whiteQueen = new WhiteQueen(3 * tileSize, 7 * tileSize, "white_queen.png");
    BlackQueen* blackQueen = new BlackQueen(3 * tileSize, 0 * tileSize, "black_queen.png");

    WhiteKing* whiteKing = new WhiteKing(4 * tileSize, 7 * tileSize, "white_king.png");
    BlackKing* blackKing = new BlackKing(4 * tileSize, 0 * tileSize, "black_king.png");

    for (int i = 0; i < 8; i++)
    {
        whitePawns[i] = new WhitePawn(i * tileSize, 6 * tileSize, "white_pawn.png"); 
        blackPawns[i] = new BlackPawn(i * tileSize, 1 * tileSize, "black_pawn.png"); 
    }

    for (int i = 0; i < 2; i++)
    {
        whiteRooks[i] = new WhiteRook(i * 7 * tileSize, 7 * tileSize, "white_rook.png");
        blackRooks[i] = new BlackRook(i * 7 * tileSize, 0 * tileSize, "black_rook.png");

        whiteKnights[i] = new WhiteKnight((1 + i * 5) * tileSize, 7 * tileSize, "white_knight.png");
        blackKnights[i] = new BlackKnight((1 + i * 5) * tileSize, 0 * tileSize, "black_knight.png");

        whiteBishops[i] = new WhiteBishop((2 + i * 3) * tileSize, 7 * tileSize, "white_bishop.png");
        blackBishops[i] = new BlackBishop((2 + i * 3) * tileSize, 0 * tileSize, "black_bishop.png");
    }

    window.setSize(sf::Vector2u(1080, 1080));

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

        board.make(window);

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

    return 0;
}