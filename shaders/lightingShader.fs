#version 330 core
out vec4 FragColor;

in vec3 fragPos;
in vec3 normal;
in vec2 UV;

// Material Struct
struct Material
{
    sampler2D texture_diffuse;
    sampler2D texture_specular;

    float shininess;
};

// Lighting Structs
struct DirLight
{
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight
{
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};
#define MAX_POINT_LIGHTS 32

struct SpotLight
{
    vec3 position;
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float cutOff;
    float outerCutOff;

    float constant;
    float linear;
    float quadratic;
};

vec3 calcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 calcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 calcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

uniform vec3 viewPos;
uniform Material material;

uniform DirLight dirLight;
uniform int nrPointLights;
uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform SpotLight spotLight;

uniform float alpha;

void main()
{
    // Properties
    vec3 norm = normalize(normal);
    vec3 viewDir = normalize(viewPos - fragPos);

    // Directional Lighting
    vec3 result = calcDirLight(dirLight, norm, viewDir);
    // Point Lights
    for(int i = 0; i < nrPointLights; ++i)
        result += calcPointLight(pointLights[i], norm, fragPos, viewDir);
    // Spot Lights
    result += calcSpotLight(spotLight, norm, fragPos, viewDir);
    
    FragColor = vec4(result, alpha);
}

vec3 calcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    // Diffuse Shading
    float diff = max(dot(normal, lightDir), 0.0f);
    // Specular Shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
    // Final Shading
    vec3 ambient  = light.ambient  * vec3(texture(material.texture_diffuse, UV));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.texture_diffuse, UV));
    vec3 specular = light.specular * spec * vec3(texture(material.texture_specular, UV));
    return (ambient + diffuse + specular);
}

vec3 calcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // Diffuse Shading
    float diff = max(dot(normal, lightDir), 0.0f);
    // Specular Shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
    // Attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    // Final Shading
    vec3 ambient  = light.ambient  * vec3(texture(material.texture_diffuse, UV));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.texture_diffuse, UV));
    vec3 specular = light.specular * spec * vec3(texture(material.texture_specular, UV));
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}

vec3 calcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // Diffuse Shading
    float diff = max(dot(normal, lightDir), 0.0f);
    // Specular Shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
    // Soft Edges
    float theta = dot(lightDir, normalize(-light.direction));
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0f, 1.0f);
    // Attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    // Final Shading
    vec3 ambient  = light.ambient  * vec3(texture(material.texture_diffuse, UV));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.texture_diffuse, UV));
    vec3 specular = light.specular * spec * vec3(texture(material.texture_specular, UV));
    diffuse  *= intensity;
    specular *= intensity;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}
