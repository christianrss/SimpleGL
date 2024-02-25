#pragma once
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <glm/glm.hpp>

GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);