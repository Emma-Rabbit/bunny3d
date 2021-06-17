#include "ShaderLoader.hpp"
#include <fstream>
#include <iostream>

std::string ShaderLoader::LoadCode(std::filesystem::path filepath){
    std::ifstream file(filepath);
    if(!file.is_open()){
        std::cout << "Could not open shader source file!\n";
        throw 1;
    }
    std::string code, data;
    while(getline(file, data)){
        data.push_back('\n');
        code.append(data);
    }
    return code;
}

GLuint ShaderLoader::Compile(GLuint type, std::string& source){
    GLuint id = glCreateShader(type); //create empty shader object and return handler
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr); //set source for shader
    glCompileShader(id);//compile

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE){ //error handling
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char message[length];
        //char* message = (char*)alloca(length*sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader\n";
        std::cout << message << "\n";
        glDeleteShader(id);
        return 0;
    }
    return id;
}

void ShaderLoader::LoadShader(GLuint type, std::filesystem::path filepath){
    std::string code = LoadCode(filepath);
    GLuint shader = Compile(type, code);
    std::string key = filepath.stem();
    if(shader == 0){
        throw 0;
    }
    switch(type){
        case GL_VERTEX_SHADER:
            verShaders[key] = shader;
            break;
        case GL_FRAGMENT_SHADER:
            fragShaders[key] = shader;
            break;
    }
}

GLuint ShaderLoader::getShader(GLuint type, std::string key){
    std::map<const std::string, GLuint> shaders;
    switch(type){
        case GL_VERTEX_SHADER:
            shaders = verShaders;
            break;
        case GL_FRAGMENT_SHADER:
            shaders = fragShaders;
            break;
    }
    return shaders[key];
}