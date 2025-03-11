#include <SFML/Graphics.hpp>
#include <iostream>
#define windowLength 1000
#define windowWidth 1000
using namespace std;

class chessBoard
{
    int length;
    int width;

    public:
        chessBoard(int l, int w) : length(l), width(w) {}
 
        void make(sf::RenderWindow &window)
        {
            const float tileSize = windowWidth / 8;
            sf::RectangleShape square(sf::Vector2(tileSize, tileSize));

            for (int row = 0; row < length; row++)
            {
                for (int col = 0; col < width; col++)
                {
                    if ((row + col) % 2 == 0)
                    {
                        square.setFillColor(sf::Color(255, 255, 255));
                    }
                    else
                    {
                        square.setFillColor(sf::Color(0, 0, 0));
                    }

                    square.setPosition(sf::Vector2f(col * tileSize, row * tileSize));

                    window.draw(square);
                }
            }
        }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode({windowLength, windowWidth}), "Chess Game");
    
    chessBoard board(8, 8);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        board.make(window);
        window.display();
    }
}