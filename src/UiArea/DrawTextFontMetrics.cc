#include "../../ui.h"
#include "../ui-node.h"



DrawTextFontMetrics::DrawTextFontMetrics(uiDrawTextFontMetrics * metrics) {
	m = metrics;
}

double DrawTextFontMetrics::getAscent() {
	return m->Ascent;
}

double DrawTextFontMetrics::getDescent() {
	return m->Descent;
}

double DrawTextFontMetrics::getLeading() {
	return m->Leading;
}

double DrawTextFontMetrics::getUnderlinePos() {
	return m->UnderlinePos;
}

double DrawTextFontMetrics::getUnderlineThickness() {
	return m->UnderlineThickness;
}



