#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "New Window");

	sf::RectangleShape rectangle1;
	rectangle1.setSize(sf::Vector2f(20, 100));
	rectangle1.setFillColor(sf::Color::White);
	rectangle1.setOutlineColor(sf::Color::White);
	rectangle1.setPosition(50, 360);

	sf::RectangleShape rectangle2;
	rectangle2.setSize(sf::Vector2f(20, 100));
	rectangle2.setFillColor(sf::Color::White);
	rectangle2.setOutlineColor(sf::Color::White);
	rectangle2.setPosition(730, 360);

	sf::CircleShape ball;
	ball.setRadius(10);
	ball.setFillColor(sf::Color::White);
	ball.setOutlineColor(sf::Color::White);
	ball.setPosition(400, 400);

	float moveSpeed = 0.1f;
	sf::Vector2f velocity(0.06f, 0.06f);

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
			if (newY < 700)
				rectangle1.move(0, moveSpeed);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			float newY = rectangle2.getPosition().y;
			if (newY >= 0)
				rectangle2.move(0, -moveSpeed);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			float newY = rectangle2.getPosition().y;
			if (newY < 700)
				rectangle2.move(0, moveSpeed);			
		}

		if (rectangle2.getGlobalBounds().intersects(ball.getGlobalBounds()) ||  rectangle1.getGlobalBounds().intersects(ball.getGlobalBounds())) {
			velocity.x = -velocity.x;
		} else if (ball.getPosition().y < 0 || ball.getPosition().y > 780) {
			velocity.y = -velocity.y;
		} else if (ball.getPosition().x < 0 || ball.getPosition().x > 780) {
			ball.setPosition(400, 400);
		}



		ball.move(velocity);

		window.clear();
		window.draw(rectangle1);
		window.draw(rectangle2);
		window.draw(ball);
		window.display();
	}
	return EXIT_SUCCESS;
}
