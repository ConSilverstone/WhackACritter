#pragma once

//-----------------
// Includes
// ----------------
// Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Critter 
{
	// --------------
	// Behaviour
	// --------------

public:

	// Constructor
	Critter();

	// Render the critter to the target
	void Draw(sf::RenderTarget& _target);

	// Process input on the Critter
	void Input(sf::Event _gameEvent);

	// Getter for pending score data
	int GetPendingScore();

	// Clear the pending score
	void ClearPendingScore();

	// End Behaviour
	// --------------

	// --------------
	// Data
	// --------------

private:

	sf::Sprite m_sprite; 
	sf::Texture m_texture;
	bool m_alive;
	sf::Sound m_deathSound;
	sf::SoundBuffer m_deathBuffer;
	int m_pendingScore;

	// end Data
	// --------------

}; // End Critter Class