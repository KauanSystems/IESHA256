# pragma once

# include <fstream>
# include <string>
# include <string_view>
# include <iomanip>
# include <sstream>

extern "C" {
	# include "sha256.h"
}

std::string calcular_sha256(std::string_view Cam_Arquivo) {

	std::ifstream Arquivo(std::string(Cam_Arquivo), std::ios::binary);
	
	if (!Arquivo.is_open()) { return ""; }
	
	SHA256_CTX Ctx;
	unsigned char hash[32];
	
	sha256_init(&Ctx);
	
	const size_t TAM_BUFFER = 4096;
	std::array<char, TAM_BUFFER> buffer;
	
	while (Arquivo.read(buffer.data(), buffer.size()) || Arquivo.gcount() > 0) {
		std::streamsize Bytes_Lidos = Arquivo.gcount();
		sha256_update(&Ctx, reinterpret_cast<const unsigned char*>(buffer.data()), Bytes_Lidos);
	}
    
    sha256_final(&Ctx, hash);
    
    std::stringstream ss;
    	for (int i = 0; i < 32; i++) {
    		ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int> (hash[i]);
    	}
    return ss.str();
}
