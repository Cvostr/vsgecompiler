#include "ShaderBundleWriter.hpp"

void ShaderBundleWriter::Create(std::string file_path, std::string map_file_path) {
	stream.open(file_path);
	map_stream.open(map_file_path);
}

void ShaderBundleWriter::WriteShader(const ShaderCompileRequest& request) {

}