//-----------------
// Includes
// ----------------
// Libraries
#include <SFML/Graphics.hpp>
#include <cstdlib> // Gives access to random funct
#include <ctime> // Gives access to time funct

// Project Includes
#include "Critter.h"

int main()
{
	// ------------------------
	// Game Setup
	// ------------------------

	// Render Window creation
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Whack A Critter!",
	sf::Style::Titlebar | sf::Style::Close);

	//Seed our random number generation
	srand(time(NULL));

	// Timer functionality
	sf::Clock gameClock;

	// Create an instance of our Critter class
	Critter myCritter;

	// End of Game Setup


	while (gameWindow.isOpen())
	{
		//------------------------
		// Input
		// -----------------------
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			// Process input on critters
			myCritter.Input(event);

			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			}
		}

		// ------------------
		// Draw
		// ------------------

		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Blue);

		// Draw everything
		myCritter.Draw(gameWindow);

		//Display the window contents of the screen
		gameWindow.display();


	} // end of game while loop
	// ----------------------------
	// end game loop
	// ----------------------------

	// exit point for the program
	return 0;
} // end of main() function
