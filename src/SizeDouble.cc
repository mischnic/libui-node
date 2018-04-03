#include "../ui.h"
#include "ui-node.h"

SizeDouble::SizeDouble(double width, double height) {
	w = width;
	h = height;
}

double SizeDouble::getWidth() {
	return w;
}

void SizeDouble::setWidth(double value) {
	w = value;
}


double SizeDouble::getHeight() {
	return h;
}

void SizeDouble::setHeight(double value) {
	h = value;
}
