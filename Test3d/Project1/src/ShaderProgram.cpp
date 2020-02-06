#include "ShaderProgram.h"


ShaderProgram::ShaderProgram()
{
	progID = glCreateProgram();
}

void ShaderProgram::loadShaders(const GLchar* fPath, const GLchar* vPath)
{
    GLint success;
    GLchar infoLog[512];
    GLuint vid, fid;

    vid = loadAndAttachShader(vPath, GL_VERTEX_SHADER);
    fid = loadAndAttachShader(fPath, GL_FRAGMENT_SHADER);
    glLinkProgram(progID);

    glGetProgramiv(progID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(progID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vid);
    glDeleteShader(fid);

}

GLuint ShaderProgram::loadAndAttachShader(const GLchar* Path, int type)
{
	std::string shaderCode;
	std::ifstream ShaderFile;

    ShaderFile.exceptions(std::ifstream::badbit);

    try
    {
        // Открываем файлы
        ShaderFile.open(Path);

        std::stringstream vShaderStream, fShaderStream;
        // Считываем данные в потоки
        vShaderStream << ShaderFile.rdbuf();

        // Закрываем файлы
        ShaderFile.close();

        // Преобразовываем потоки в массив GLchar
        shaderCode = vShaderStream.str();

    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const GLchar* Code = shaderCode.c_str();

    GLuint shaderID;
    GLint success;
    GLchar infoLog[512];	

    shaderID = glCreateShader(type);
    glShaderSource(shaderID, 1, &Code, NULL);
    glCompileShader(shaderID);

    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
        std::cout << "ERROR:: Shader compilation failed\n" << infoLog << std::endl;
    }

    glAttachShader(progID, shaderID);
    return shaderID;

}

void ShaderProgram::loadVec4(int location, float x, float y, float z, float alpha)
{
    glUniform4f(location, x, y, z, alpha);
}

void ShaderProgram::load1f(int location, float x)
{
    glUniform1f(location, x);
}

void ShaderProgram::loadMat4x4(int location, glm::mat4x4 matrix)
{
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

GLuint ShaderProgram::getProgID()
{
	return progID;
}

void ShaderProgram::Use()
{
    glUseProgram(progID);
}

void ShaderProgram::Stop()
{
    glUseProgram(0);
}
