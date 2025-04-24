#include "ChessBoard.h"

ChessBoard::ChessBoard(string i) : image(i) {}

void ChessBoard::make(sf::RenderWindow& window)
{
    sf::Texture texture(image);
    sf::Sprite sprite(texture);
    sprite.setPosition(sf::Vector2f(0, 0));

    window.draw(sprite);
}