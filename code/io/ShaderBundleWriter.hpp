#pragma once

#include <fstream>
#include <string>
#include "../input_parser/CompileRequest.hpp"

class ShaderBundleWriter {
private:
	std::ofstream stream;
	std::ofstream map_stream;

	unsigned int written_bytes;

public:

	ShaderBundleWriter() {
		written_bytes = 0;
	}

	~ShaderBundleWriter() {
		stream.close();
		map_stream.close();
	}

	void Create(std::string file_path, std::string map_file_path);
	void WriteShader(unsigned char* data, unsigned int size, std::string name);
};