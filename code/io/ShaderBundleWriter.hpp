#pragma once

#include <fstream>
#include <string>
#include "../input_parser/CompileRequest.hpp"

class ShaderBundleWriter {
private:
	std::ofstream stream;
	std::ofstream map_stream;

public:

	void Create(std::string file_path, std::string map_file_path);
	void WriteShader(const ShaderCompileRequest& request);
};