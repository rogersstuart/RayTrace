#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>
#include <atomic>
#include <thread>

#include "RTCommon.h"
#include "Vec3.h"
#include "Sphere.h"

//[comment]
// This variable controls the maximum recursion depth
//[/comment]
#define MAX_RAY_DEPTH 5

class BasicTracer
{

public:

    static volatile int num_threads;
    static Vec3f* image;
    static bool frame_ready;
    static bool rendering;
    static Vec3f* image_buffer;

    static float sph_1;
    
    static Vec3f trace(
        const Vec3f& rayorig,
        const Vec3f& raydir,
        const std::vector<Sphere>& spheres,
        const int& depth);

    static void render(const std::vector<Sphere>& spheres);

    static void generate_frame();

    static float mix(const float& a, const float& b, const float& mix);

};
