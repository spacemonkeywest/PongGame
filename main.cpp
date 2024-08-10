#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
	RenderWindow window(VideoMode(800, 800), "New Window");
	while (window.isOpen()) {
		Event event;
		while(window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		window.clear();
		window.display();
		}
	}
	return EXIT_SUCCESS;
}
