#include <ui.h>
#include <ui-node.h>
#include <cstdio>
#include <iostream>

#include <sys/time.h>
#include <sys/resource.h>

long getMemoryUsage() 
{
  struct rusage usage;
  if(0 == getrusage(RUSAGE_SELF, &usage))
    return usage.ru_maxrss; // bytes
  else
    return 0;
}

UiEntry entry;

void a(int max){
	for(int i = 0; i < max; i++){
		entry.getText();
		// printf("%d\n", i);
		std::cout << getMemoryUsage() << "\n";
	}
	std::cout << entry.getText() << "\n";
}

int main(){
	// Ui::init();

	UiWindow win("UiEntry example", 320, 320, true);

	// entry.onChanged(a);
	entry.setText("kasdjklasdjkladsjkladsjkldasjkldsajkldasjlkdasjkladsljkajkldsjkladsHelloadsjksadjklsadjklasdjklsadjlkasdjlkadjslkjlkadsjlkasdjlkasdjklasdjkladsjkladsjkldasjkldsajkldasjlkdasjkladsljkajkldsjkladsHelloadsjksadjklsadjklasdjklsadjlkasdjlkadjslkjlkadsjlkasdjlkasdjklasdjkladsjkladsjkldasjkldsajkldasjlkdasjkladsljkajkldsjkladsHelloadsjksadjklsadjklasdjklsadjlkasdjlkadjslkjlkadsjlkasdjlkasdjklasdjkladsjkladsjkldasjkldsajkldasjlkdasjkladsljkajkldsjkladsHelloadsjksadjklsadjklasdjklsadjlkasdjlkadjslkjlkadsjlkasdjlkasdjklasdjkladsjkladsjkldasjkldsajkldasjlkdasjkladsljkajkldsjkladsHelloadsjksadjklsadjklasdjklsadjlkasdjlkadjslkjlkadsjlkasdjlkasdjklasdjkladsjkladsjkldasjkldsajkldasjlkdasjkladsljkajkldsjkladsHelloadsjksadjklsadjklasdjklsadjlkasdjlkadjslkjlkadsjlkasdjlkasdjklasdjkladsjkladsjkldasjkldsajkldasjlkdasjkladsljkajkldsjkladsHelloadsjksadjklsadjklasdjklsadjlkasdjlkadjslkjlkadsjlkasdjlkasdjklasdjkladsjkladsjkldasjkldsajkldasjlkdasjkladsljkajkldsjkladsHelloadsjksadjklsadjklasdjklsadjlkasdjlkadjslkjlkadsjlkasdjlkasdjklasdjkladsjkladsjkldasjkldsajkldasjlkdasjkladsljkajkldsjklads!");

	// win.setChild(&entry);

	a(100);


	// win.show();
	// Ui::main();
}
