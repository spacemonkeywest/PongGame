#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "New Window");

	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(100, 50));
	rectangle.setFillColor(sf::Color::White);
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(10, 20);

	while (window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		std::cout << "Rectangle position: " << rectangle.getPosition().x 		i<< ", " << rectangle.getPosition().y << std::endl;

		window.draw(rectangle);
		window.display();
	}
	return EXIT_SUCCESS;
}
