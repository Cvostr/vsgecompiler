#include "ShaderBundleWriter.hpp"

void ShaderBundleWriter::Create(std::string file_path, std::string map_file_path) {
	stream.open(file_path, std::ios::binary);
	map_stream.open(map_file_path, std::ios::binary);
}

void ShaderBundleWriter::WriteShader(unsigned char* data, unsigned int size, std::string name){
	//write data to bundle stream
	stream.write((const char*)data, size);
	//write shader info to map stream
	map_stream << name << '\0';
	map_stream.write((const char*)&written_bytes, sizeof(unsigned int));
	written_bytes += size;
	map_stream.write((const char*)&size, sizeof(unsigned int));
}

void ShaderBundleWriter::Close() {
	map_stream.close();
	stream.close();
}