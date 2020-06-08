#include <vector>
#include "Window.h"
#include "TextBuffer.h"

class Console{
public:
	vector<shared_ptr<Window>> window;

	static Console& instance(){
		static Console console;
		return console;
	}

	shared_ptr<Window> multicolumn(const string& title,
	uint8_t columnCount, uint8_t columnWidth, uint8_t charsHight){
		auto w = make_shared<Window>(title,
			columnCount*columnWidth*charWidth,
			charsHigh*charHeigh);

		for(uint8_t c = 0; c < columnCount; ++c){
			auto buffer = make_shared<TextBuffer>(columnWidth, charsHight);
			w->buffer.push_back(buffer);
			auto viewport = make_shared<viewport>(buffer,
				buffer->get_size(), Point{}, Point{columnWidth*c, 0});
			w->viewport.push_back(viewport);
			window.push_back(w);
		}

		return w;
	}


private:
	const int charWidth = 10, charHeight = 14;
	Console(){}
	Console(Console const&) = delete;
	void operator=(Console const&) = delete;
}