#include "../ui.h"
#include "ui-node.h"

Size::Size(int width, int height) {
	w = width;
	h = height;
}

int Size::getWidth() {
	return w;
}

void Size::setWidth(int value) {
	w = value;
}


int Size::getHeight() {
	return h;
}

void Size::setHeight(int value) {
	h = value;
}



