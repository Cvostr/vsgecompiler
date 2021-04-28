#pragma once

#include "../base.hpp"

#include "../ShaderStages.hpp"

bool CompileFromGLSL(const char* shader_data, ShaderStagesBits stage, byte** out, uint32& spv_size);