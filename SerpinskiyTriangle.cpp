#include <SFML\Graphics.hpp>
#include <iostream>
using namespace sf;

struct point {
	float x;
	float y;
};

int SerpinskiyTriangle(point A, point B, point C, int depth, RenderWindow& window) {

	point a, b, c;
	a.x = (A.x + B.x) / 2;
	a.y = (A.y + B.y) / 2;
	b.x = (C.x + B.x) / 2;
	b.y = (C.y + B.y) / 2;
	c.x = (A.x + C.x) / 2;
	c.y = (A.y + C.y) / 2;



	Vertex line[] =
	{
		Vertex(Vector2f(B.x, B.y),  Color::Red),
		Vertex(Vector2f(A.x, A.y),  Color::Red),
		Vertex(Vector2f(C.x, C.y),  Color::Red),
		Vertex(Vector2f(B.x, B.y),  Color::Red),
	};
	
	if (depth > 0) {

	window.draw(line, 4, LinesStrip);

	SerpinskiyTriangle(A, a, c, depth - 1, window);
	SerpinskiyTriangle(a, B, b, depth - 1, window);
	SerpinskiyTriangle(c, b, C, depth - 1, window);
	
	return 0;
	}
	
}

int main()
{
	 RenderWindow window( VideoMode(1100, 1100), "My window");
	while (window.isOpen()){
		 Event event;
		while (window.pollEvent(event)) {
			if (event.type ==  Event::Closed)
				window.close();
		}

		window.clear( Color::White);

		point a, b, c;
		a.x = 10;
		a.y = 990;
		b.x = 990;
		b.y = 990;
		c.x = 500;
		c.y = 50;

		SerpinskiyTriangle(a, b, c, 6, window);

		window.display();
	}
}
