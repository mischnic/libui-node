#include <ui.h>
#include <ui-node.h>
#include <cstdio>
#include <iostream>

UiEntry entry;

void a(){
	for(int i = 0; i < 100; i++){
		entry.getText();
	}
	std::cout << entry.getText() << "\n";
}

int main(){
	Ui::init();

	UiWindow win("UiEntry example", 320, 320, true);

	entry.onChanged(a);
	entry.setText("Hello!");

	win.setChild(&entry);

	win.show();
	Ui::main();
}
