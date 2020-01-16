#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;
	// initialise game objects
	circle.setRadius(50);
	circle.setPosition(575, 335);
	circle.setFillColor(sf::Color::White);

	/*Rectangle initialisation*/
	rect2.setSize(sf::Vector2f(80, 80));
	rect2.setPosition(450, 450);
	rect2.setFillColor(sf::Color::Red);
	rect3.setSize(sf::Vector2f(50, 50));
	rect3.setPosition(465, 465);
	rect3.setFillColor(sf::Color::Green);
	rect4.setSize(sf::Vector2f(20, 20));
	rect4.setPosition(480, 480);
	rect4.setFillColor(sf::Color::Blue);

	/*outputs error message if font fails to load*/
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font \n";
	}

	text.setFont(font);
	text.setString("Hello World");
	text.setCharacterSize(35);
	text.setPosition(400, 0);
	text.setFillColor(sf::Color::Red);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	/*Re-positions rectangle when every frame*/
	sf::Vector2u pos = window->getSize();
	rect.setSize(sf::Vector2f(100, 50));
	rect.setPosition(pos.x - 100, pos.y - 50);
	rect.setFillColor(sf::Color::Red);
	
}

// Render level
void Level::render()
{
	/*Draw objects on window*/
	beginDraw();
	window->draw(rect);
	window->draw(rect2);
	window->draw(rect3);
	window->draw(rect4);
	window->draw(circle);
	window->draw(text);
	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}