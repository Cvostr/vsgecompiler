#include "InputFileParser.hpp"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void GetFileName(std::string& str) {
	std::string old = str;
	str.clear();
	int last_slash = static_cast<int>(old.size()) - 1;
	while (old[last_slash] != '/')
		last_slash--;
	for (int i = last_slash + 1; i < old.size(); i++) {
		str.push_back(old[i]);
	}
}

std::string GetFileExt(std::string str) {
	std::string old = str;
	str.clear();
	int last_slash = static_cast<int>(old.size()) - 1;
	while (old[last_slash] != '.')
		last_slash--;

	std::string result;
	for (unsigned int r_i = last_slash; r_i < old.size(); r_i++) {
		result.push_back(old[r_i]);
	}

	return result;
}

bool ParseInputFile(const char* file_path, InputFileContents& contents) {
	ifstream stream;

	stream.open(file_path, ifstream::ate);

	if (stream.fail()) {
		return false;
	}

	stream.seekg(0);

	stringstream sstr;
	sstr << stream.rdbuf();

	string prefix;

	while (!sstr.eof()) {
		sstr >> prefix;

		if (prefix.compare("outputFile") == 0) {
			sstr >> contents.outputFile;
		}

		if (prefix.compare("mapFile") == 0) {
			sstr >> contents.mapFile;
		}

		if (prefix.compare("shader") == 0) {
			RequestedShader shader;
			sstr >> shader.file_path;
			shader.file_name = shader.file_path;
			GetFileName(shader.file_name);
			shader.file_ext = GetFileExt(shader.file_name);

			contents.shaders.push_back(shader);
		}
	}
	return true;
}