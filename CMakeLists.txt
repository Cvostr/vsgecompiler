cmake_minimum_required (VERSION 3.14)

project ("VSGECompiler")

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRC_FILES "code/*.cpp")
file(GLOB_RECURSE HEADER_FILES "code/*.hpp")

include_directories("vendor/headers/" REQUIRED)

add_executable (compiler ${SRC_FILES} ${HEADER_FILES})
IF (WIN32)
#Static Libs linkage
set(STATIC_LIBS_DIR  ${CMAKE_SOURCE_DIR}/vendor/static-x64/win)

target_link_libraries(compiler ${STATIC_LIBS_DIR}/vulkan/vulkan-1.lib)

#if (CMAKE_BUILD_TYPE EQUAL "DEBUG")
target_link_libraries(compiler ${STATIC_LIBS_DIR}/glslang/dbg/glslangd.lib)
target_link_libraries(compiler ${STATIC_LIBS_DIR}/glslang/dbg/SPIRVd.lib)
target_link_libraries(compiler ${STATIC_LIBS_DIR}/glslang/dbg/SPVRemapperd.lib)
target_link_libraries(compiler ${STATIC_LIBS_DIR}/glslang/dbg/MachineIndependentd.lib)
target_link_libraries(compiler ${STATIC_LIBS_DIR}/glslang/dbg/OGLCompilerd.lib)
target_link_libraries(compiler ${STATIC_LIBS_DIR}/glslang/dbg/OSDependentd.lib)
target_link_libraries(compiler ${STATIC_LIBS_DIR}/glslang/dbg/GenericCodeGend.lib)

#Win32 libs
target_link_libraries(compiler winmm.lib)
target_link_libraries(compiler Setupapi.lib)
target_link_libraries(compiler Version.lib)
target_link_libraries(compiler Imm32.lib)

target_link_libraries(compiler d3d12.lib)
#target_link_libraries(EngineTest d3dcompiler.lib)

ENDIF()

IF(UNIX)
set(STATIC_LIBS_DIR  ${CMAKE_SOURCE_DIR}/vendor/static-x64/linux)
target_link_libraries(compiler ${STATIC_LIBS_DIR}/vulkan/vulkan-1.lib)

target_link_libraries(compiler ${CMAKE_DL_LIBS})
target_link_libraries(compiler pthread)

target_link_libraries(compiler ${STATIC_LIBS_DIR}/glslang/libglslang.a)
target_link_libraries(compiler ${STATIC_LIBS_DIR}/glslang/libSPIRV.a)
target_link_libraries(compiler ${STATIC_LIBS_DIR}/glslang/libSPVRemapper.a)
target_link_libraries(compiler ${STATIC_LIBS_DIR}/glslang/libMachineIndependent.a)
target_link_libraries(compiler ${STATIC_LIBS_DIR}/glslang/libOGLCompiler.a)
target_link_libraries(compiler ${STATIC_LIBS_DIR}/glslang/libOSDependent.a)
target_link_libraries(compiler ${STATIC_LIBS_DIR}/glslang/libGenericCodeGen.a)


ENDIF()
