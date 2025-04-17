#include <SFML/Graphics.hpp>
#include <iostream>

const int windowLength = 1000;
const int windowWidth = 1000;
const float tileSize = windowWidth / 8;

class chessBoard 
{
    int length;
    int width;

    public:
        chessBoard(int l, int w) : length(l), width(w) {}

        void make(sf::RenderWindow& window)
        {
            sf::RectangleShape square(sf::Vector2f(tileSize, tileSize));

            for (int row = 0; row < length; row++) 
            {
                for (int col = 0; col < width; col++) 
                {
                    if ((row + col) % 2 == 0) 
                    {
                        square.setFillColor(sf::Color(130, 70, 52));
                    }
                    else 
                    {
                        square.setFillColor(sf::Color(99, 53, 53));
                    }

                    square.setPosition(sf::Vector2f(col * tileSize, row * tileSize));
                    window.draw(square);
                }
            }
        }

        ~chessBoard() {}
};

class Pawn 
{
    float size;
    sf::Color color;
    float x, y;

    public:
        Pawn(float s, const sf::Color& c, float X, float Y): size(s), color(c), x(X), y(Y) {}

        void draw(sf::RenderWindow& window) 
        {
            sf::CircleShape lower(size * 0.3f);
            lower.setFillColor(color);
            lower.setPosition(sf::Vector2f(x + tileSize / 2 - size * 0.3f, y + tileSize * 0.9 - size * 0.6f));
            window.draw(lower);

            sf::CircleShape middle(size * 0.2f);
            middle.setFillColor(color);
            middle.setPosition(sf::Vector2f(x + tileSize / 2 - size * 0.2f, y + tileSize * 0.9 - size * 0.9f));
            window.draw(middle);

            sf::CircleShape upper(size * 0.15f);
            upper.setFillColor(color);
            upper.setPosition(sf::Vector2f(x + tileSize / 2 - size * 0.15f, y + tileSize * 0.9 - size * 1.1f));
            window.draw(upper);
        }
};


int main() 
{
    sf::RenderWindow window(sf::VideoMode({ windowLength, windowWidth }), "Chess Game");

    chessBoard board(8, 8);

    float size = tileSize / 1.5;

    Pawn whitePawns[8] = 
    {
        Pawn(size, sf::Color::White, 0 * tileSize, 6 * tileSize),
        Pawn(size, sf::Color::White, 1 * tileSize, 6 * tileSize),
        Pawn(size, sf::Color::White, 2 * tileSize, 6 * tileSize),
        Pawn(size, sf::Color::White, 3 * tileSize, 6 * tileSize),
        Pawn(size, sf::Color::White, 4 * tileSize, 6 * tileSize),
        Pawn(size, sf::Color::White, 5 * tileSize, 6 * tileSize),
        Pawn(size, sf::Color::White, 6 * tileSize, 6 * tileSize),
        Pawn(size, sf::Color::White, 7 * tileSize, 6 * tileSize)
    };

    Pawn blackPawns[8] = 
    {
        Pawn(size, sf::Color::Black, 0 * tileSize, 1 * tileSize),
        Pawn(size, sf::Color::Black, 1 * tileSize, 1 * tileSize),
        Pawn(size, sf::Color::Black, 2 * tileSize, 1 * tileSize),
        Pawn(size, sf::Color::Black, 3 * tileSize, 1 * tileSize),
        Pawn(size, sf::Color::Black, 4 * tileSize, 1 * tileSize),
        Pawn(size, sf::Color::Black, 5 * tileSize, 1 * tileSize),
        Pawn(size, sf::Color::Black, 6 * tileSize, 1 * tileSize),
        Pawn(size, sf::Color::Black, 7 * tileSize, 1 * tileSize)
    };

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
            whitePawns[i].draw(window);
        }

        for (int i = 0; i < 8; i++) 
        {
            blackPawns[i].draw(window);
        }

        window.display();
    }

    return 0;
}