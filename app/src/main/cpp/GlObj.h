#ifndef CPPMD2VIEWER_GLOBJ_H
#define CPPMD2VIEWER_GLOBJ_H

#include <map>
#include <string>
#include <array>
#include <unordered_map>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include "Md2Parts.h"

enum class EShaderType : int {
    VERTEX_SHADER = 0,
    FRAGMENT_SHADER,
};

using RetShaderAttribs = std::tuple<bool, std::unordered_map<int, std::pair<int, int>>, GLuint, GLuint, GLuint, GLuint>;

class GlObj {
public:
    /* OpenGL������ */
    static void GlInit();
    /* Texture������ */
    static std::tuple<bool, GLuint> LoadShaders(const std::string &vshstrdata, const std::string &fshstrdata);
    static RetShaderAttribs setAttribute(GLuint programId, int totalframes,
                                         const std::vector<vertex> &vertexs, const std::vector<mesh> &polyIndexs, const std::vector<texstcoord> &sts);
    static void DeleteShaders(GLuint programId);
    static void activeTexture(GLenum texture);
    static void bindTexture(GLenum target, GLuint textureid);

private:
    static bool CheckCompileErrors(GLuint sid, EShaderType type);
    static bool CheckLinkError(GLuint programId);
    static std::map<std::string, GLint>     mUniformLocations;
};
#endif //CPPMD2VIEWER_GLOBJ_H