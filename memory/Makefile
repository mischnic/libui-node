CC=clang
CXX=clang++

CPPFLAGS=-I../src -I.. -std=c++11 -O0

test: libui-node.dylib test.o
	${CXX} test.o -o $@ ${CPPFLAGS} -lui-node -L. -rpath '@loader_path/..' -g

%.o : %.mm
	${CXX} $^ -c -o $@ -g

# ../src/UiFontButton.o ../src/UiArea/DrawTextFont.o ../src/UiArea/DrawTextFontDescriptor.o ../src/UiArea/DrawTextFontMetrics.o ../src/UiArea/DrawTextLayout.o ../src/UiArea/UiArea.o ../src/UiArea/DrawStrokeParams.o ../src/UiArea/UiDrawContext.o ../src/UiArea/UiDrawPath.o ../src/UiArea/DrawBrush.o ../src/UiArea/DrawMatrix.o ../src/UiArea/BrushGradientStop.o ../src/UiArea/UiAreaDrawParams.o ../src/UiArea/UiAreaKeyEvent.o ../src/UiArea/UiAreaMouseEvent.o ../src/UiArea/UiAreaHandler.o 
# ../src/SizeDouble.o ../src/PointDouble.o ../src/UiGrid.o ../src/UiForm.o ../src/Point.o ../src/Color.o ../src/UiColorButton.o ../src/UiDialogs.o ../src/UiMenu.o ../src/UiCombobox.o ../src/UiSlider.o ../src/UiSpinbox.o ../src/UiCheckbox.o ../src/UiMultilineEntry.o ../src/UiRadioButtons.o ../src/UiEditableCombobox.o ../src/UiGroup.o ../src/UiTab.o ../src/UiBox.o ../src/UiDateTimePicker.o ../src/UiSeparator.o ../src/UiProgressBar.o ../src/UiLabel.o ../src/UiButton.o
libui-node.dylib: ../src/Ui.o ../src/UiControl.o ../src/UiWindow.o ../src/UiEntry.o ../src/Size.o ../src/EventLoop.o ../src/arch/darwin/libui_loop.o
	${CXX} $^ -o $@ -shared -lui -L.. -framework Cocoa -luv -g

clean:
	rm ../src/Ui.o ../src/UiControl.o ../src/UiWindow.o ../src/UiEntry.o ../src/Size.o ../src/EventLoop.o ../src/arch/darwin/libui_loop.o
	rm libui-node.dylib test