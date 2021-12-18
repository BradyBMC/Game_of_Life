#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

void drawGrid(sf::RenderWindow&, int rows, int cols);

int main() {
  cout << "This took way too much work lol" << endl;
  sf::RenderWindow window(sf::VideoMode(200,200), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);
  drawGrid(window,5,5);
  window.display();
  while(window.isOpen()) { 
    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed) {
	      window.close();
      }
    }
  }
  return 0;
}

void drawGrid(sf::RenderWindow& window, int rows, int cols) {
  int numLines = rows+cols-2;
    sf::VertexArray grid(sf::Lines, 2*(numLines));
    window.setView(window.getDefaultView());
    auto size = window.getView().getSize();
    float rowH = size.y/rows;
    float colW = size.x/cols;
    // row separators
    for(int i=0; i < rows-1; i++){
        int r = i+1;
        float rowY = rowH*r;
        grid[i*2].position = {0, rowY};
        grid[i*2+1].position = {size.x, rowY};
    }
    // column separators
    for(int i=rows-1; i < numLines; i++){
        int c = i-rows+2;
        float colX = colW*c;
        grid[i*2].position = {colX, 0};
        grid[i*2+1].position = {colX, size.y};
    }
    // draw it
    window.draw(grid);
}
