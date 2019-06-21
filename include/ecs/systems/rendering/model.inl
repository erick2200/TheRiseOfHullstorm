Model::Model(const std::string& path)
{
    loadModel(path);
}

Model::~Model()
{
    for(size_t i = 0; i < meshes.size(); ++i)
        meshes[i].freeMesh();
}

void Model::render(Shader& shader)
{
    for(size_t i = 0; i < meshes.size(); ++i)
        meshes[i].render(shader);
}

void Model::loadModel(const std::string& path)
{
    Assimp::Importer import;
    const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cerr << "Assimp : Error Loading Model : " << import.GetErrorString() << std::endl;
        return;
    }
    directory = path.substr(0, path.find_last_of('/'));

    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
    for(size_t i = 0; i < node->mNumMeshes; ++i)
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
    }
    for(size_t i = 0; i < node->mNumChildren; ++i)
    {
        processNode(node->mChildren[i], scene);
    }
}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> textures;

    for(size_t i = 0; i < mesh->mNumVertices; ++i)
    {
        Vertex vertex;
        glm::vec3 placeholder;

        placeholder.x = mesh->mVertices[i].x;
        placeholder.y = mesh->mVertices[i].y;
        placeholder.z = mesh->mVertices[i].z;
        vertex.position = placeholder;

        placeholder.x = mesh->mNormals[i].x;
        placeholder.y = mesh->mNormals[i].y;
        placeholder.z = mesh->mNormals[i].z;
        vertex.normal = placeholder;

        if(mesh->mTextureCoords[0])
        {
            glm::vec2 coords;
            coords.x = mesh->mTextureCoords[0][i].x;
            coords.y = mesh->mTextureCoords[0][i].y;
            vertex.UV = coords;
        }
        else
            vertex.UV = glm::vec2(0.0f, 0.0f);
        
        vertices.push_back(vertex);
    }

    for(size_t i = 0; i < mesh->mNumFaces; ++i)
    {
        aiFace face = mesh->mFaces[i];
        for(size_t j = 0; j < face.mNumIndices; ++j)
            indices.push_back(face.mIndices[j]);
    }

    if(mesh->mMaterialIndex >= 0)
    {
        aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

        std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

        std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
        textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    }

    return Mesh(vertices, indices, textures);
}

std::vector<Texture> Model::loadMaterialTextures(aiMaterial* material, aiTextureType type, const std::string& typeName)
{
    std::vector<Texture> textures;

    for(size_t i = 0; i < material->GetTextureCount(type); ++i)
    {
        aiString str;
        material->GetTexture(type, i, &str);
        bool skip = false;
        for(size_t j = 0; j < texturesLoaded.size(); ++j)
        {
            if(std::strcmp(texturesLoaded[j].name.data(), str.C_Str()) == 0)
            {
                textures.push_back(texturesLoaded[j]);
                skip = true;
                break;
            }
        }
        if(!skip)
        {
            Texture texture;
            texture.ID = RenderingSystem::loadTextureFromFile(str.C_Str(), directory, false);
            texture.type = typeName;
            texture.name = str.C_Str();
            textures.push_back(texture);
            texturesLoaded.push_back(texture);
        }
    }

    return textures;
}
