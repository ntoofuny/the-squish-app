#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


float yVelocity = 0.5;
float xVelocity = 0.5;

int main()
{

    //setup the plate background
    sf::Texture textPlate;
    sf::Sprite Plate;
    textPlate.loadFromFile("resources\\plate.jpg");
    textPlate.setSmooth(true);
    Plate.setTexture(textPlate);

    //setup squish-o-meter
    sf::Texture textMeter;
    sf::Sprite squishMeter;
    textMeter.loadFromFile("resources\\squish-o-meter.png");
    squishMeter.setTexture(textMeter);
    squishMeter.setPosition(100, 430);
    squishMeter.scale(0.3, 0.3);

    //setup the perogi
    sf::Texture textPerog;
    sf::Sprite glPerog;
    textPerog.loadFromFile("resources\\glPerogi.png");
    glPerog.setTexture(textPerog);
    glPerog.setPosition(400, 250);
    glPerog.scale(0.1, 0.1);

    //setup brown sushi roll
    sf::Texture textSush;
    sf::Sprite brSushi;
    textSush.loadFromFile("resources\\brSushi.png");
    brSushi.setTexture(textSush);
    brSushi.setPosition(100, 150);
    brSushi.scale(0.2, 0.2);

    //setup pink heart
    sf::Texture textHeart;
    sf::Sprite pkHeart;
    textHeart.loadFromFile("resources\\pkHeart.png");

    std::vector<sf::Sprite> hearts;

    pkHeart.setTexture(textHeart);
    float xHeart = 0;
    float yHeart = 100;
    pkHeart.setPosition(xHeart, yHeart);

    //hearts.push_back(pkHeart);
    //pkHeart.setPosition(100, 50);
    //hearts.push_back(pkHeart);

    //setup font
    sf::Font aclonica;
    sf::Text title;
    if (!aclonica.loadFromFile("resources\\aclonica.regular.ttf"))
    {
        return -1;
    }
    title.setFont(aclonica);
    title.setString("The Squish App");
    title.setCharacterSize(70);
    title.setFillColor(sf::Color::White);
    title.setPosition(100, 0);

    

    //window setup and events
    sf::RenderWindow window(sf::VideoMode(800, 600), "Welcome to the Squish App!");

    sf::Vector2u plateSize; //background
    sf::Vector2u windowSize;
    windowSize = window.getSize();
    plateSize = textPlate.getSize(); //remember to get size of textures, not sprites
    float ScaleX = (float)windowSize.x / plateSize.x;
    float ScaleY = (float)windowSize.y / plateSize.y;
    Plate.setScale(ScaleX, ScaleY);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                glPerog.move(2.f, 0.f);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                glPerog.move(-2.f, 0.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                brSushi.move(-2.f, 0.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                brSushi.move(2.f, 0.f);
            }
        }

        //when they hug, the squish-o-meter fills up

            yHeart = yHeart + yVelocity;
            xHeart = xHeart + xVelocity;
        if (yHeart >= windowSize.y) {
            yVelocity = -yVelocity;
        }
        else if (yHeart < 0) {
            yVelocity = -yVelocity;
        }
        if (xHeart >= windowSize.x) {
            xVelocity = -xVelocity;
        }
        else if (xHeart < 0) {
            xVelocity = -xVelocity;
        }
        pkHeart.setPosition(xHeart, yHeart);
        

        window.clear();
        window.draw(Plate);
        //for (size_t i = 0; i < hearts.size(); i++) {
            //window.draw(hearts[i]);
        //}
        window.draw(pkHeart);
        window.draw(title);
        window.draw(squishMeter);
        window.draw(glPerog);
        window.draw(brSushi);
        window.display();
    }

    return 0;

}