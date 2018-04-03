#include "../../ui.h"
#include "../ui-node.h"

UiDrawMatrix::UiDrawMatrix() {
	m = new uiDrawMatrix();
}

double UiDrawMatrix::getM11() {
	return m->M11;
}


uiDrawMatrix* UiDrawMatrix::getStruct() {
	return m;
}

double UiDrawMatrix::getM12() {
	return m->M12;
}

double UiDrawMatrix::getM21() {
	return m->M21;
}

double UiDrawMatrix::getM22() {
	return m->M22;
}

double UiDrawMatrix::getM31() {
	return m->M31;
}

double UiDrawMatrix::getM32() {
	return m->M32;
}

void UiDrawMatrix::setM11(double value) {
	m->M11 = value;
}

void UiDrawMatrix::setM12(double value) {
	m->M12 = value;
}

void UiDrawMatrix::setM21(double value) {
	m->M21 = value;
}

void UiDrawMatrix::setM22(double value) {
	m->M22 = value;
}

void UiDrawMatrix::setM31(double value) {
	m->M31 = value;
}

void UiDrawMatrix::setM32(double value) {
	m->M32 = value;
}

void UiDrawMatrix::setIdentity() {
	uiDrawMatrixSetIdentity(m);
}

void UiDrawMatrix::translate(double x, double y) {
	uiDrawMatrixTranslate(m, x, y);
}

void UiDrawMatrix::scale(double xCenter, double yCenter, double x, double y) {
	uiDrawMatrixScale(m, xCenter, yCenter, x, y);
}

void UiDrawMatrix::rotate(double x, double y, double amount) {
	uiDrawMatrixRotate(m, x, y, amount);
}

void UiDrawMatrix::skew(double x, double y, double xamount, double yamount) {
	uiDrawMatrixSkew(m, x, y, xamount, yamount);
}

void UiDrawMatrix::multiply(UiDrawMatrix *src) {
	uiDrawMatrixMultiply(m, src->getStruct());
}

int UiDrawMatrix::invertible() {
	return uiDrawMatrixInvertible(m);
}

int UiDrawMatrix::invert() {
	return uiDrawMatrixInvert(m);
}

PointDouble UiDrawMatrix::transformPoint() {
	double x;
	double y;
	uiDrawMatrixTransformPoint(m, &x, &y);
	return PointDouble(x, y);
}

SizeDouble UiDrawMatrix::transformSize() {
	double x;
	double y;
	uiDrawMatrixTransformSize(m, &x, &y);
	return SizeDouble(x, y);
}






