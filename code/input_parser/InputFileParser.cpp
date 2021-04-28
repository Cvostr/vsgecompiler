#include "InputFileParser.hpp"
#include <fstream>
#include <sstream>

using namespace std;

bool ParseInputFile(const char* file_path, InputFileContents& contents) {
	ifstream stream;

	stream.open(file_path, ifstream::ate);

	if (stream.fail()) {
		return false;
	}

	uint32 size = stream.tellg();
	char* data = new char[size];
	stream.seekg(0);
	stream.read(data, size);

	stringstream sstr;
	sstr.write((const char*)data, size);

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
			ShaderCompileRequest request;
			while (prefix.compare("end")) {
				sstr >> prefix;
				if (prefix.compare("name") == 0) {
					sstr >> request.name;
				}
				if (prefix.compare("glsl") == 0) {
					sstr >> request.glslPath;
				}
				if (prefix.compare("hlsl") == 0) {
					sstr >> request.hlslPath;
				}
			}
			contents.requests.push_back(request);
		}
	}

}