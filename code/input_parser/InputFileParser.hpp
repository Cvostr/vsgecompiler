#pragma once

#include "../base.hpp"
#include "CompileRequest.hpp"
#include <vector>

class RequestedShader {
public:
	std::string file_path;
	std::string file_name;
	std::string file_ext;
};

class InputFileContents {
public:
	std::string outputFile;
	std::string mapFile;
	std::vector<RequestedShader> shaders;

	InputFileContents() {
		outputFile = "shaders.bundle";
		mapFile = "shaders.map";
	}
};

bool ParseInputFile(const char* file_path, InputFileContents& contents);