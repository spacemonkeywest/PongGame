#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "New Window");

	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(5, 80));
	rectangle.setFillColor(sf::Color::White);
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(50, 360);

	float moveSpeed = 0.05f;

	while (window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::W) {
				rectangle.move(0, -moveSpeed);
			}

			if (event.key.code == sf::Keyboard::S) {
				rectangle.move(0, moveSpeed);
			}

		}

		window.clear();
		window.draw(rectangle);
		window.display();
	}
	return EXIT_SUCCESS;
}
