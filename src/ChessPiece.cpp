#include "global.h"
#include "ChessPiece.h"

ChessPiece::ChessPiece(float x, float y, string i): posX(x), posY(y), image(i) {}  

void ChessPiece::make(sf::RenderWindow &window)
{  
    sf::Texture texture(image);
    sf::Sprite sprite(texture);
    sprite.setPosition(sf::Vector2f(posX + tileSize / 4, posY + tileSize / 4));
    float scaleX = tileSize / texture.getSize().x / 2;
    float scaleY = tileSize / texture.getSize().y / 2;
    sprite.setScale(sf::Vector2f(scaleX, scaleY));

    window.draw(sprite);
}