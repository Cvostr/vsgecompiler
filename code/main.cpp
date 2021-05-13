#include <iostream>
#include "io/FileLoader.hpp"
#include "input_parser/InputFileParser.hpp"
#include "compilers/glsl_compiler.hpp"
#include "io/ShaderBundleWriter.hpp"
#include "ShaderStages.hpp"

using namespace std;

int main(int argc, char** argv) {
	cout << "VSGE shader compiler v1.0" << endl;

	std::string win32_wait = "true";

	std::string input_file_str = "input.txt";
	if (argc == 2)
		input_file_str = std::string(argv[1]);
	if (argc == 3)
		win32_wait = std::string(argv[1]);

	InputFileContents ifc;
	bool result = ParseInputFile(input_file_str.c_str(), ifc);

	if (!result) {
		std::cout << "Error loading file " << input_file_str << endl;
		return 1;
	}

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

		cout << "\t Shader type " << GetStageBit(shader.file_ext) << endl;
		unsigned char* out = nullptr;
		unsigned int out_size;
		result = CompileFromGLSL(data, GetStageBit(shader.file_ext), &out, out_size);

		if (!result) {
			cout << "Error compiling shader, skipping" << endl;
			continue;
		}

		cout << "\t Output size " << out_size << " bytes" << endl;

		writer.WriteShader(out, out_size, shader.file_name);
	}
	writer.Close();
	
#ifdef _WIN32
	if(win32_wait == "true")
		system("pause");
#endif

}