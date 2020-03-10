
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(900, 700), "Game");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon2.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::RectangleShape sfondo (sf::Vector2f(900.0f,700.0f));
    sf::Texture sfondoTexture;
    sfondoTexture.loadFromFile( resourcePath() + "sfondo3.png" );
    sfondo.setTexture(&sfondoTexture);
    //Create the Player
    sf::RectangleShape player (sf::Vector2f(100.0f,100.0f));
    player.setPosition(450.0f,350.06f);
    sf::Texture playerTexture ;
    playerTexture.loadFromFile( resourcePath() + "tux_from_linux.png" );
    player.setTexture(&playerTexture);
    
    sf::Vector2u textureSize = playerTexture.getSize();
    textureSize.x /= 3 ;
    textureSize.y /= 9 ;
    
    player.setTextureRect(sf::IntRect(textureSize.x * 2,textureSize.y * 8, textureSize.x,textureSize.y));
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Welcome", font, 50);
    text.setFillColor(sf::Color::Red);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "prova2.wav")) {
        return EXIT_FAILURE;
    }
    //nice_music.ogg

    // Play the music
    music.play();

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            player.move(-0.1f,0.0f);
        };
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            player.move(0.1f,0.0f);
        };

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sfondo);
        window.draw(player);
        // Draw the string
        //window.draw(text);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
/*
sf::Texture texture;
if (!texture.loadFromFile(resourcePath() + "sfondo.png")) {
    return EXIT_FAILURE;
}
sf::Sprite sprite(texture);
*/
