#include "../ui.h"
#include "ui-node.h"

Point::Point(const Point &other) {
	x = other.x;
	y = other.y;
}

Point::Point(int xCoord, int yCoord) {
	x = xCoord;
	y = yCoord;
}

int Point::getX() {
	return x;
}

void Point::setX(int value) {
	x = value;
}


int Point::getY() {
	return y;
}

void Point::setY(int value) {
	y = value;
}



