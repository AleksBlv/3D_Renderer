#include "ShaderProgram.h"
#include "Matrices.h"


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
    bindAttributes();
    glLinkProgram(progID);

    glGetProgramiv(progID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(progID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    getAllUniformLocations();
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
        // ��������� �����
        ShaderFile.open(Path);

        std::stringstream vShaderStream, fShaderStream;
        // ��������� ������ � ������
        vShaderStream << ShaderFile.rdbuf();

        // ��������� �����
        ShaderFile.close();

        // ��������������� ������ � ������ GLchar
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

GLuint ShaderProgram::getUniformLocation(const GLchar* uniformName)
{
    return glGetUniformLocation(progID, uniformName);
    
}

void ShaderProgram::bindAttributes()
{
    bindAttribute(0, "position");
    bindAttribute(1, "texCoord");
    bindAttribute(2, "normal");
}

void ShaderProgram::bindAttribute(int attrib,const GLchar* attribName)
{
    glBindAttribLocation(progID, attrib, attribName);
}

void ShaderProgram::getAllUniformLocations()
{
    location_TransformationMatrix = getUniformLocation("transformation_matrix");
    location_ProjectionMatrix = getUniformLocation("projection_matrix");
    location_ViewMatrix = getUniformLocation("view_matrix");
    location_LightPosition = getUniformLocation("light_position");
    location_LightColor = getUniformLocation("light_color");
    location_ShineDumper = getUniformLocation("shineDumper");
    location_Reflectivity = getUniformLocation("reflectivity");
}

void ShaderProgram::loadVec4(int location, float x, float y, float z, float alpha)
{
    glUniform4f(location, x, y, z, alpha);
}

void ShaderProgram::loadVec3f(int location, glm::vec3 vec)
{
    glUniform3f(location, vec.x, vec.y, vec.z);
}

void ShaderProgram::load1f(int location, float x)
{
    glUniform1f(location, x);
}

void ShaderProgram::loadMat4x4(int location, const GLfloat* matrix)
{
    glUniformMatrix4fv(location, 1, GL_FALSE, matrix);
    
}

void ShaderProgram::loadTransformationMatrix(const GLfloat* transformMatrix)
{
    loadMat4x4(location_TransformationMatrix, transformMatrix);
}

void ShaderProgram::loadProjectionMatrix(const GLfloat* projectionMatrix)
{
    loadMat4x4(location_ProjectionMatrix, projectionMatrix);
}

void ShaderProgram::loadViewMatrix(Camera* camera)
{
    glm::mat4x4* viewMatrix = createViewMatrix(camera);
    loadMat4x4(location_ViewMatrix, glm::value_ptr(*viewMatrix));
    delete viewMatrix;
}

void ShaderProgram::loadLight(Light* light)
{
    loadVec3f(location_LightPosition, light->getPosition());
    loadVec3f(location_LightColor, light->getColor());
}

void ShaderProgram::loadShineVariables(float dumper, float reflect)
{
    load1f(location_ShineDumper, dumper);
    load1f(location_Reflectivity, reflect);
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
