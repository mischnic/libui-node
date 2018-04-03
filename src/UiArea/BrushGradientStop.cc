#include "../../ui.h"
#include "../ui-node.h"

BrushGradientStop::BrushGradientStop(double pos, Color color) : c(color) {
	p = pos;
}

Color BrushGradientStop::getColor() {
	return c;
}

void BrushGradientStop::setColor(Color value) {
	c = value;
}

double BrushGradientStop::getPos() {
	return p;
}

void BrushGradientStop::setPos(double value) {
	p = value;
}
