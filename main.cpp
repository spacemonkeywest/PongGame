#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "New Window");

	sf::RectangleShape rectangle1;
	rectangle1.setSize(sf::Vector2f(20, 150));
	rectangle1.setFillColor(sf::Color::White);
	rectangle1.setOutlineColor(sf::Color::White);
	rectangle1.setPosition(50, 360);

	sf::RectangleShape rectangle2;
	rectangle2.setSize(sf::Vector2f(20, 150));
	rectangle2.setFillColor(sf::Color::White);
	rectangle2.setOutlineColor(sf::Color::White);
	rectangle2.setPosition(730, 360);

	float moveSpeed = 0.05f;

	while (window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))  {
			float newY = rectangle1.getPosition().y;
			if (newY >= 0)
				rectangle1.move(0, -moveSpeed);
		} 

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			float newY = rectangle1.getPosition().y;
			if (newY < 650)
				rectangle1.move(0, moveSpeed);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			float newY = rectangle2.getPosition().y;
			if (newY >= 0)
				rectangle2.move(0, -moveSpeed);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			float newY = rectangle2.getPosition().y;
			if (newY < 650)
				rectangle2.move(0, moveSpeed);			
		}



		window.clear();
		window.draw(rectangle1);
		window.draw(rectangle2);
		window.display();
	}
	return EXIT_SUCCESS;
}
