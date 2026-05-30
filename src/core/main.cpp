# include <iostream>
# include <span>
# include <fstream>
# include <string>

# include "hash.hpp"

int main (int argc, char* argv[]) {

auto const args = std::span(argv + 1, argc - 1);

for (const char* p : args) {
	if (std::ifstream file(p); !file.is_open()) {
		std::cout << "\nFile: " << p << " NOT Exists.\n";
	} else {
		auto Hash_File = Hash_Sha256(p);
		
		std::cout << "\nFile: " << p << "    SHA-256:   " << Hash_File.value() << "\n\n";	
	}
}

return 0;
}
