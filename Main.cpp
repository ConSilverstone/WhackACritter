#include <SFML/Graphics.hpp>

int main()
{
	// ------------------------
	// Game Setup
	// ------------------------

	// Render Window creation
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Whack A Critter!",
	sf::Style::Titlebar | sf::Style::Close);

	// Timer functionality
	sf::Clock gameClock;

	while (gameWindow.isOpen())
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameWindow.close();
		}

		// -----------------
		// Draw
		// ------------------

		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Blue);

		// Draw everything

		//Display the window contents of the screen
		gameWindow.display();


	} // end of game while loop
	// ----------------------------
	// end game loop
	// ----------------------------

	// exit point for the program
	return 0;
} // end of main() function
