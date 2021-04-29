#include "ShaderStages.hpp"

ShaderStagesBits GetStageBit(std::string ext) {
	if (ext == ".vert")
		return SHADER_STAGE_VERTEX;
	else if (ext == ".frag")
		return SHADER_STAGE_FRAGMENT;
	else if (ext == ".geom")
		return SHADER_STAGE_GEOMETRY;
	else if (ext == ".comp")
		return SHADER_STAGE_COMPUTE;

	return SHADER_STAGE_NULL;
}