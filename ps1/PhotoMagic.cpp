// pixels.cpp: 
// using SFML to load a file, manipulate its pixels, write it to disk


// g++ -o pixels pixels.cpp -lsfml-graphics -lsfml-window
#include  "FibLFSR.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
void transform(sf::Image& img, FibLFSR* lfsr);
int main(int argc,char* argv[])
{
	sf::Image image;
	sf::Image imageEnc;//encrypted image object
	if (!image.loadFromFile(argv[1]))
		return -1;
	if (!imageEnc.loadFromFile(argv[1]))
		return -1;
	// p is a pixelimage.getPixel(x, y);
	sf::Color p;

    FibLFSR lfsr(argv[3]);
	// create photographic negative image of upper-left 200 px square
	transform(imageEnc,&lfsr);
	sf::Vector2u size = image.getSize();
	sf::Vector2u size2 = imageEnc.getSize();//size for enccrypted image
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Meow");
	sf::RenderWindow window2(sf::VideoMode(size2.x, size2.y), "Meow-transform");//window for encrypted image

	sf::Texture texture;
	sf::Texture texture2;//texture for encrypted image
	texture.loadFromImage(image);
	texture2.loadFromImage(imageEnc);
	
	sf::Sprite sprite;
	sf::Sprite spriteEnc;
	sprite.setTexture(texture);
	spriteEnc.setTexture(texture2);

	while (window1.isOpen() && window2.isOpen()) {
		sf::Event event;
		while (window1.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window1.close();
		}
	while (window2.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window2.close();
	}
	window1.clear();
	window1.draw(sprite);
	window1.display();
	window2.clear();
	window2.draw(spriteEnc);
	window2.display();
	}


	// fredm: saving a PNG segfaults for me, though it does properly
	//   write the file
	if (!imageEnc.saveToFile(argv[2]))
		return -1;

	return 0;
}
void transform(sf::Image &img, FibLFSR *lfsr)
{
    sf::Color p;
	sf::Vector2u size = img.getSize();
	for (unsigned x = 0; x<size.x; x++) {
		for (unsigned y = 0; y<size.y; y++) {
			p = img.getPixel(x, y);
			p.r = p.r ^ lfsr->generate(8);
			p.g = p.g ^ lfsr->generate(8);
			p.b = p.b ^ lfsr->generate(8);
			img.setPixel(x, y, p);
	    }
	}
}
