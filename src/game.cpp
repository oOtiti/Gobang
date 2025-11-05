#include<SFML/Graphics.hpp>
int main()
{
    // Create a VideoMode and a RenderWindow, then run a simple event loop.
    sf::VideoMode vm(sf::Vector2u(800u, 600u));
    sf::RenderWindow window(vm, "Gobang - Test Window");
    window.setFramerateLimit(60);

    // Main loop (SFML 3: pollEvent returns std::optional<sf::Event>)
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            // Check event subtype using the new Event API
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // Simple clear/draw/display so the window is visible.
        window.clear(sf::Color(30, 30, 30));

        // (Optional) draw a simple shape to verify rendering
        sf::CircleShape circle(50.f);
        circle.setFillColor(sf::Color::Green);
    circle.setPosition(sf::Vector2f(100.f, 100.f));
        window.draw(circle);

        window.display();
    }

    return 0;
}