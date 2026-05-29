# include <iostream>
# include <span>
# include <fstream>
# include <string>

# include "hash.hpp"

void ql(int i) { std::cout << "\n"; }

int main (int quantidade, char* parametros[]) {

auto args = std::span(parametros, quantidade);
auto pass = args.subspan(1);

ql(1);

for (const char* p : pass) {
	if (std::ifstream file(p); !file.is_open()) {
		std::cout << "· File: " << p << " NOT Exists.\n";
	} else {
		std::string Hash_Arquivo = calcular_sha256(p);
		
		std::cout << "· Arquivo: " << p << "\n";
		std::cout << "· SHA-256: " << Hash_Arquivo << "\n\n";	
	}
}

return 0;
}
