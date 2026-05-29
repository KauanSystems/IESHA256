# pragma once

# include <fstream>
# include <string>
# include <string_view>
# include <iomanip>
# include <sstream>

extern "C" {
	# include "sha256.h"
}

void ql(int i) { std::cout << "\n"; }

std::string Hash_Sha256(std::string_view File_Path) {

	std::ifstream File(std::string(File_Path), std::ios::binary);
	
	if (!File.is_open()) { return ""; }
	
	SHA256_CTX Ctx;
	unsigned char hash[32];
	
	sha256_init(&Ctx);
	
	const size_t Size_Buffer = 4096;
	std::array<char, Size_Buffer> Buffer;
	
	while (File.read(Buffer.data(), Buffer.size()) || File.gcount() > 0) {
		std::streamsize Bytes_Read = File.gcount();
		sha256_update(&Ctx, reinterpret_cast<const unsigned char*>(Buffer.data()), Bytes_Read);
	}
    
    sha256_final(&Ctx, hash);
    
    std::stringstream ss;
    	for (int i = 0; i < 32; i++) {
    		ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int> (hash[i]);
    	}
    return ss.str();
}
