#include <iostream>
#include "io/FileLoader.hpp"
#include "input_parser/InputFileParser.hpp"
#include "compilers/glsl_compiler.hpp"
#include "io/ShaderBundleWriter.hpp"

using namespace std;

int main(int argc, char** argv) {
	cout << "VSGE shader compiler v1.0" << endl;

	InputFileContents ifc;
	ParseInputFile("input.txt", ifc);

	ShaderBundleWriter writer;
	writer.Create(ifc.outputFile, ifc.mapFile);

	cout << "Shaders to compile " << ifc.shaders.size() << endl;

	for (auto shader : ifc.shaders) {
		cout << "Compiling shader " << shader.file_name << endl;

		char* data = nullptr;
		unsigned int size = 0;

		bool result = LoadFile(shader.file_path, &data, &size, true);
		if (!result) {
			cout << "Error loading shader file " << shader.file_path << endl;
			continue;
		}
		unsigned char* out = nullptr;
		unsigned int out_size;
		CompileFromGLSL(data, GetStageBit(shader.file_ext), &out, out_size);

		writer.WriteShader(out, out_size, shader.file_name);
	}
	
#ifdef _WIN32
	system("pause");
#endif

}