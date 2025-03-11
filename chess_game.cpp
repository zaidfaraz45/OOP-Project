#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class chessBoard
{
    int length;
    int width;

    public:
        chessBoard(int l, int w) : length(l), width(w) {}
 
        void make(sf::RenderWindow &window)
        {
            sf::RectangleShape square(sf::Vector2(125.f, 125.f));

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

                    square.setPosition(sf::Vector2f(col * 125, row * 125));

                    window.draw(square);
                }
            }
        }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "Chess Game");
    
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