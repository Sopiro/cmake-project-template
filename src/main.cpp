#if defined(_WIN32)
#include <crtdbg.h>
#endif

#include "project/project.h"

using namespace muli;

int main()
{
#if defined(_WIN32)
    // Enable memory-leak reports
    _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG));
#endif
    std::srand(static_cast<uint32_t>(std::time(0)));

    WorldSettings settings;
    World world = World(settings);
    RigidBody* b = world.CreateBox(1.0f);

    printf("mass: %.4f\n", b->GetMass());
    printf("moment of inertia: %.4f\n", b->GetInertia());
    Vec2 pos = b->GetPosition();
    printf("initial position: %.4f, %.4f\n", pos.x, pos.y);

    float hz = 3000.0f;
    float dt = 1.0f / hz;
    float t = 10.0f;

    for (int i = 0; i < t * hz; ++i)
    {
        world.Step(dt);
    }

    pos = b->GetPosition();
    printf("%.2f second after: %.4f, %.4f\n", t, pos.x, pos.y);
    printf("S = 0.5 * G * t^2: %.4f\n\n", 0.5f * 10.0f * t * t);

    return 0;
}
