Shader::Shader() {}

Shader::Shader(const String& name)
{
    initShader(name);
}

void Shader::initShader(const String& name)
{
    program = glCreateProgram();

    shaders[VERTEX_SHADER] = createShader(name + ".vs", GL_VERTEX_SHADER);
    shaders[FRAGMENT_SHADER] = createShader(name + ".fs", GL_FRAGMENT_SHADER);

    glAttachShader(program, shaders[VERTEX_SHADER]);
    glAttachShader(program, shaders[FRAGMENT_SHADER]);

    glLinkProgram(program);
    checkErrors(program, true);
}

Shader::~Shader()
{
    glDetachShader(program, shaders[VERTEX_SHADER]);
    glDetachShader(program, shaders[FRAGMENT_SHADER]);

    glDeleteShader(shaders[VERTEX_SHADER]);
    glDeleteShader(shaders[FRAGMENT_SHADER]);

    glDeleteProgram(program);
}

void Shader::use()
{
    glUseProgram(program);
}

void Shader::setBool(const String& name, bool v0)
{
    glUniform1i(glGetUniformLocation(program, name.c_str()), (int)v0);
}
void Shader::setInt(const String& name, int v0)
{
    glUniform1i(glGetUniformLocation(program, name.c_str()), v0);
}
void Shader::setFloat(const String& name, float v0)
{
    glUniform1f(glGetUniformLocation(program, name.c_str()), v0);
}

void Shader::setVec2(const String& name, float v0, float v1)
{
    glUniform2f(glGetUniformLocation(program, name.c_str()), v0, v1);
}
void Shader::setVec3(const String& name, float v0, float v1, float v2)
{
    glUniform3f(glGetUniformLocation(program, name.c_str()), v0, v1, v2);
}
void Shader::setVec4(const String& name, float v0, float v1, float v2, float v3)
{
    glUniform4f(glGetUniformLocation(program, name.c_str()), v0, v1, v2, v3);
}

void Shader::setVec2(const String& name, const glm::vec2& v)
{
    glUniform2f(glGetUniformLocation(program, name.c_str()), v.x, v.y);
}
void Shader::setVec3(const String& name, const glm::vec3& v)
{
    glUniform3f(glGetUniformLocation(program, name.c_str()), v.x, v.y, v.z);
}
void Shader::setVec4(const String& name, const glm::vec4& v)
{
    glUniform4f(glGetUniformLocation(program, name.c_str()), v.x, v.y, v.z, v.w);
}

void Shader::setMat3(const String& name, const glm::mat3& m0)
{
    glUniformMatrix3fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, glm::value_ptr(m0));
}
void Shader::setMat4(const String& name, const glm::mat4& m0)
{
    glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, glm::value_ptr(m0));
}

uint32 Shader::createShader(const String& name, GLenum type)
{
    uint32 shader = glCreateShader(type);

    String shaderCode = loadShader("shaders/" + name);
    const GLchar* shaderSource = shaderCode.c_str();

    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);
    checkErrors(shader, false);

    return shader;
}

String Shader::loadShader(const String& path)
{
    std::cout << path << std::endl;
    String code;
    std::ifstream shaderFile;

    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        shaderFile.open(path.c_str());
        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        code = shaderStream.str();
    }
    catch(std::ifstream::failure e)
    {
        std::cerr << "Error loading shader! " << e.what() << std::endl;
    }

    return code;
}

void Shader::checkErrors(uint32 val, bool isProgram)
{
    int success;
    char infoLog[512];
    if(isProgram)
    {
        glGetProgramiv(val, GL_LINK_STATUS, &success);
        if(!success)
        {
            glGetProgramInfoLog(val, 512, NULL, infoLog);
            std::cerr << "Error Linking Shader Program! : " << infoLog << std::endl;
        }
    }
    else
    {
        glGetShaderiv(val, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(val, 512, NULL, infoLog);
            std::cerr << "Error Compiling Shader! : " << infoLog << std::endl;
        }
    }
}
