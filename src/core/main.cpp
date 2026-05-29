# include <iostream>
# include <span>
# include <fstream>
# include <string>

# include "hash.hpp"

int main (int argv, char* argc[]) {

auto args = std::span(argc, argv);
auto pass = args.subspan(1);

ql(1);

for (const char* p : pass) {
	if (std::ifstream file(p); !file.is_open()) {
		std::cout << "· File: " << p << " NOT Exists.\n";
	} else {
		std::string Hash_File = Hash_Sha256(p);
		
		std::cout << "File: " << p << "    SHA-256:   " << Hash_File << "\n\n";	
	}
}

return 0;
}
