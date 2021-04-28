#pragma once

#include "../base.hpp"
#include "CompileRequest.hpp"
#include <vector>

class InputFileContents {
public:
	std::string outputFile;
	std::string mapFile;
	std::vector<ShaderCompileRequest> requests;
};

bool ParseInputFile(const char* file_path, InputFileContents& contents);