// Anushervon Rakhmatov afr741 201356375	
//Jesse Alexander ______ ________________

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>

class Shape {
	const std::string name;
	int position_X;
	int position_Y;
	float speed;
	const std::string color;

	std::vector<std::shared_ptr<sf::Shape>> shapes;

public:
	void setPosition_X(int x) {
		position_X = x;
	}

	void setPosition_Y(int y) {
		position_Y = y;
	}
};

class Circle : public Shape {

};

class Rectangle : public Shape {

};

int main(int argc, char * argv[])
{

    // create a new window of size 400 by 400 pixels
    // top-left of the window is (0,0) and bottom-right is (w,h)
    const int wWidth = 800;
    const int wHeight = 600;
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");

	float circlex = 300.0f;
	float circley = 50.0f;
	 
	float circle2x = 100.0f;
	float circle2y = 100.0f;
		
	float rectx = 150.0f;
	float recty = 100.0f;

    // let's make a shape that we will draw to the screen
    sf::CircleShape circle(50);             // create a circle shape with radius 50
    circle.setFillColor(sf::Color::Green);  // set the circle color to green
    circle.setPosition(circlex, circley);     // set the top-left position of the circle
    float circleMoveSpeedy = 0.6f;          // we will use this to move the circle later
	float circleMoveSpeedx = 0.6f;

	//Circle2blue
		// let's make a shape that we will draw to the screen
	sf::CircleShape circle2(100);             // create a circle shape with radius 100
	circle2.setFillColor(sf::Color::Blue);  // set the circle color to blue
	circle2.setPosition(circle2x,circle2y);     // set the top-left position of the circle
	float circleMoveSpeed2y = 0.3f;          // we will use this to move the circle later
	float circleMoveSpeed2x = 0.3f;


	//rectangle
		// let's make a shape that we will draw to the screen
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(100, 50));
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(rectx,recty);
	float rectMoveSpeedx = 0.4f;          // we will use this to move the circle later
	float rectMoveSpeedy = 0.4f;

	std::vector<Shape> shapes;

	std::ifstream cin("config.txt");

	std::string token, color;
	int width, height;

	while (cin.good())
	{
		cin >> token;

		if (token == "Window")
		{
			cin >> width >> height;
			std::cout << "\dimension: " << width << "," << height;
			sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");
		}
	}


	//struct myShape {
		//shared.ptr<sf::shape>
			//name
			//speed
	//};

	sf::Vector2f velocity;
	velocity.x = 1;
	velocity.y = 1;

	



    // let's load a font so we can display some text
    sf::Font arial;

    // attempt to load the font from a file
    if (!arial.loadFromFile("fonts/arial.ttf"))
    {
        // if we can't load the font, print an error to the error console and exit
        std::cerr << "Could not load font!\n";
        exit(-1);
    }

    // set up the text object that will be drawn to the screen
    sf::Text text("Circle", arial, 24);

    // position the top-left corner of the text so that the text aligns on the bottom
    // text character size is in pixels, so move the text up  from the bottom by its height
	float textx = 300.0f;
	float texty = 50.0f;
	text.setPosition(textx, texty);    
	float textMoveSpeedx = 0.3f;
	float textMoveSpeedy = 0.3f;

	

    // main loop - continues for each frame while window is open
    while (window.isOpen())
    {

        // event handling 
        sf::Event event;
        while (window.pollEvent(event))
        {
			
            // this event triggers when the window is closed
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // this event is triggered when a key is pressed
            if (event.type == sf::Event::KeyPressed)
            {
                // print the key that was pressed to the console
                std::cout << "Key pressed with code = " << event.key.code << "\n";

                // example, what happens when x is pressed
                if (event.key.code == sf::Keyboard::X)
                {
                    // reverse the direction of the circle on the screen
                    circleMoveSpeedx *= -1.0f;
					rectMoveSpeedy *= -1.0f;
					
                }
            }
        }
		
        // basic animation - move the each frame if it's still in frame
        circle.setPosition(circle.getPosition().x - circleMoveSpeedx, circle.getPosition().y - circleMoveSpeedy);
		circle2.setPosition(circle2.getPosition().x - circleMoveSpeed2x, circle2.getPosition().y - circleMoveSpeed2y);
		rect.setPosition(rect.getPosition().x - rectMoveSpeedx, rect.getPosition().y - rectMoveSpeedy);
		

		// animation for text 
		text.setPosition(text.getPosition().x - textMoveSpeedx, text.getPosition().y - textMoveSpeedy);


		//collision for text(needs a rework)
		if (text.getPosition().x <= 0 || (text.getPosition().x + text.getLocalBounds().width >= wWidth)) {
			textx = wWidth - text.getLocalBounds().width;
			textMoveSpeedx *= -1.0f;

		}
		else if (text.getPosition().y <= 0 || (text.getPosition().y + text.getLocalBounds().height >= wHeight))
		{
			texty = wHeight - text.getLocalBounds().height;
			textMoveSpeedy *= -1.0f;
		}




		//Collision for circle
		if (circle.getPosition().x <= 0  || (circle.getPosition().x + circle.getLocalBounds().width >= wWidth)) {
			circlex = wWidth-circle.getLocalBounds().width;
			circleMoveSpeedx *= -1.0f;
			
		}
		else if( circle.getPosition().y <= 0 || (circle.getPosition().y + circle.getLocalBounds().height >= wHeight))
			{
			circley = wHeight-circle.getLocalBounds().height;
				circleMoveSpeedy *= -1.0f;
			}
	

		//collision for circle2
		if (circle2.getPosition().x <= 0 || (circle2.getPosition().x + circle2.getLocalBounds().width >= wWidth)) {
			circle2x = wWidth - circle2.getLocalBounds().width;
			circleMoveSpeed2x *= -1.0f;

		}
		else if (circle2.getPosition().y <= 0 || (circle2.getPosition().y + circle2.getLocalBounds().height >= wHeight))
		{
			circle2y = wHeight - circle2.getLocalBounds().height;
			circleMoveSpeed2y *= -1.0f;
		}
			


		//collision for rectangle needs to be changed
		
		if (rect.getPosition().x <= 0 || (rect.getPosition().x + rect.getLocalBounds().width >= wWidth)) {
			rectx = wWidth - rect.getLocalBounds().width;
			rectMoveSpeedx *= -1.0f;

		}
		else if (rect.getPosition().y <= 0 || (rect.getPosition().y + rect.getLocalBounds().height >= wHeight))
		{
			recty = wHeight - rect.getLocalBounds().height;
			rectMoveSpeedy *= -1.0f;
		}

		

        // basic rendering function calls
        window.clear();         // clear the window of anything previously drawn
        window.draw(circle);    // draw the circle
		window.draw(circle2);
		window.draw(rect);
        window.draw(text);      // draw the text
        window.display();       // call the window display function
		
    }


    return 0;



}