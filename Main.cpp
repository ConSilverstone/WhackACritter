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
	Critter myCritter;
	Critter secondCritter;
	// Critter point values
	myCritter.Setup("graphics/owl.png", 10);
	secondCritter.Setup("graphics/parrot.png", 25);

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
			myCritter.Input(event);
			secondCritter.Input(event);

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
		score += myCritter.GetPendingScore();
		myCritter.ClearPendingScore();

		score += secondCritter.GetPendingScore();
		secondCritter.ClearPendingScore();
		scoreText.setString("Score: " + std::to_string(score));

		// End Update
		// --------------------

		// ------------------
		// Draw
		// ------------------

		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Blue);

		// Draw everything
		myCritter.Draw(gameWindow);
		secondCritter.Draw(gameWindow);
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
