
//-----------------
// Includes
// ----------------
// Library Includes
#include <cstdlib>

// Project Includes
#include "Critter.h"

Critter::Critter() 
// initialisation list
	: m_sprite()
	, m_texture()
	, m_alive(true)
	, m_deathSound()
	, m_deathBuffer()
	, m_pendingScore(0)
	, m_scoreValue(1)
{
	// Setting up the death sound
	m_deathBuffer.loadFromFile("audio/buttonclick.ogg");
	m_deathSound.setBuffer(m_deathBuffer);
}

void Critter::Draw(sf::RenderTarget& _target)
{
	if (m_alive)
	{
		_target.draw(m_sprite);
	}
}

void Critter::Input(sf::Event _gameEvent)
{
	// only draw our sprite if we are alive
	if (m_alive)
	{
		// Check if this event is a click
		if (_gameEvent.type == sf::Event::MouseButtonPressed)
		{

			// Check if this event is a click
			if (_gameEvent.type == sf::Event::MouseButtonPressed)
			{

				// Did they click on this critter?
				if (m_sprite.getGlobalBounds().contains(_gameEvent.mouseButton.x, _gameEvent.mouseButton.y))
				{
					// They clicked it!

					// We die
					m_alive = false;

					// Play the death sound
					m_deathSound.play();

					// Added to pending score
					m_pendingScore += m_scoreValue;
				}

			} // End event is statement
		}
	}
}

int Critter::GetPendingScore()
{
	return m_pendingScore;
}


void Critter::ClearPendingScore() 
{
	m_pendingScore = 0;
}

void Critter::Setup(std::string _texturefile, int _pointValue) 
{
	// Set up the sprite
	m_texture.loadFromFile(_texturefile);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand() % sf::VideoMode::getDesktopMode().width,
		rand() % sf::VideoMode::getDesktopMode().height);

	m_scoreValue = _pointValue;
}