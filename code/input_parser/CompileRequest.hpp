#pragma once

#include <string>
#include "../ShaderStages.hpp"

class ShaderCompileRequest {
public:
	std::string name;

	std::string glslPath;
	std::string hlslPath;
};

class CompiledShader {
	ShaderStagesBits mStage;
	ShaderAPI api;

	unsigned char* binary;
	unsigned int size;
};
