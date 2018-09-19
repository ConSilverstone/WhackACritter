//-----------------
// Includes
// ----------------
// Libraries
#include <SFML/Graphics.hpp>
#include <string> // Gives access to string library
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
	const int NUM_CRITTERS = 5;
	Critter critters[NUM_CRITTERS];

	// Critter Index froma array
	critters[0].Setup("graphics/sloth.png", 1);
	critters[1].Setup("graphics/moose.png", 5);
	critters[2].Setup("graphics/buffalo.png", 15);
	critters[3].Setup("graphics/owl.png", 10);
	critters[4].Setup("graphics/parrot.png", 25);

	// Game Font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");

	// Score tracking
	int score = 0;
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(50, 50);

	// End of Game Setup
	// ---------------------

	while (gameWindow.isOpen())
	{
		//------------------------
		// Input
		// -----------------------
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			// Process input on critters
			for (int i = 0; i < NUM_CRITTERS; ++i)
			{
				critters[i].Input(event);
			}

			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			}
		}

		// End Input
		// -------------------

		// -------------------
		// Update
		// -------------------

		sf::Time frameTime = gameClock.restart();

		// See if there is a pending score
		for (int i = 0; i < NUM_CRITTERS; ++i)
		{
			score += critters[i].GetPendingScore();
			critters[i].ClearPendingScore();
		}

		// End Update
		// --------------------

		// ------------------
		// Draw
		// ------------------

		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Blue);

		// Draw everything
		for (int i = 0; i < NUM_CRITTERS; ++i)
		{
			critters[i].Draw(gameWindow);
		}
		gameWindow.draw(scoreText);

		//Display the window contents of the screen
		gameWindow.display();


	} // end of game while loop
	// ----------------------------
	// end game loop
	// ----------------------------

	// exit point for the program
	return 0;
} // end of main() function
