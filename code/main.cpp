#include <iostream>
#include "io/FileLoader.hpp"
#include "input_parser/InputFileParser.hpp"

using namespace std;

int main(int argc, char** argv) {
	cout << "VSGE shader compiler v1.0" << endl;

	InputFileContents ifc;
	ParseInputFile("input.txt", ifc);

	for (auto shader : ifc.requests) {
		char* data = nullptr;
		unsigned int size = 0;

		LoadFile(shader.glslPath, &data, &size);
	}

	cout << "Shaders to compile " << ifc.requests.size() << endl;
}