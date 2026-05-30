# pragma once

# include <fstream>
# include <string>
# include <string_view>
# include <iomanip>
# include <sstream>
# include <optional>
# include <format>

# include "sha256.h"

inline std::optional<std::string> Hash_Sha256(const char* File_Path) {

	std::ifstream File(File_Path, std::ios::binary);
	
	if (!File.is_open()) { return std::nullopt; }
	
	SHA256_CTX Ctx;
	unsigned char hash[SHA256_BLOCK_SIZE];
	
	sha256_init(&Ctx);
	
	const size_t Size_Buffer = 4096;
	std::array<char, Size_Buffer> Buffer;
	
	while (File.read(Buffer.data(), Buffer.size()) || File.gcount() > 0) {
		std::streamsize Bytes_Read = File.gcount();
		sha256_update(&Ctx, reinterpret_cast<const unsigned char*>(Buffer.data()), Bytes_Read);
	}
    
    sha256_final(&Ctx, hash);
    
    std::stringstream ss;
	for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
		ss << std::format("{:02x}",hash[i]);
	}
	return ss.str();
}
