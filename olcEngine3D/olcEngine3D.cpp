#include "olcConsoleGameEngine.h"



struct vec3d {
    float x, y, z;
};

struct triangle {
    vec3d p[3];
};

struct mesh {
    std::vector<triangle> tris;
};

class olcEngine3D : public olcConsoleGameEngine {
public:
    olcEngine3D() {
        m_sAppName = L"3D Demo";
    }

private: 
    mesh meshCube;

public:
    bool OnUserCreate() override {
        meshCube.tris = {
            // SOUTH FACE
            {0.0f, 0.0f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 0.0f,   1.0f, 0.0f, 0.0f},

            // EAST FACE
            {1.0f, 0.0f, 0.0f,   1.0f, 1.0f, 0.0f,   1.0f, 1.0f, 1.0f},
            {1.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, 1.0f},

            // NORTH FACE
            {1.0f, 0.0f, 1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f, 1.0f},
            {1.0f, 0.0f, 1.0f,   0.0f, 1.0f, 1.0f,   0.0f, 0.0f, 1.0f},

            // WEST FACE
            {0.0f, 0.0f, 1.0f,   0.0f, 1.0f, 1.0f,   0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f, 0.0f},

            // TOP FACE
            {0.0f, 1.0f, 0.0f,   0.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f},
            {0.0f, 1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 0.0f},

            // BOTTOM FACE
            {1.0f, 0.0f, 1.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 1.0f,   0.0f, 0.0f, 0.0f,   1.0f, 0.0f, 0.0f}
        };
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
        Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_BLACK);
        return true;
    }
};

int main()
{
    olcEngine3D demo;
    
    // Check if you can display the console and start it
    if (demo.ConstructConsole(256, 240, 4, 4)) {
        demo.Start();
    }
}

