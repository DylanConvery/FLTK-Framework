#include <iostream>
#include "GUI/Graph.h"
#include "GUI/Window.h"

int main() {
	using namespace Graph_lib;

	Graph_lib::Window window{{x_max()/2, y_max()/2}, 800, 600, "window"};

	Axis x{Axis::x,{0, window.y_max()/2}, window.x_max(), 80};
	x.set_style(Line_style{Line_style::solid, 1});
	x.set_color(Color::black);
	
	Axis y{Axis::y,{window.x_max()/2, window.y_max()}, window.y_max(), 60};
	y.set_style(Line_style{Line_style::solid, 1});
	y.set_color(Color::black);

	Arrow arrow{{50, 50}, {200, 200}};
	arrow.set_style(Line_style{Line_style::solid, 3});
	arrow.set_color(Color::black);

	Function sine{sin, 0, 50, Point{20,150}, 100, 10, 10};
	sine.set_color(Color::red);

	int x_size = window.x_max();
	int y_size = window.y_max();

	int x_grid = 80;
	int y_grid = 40;

	Lines grid;
	grid.set_color(Color::black);

	for(int x = x_grid; x < x_size; x+= x_grid){
		grid.add(Point{x,0}, Point{x,y_size});
	}
	for(int y = y_grid; y < y_size; y+= y_grid){
		grid.add(Point{0,y}, Point{x_size,y});
	}

	Lines newLines = {
		{Point{100,100}, Point{200,100}},
		{Point{150,50}, Point{150,150}}
	};

	window.attach(newLines);
	
	window.color(39);
	window.attach(sine);
	window.attach(x);
	window.attach(y);
	window.attach(arrow);
	window.attach(grid);

	gui_main();
	return 0;
}