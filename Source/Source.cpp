#include <iostream>
#include "GUI/Graph.h"
#include "GUI/Window.h"

int main() {
	try {
		using namespace Graph_lib;

		Graph_lib::Window window{ { x_max() / 3, 200 }, 800, 600, "window" };
		window.color(39);

		Vector_ref<Graph_lib::Rectangle>v;
		for (int x = 0; x < 16; ++x) {
			for (int y = 0; y < 16; ++y) {
				v.push_back(new Graph_lib::Rectangle{{x * 20, y * 20 }, 20, 20});
				v[v.size() - 1].set_fill_color(x * 16 + y);
				v[v.size() - 1].set_color(Color::invisible);
				window.attach(v[v.size() - 1]);
			}
		}
		Graph_lib::gui_main();
	}
	
	catch (std::runtime_error &e) {
		std::cerr << "RUNTIME_ERROR: " << e.what() << '\n';
		char ch(0);
		while (ch != '\n') {	
			std::cin.clear();
			std::cout << "Press Enter to continue...\n";
			std::cin.get(ch);
		}
		return 1;
	}
	return 0;
}
