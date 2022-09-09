#include "test/test.h"
#include <crtdbg.h>

using namespace spe;

int main(int argc, char** argv)
{
#if defined(_WIN32)
    // Enable memory-leak reports
    _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG));
#endif
    std::srand(static_cast<uint32_t>(std::time(0)));

    WorldSettings s;

    World w = World(s);
    auto b = w.CreateBox(1.0f);

    printf("mass: %.4f\n", b->GetMass());
    printf("moment of inertia: %.4f\n", b->GetInertia());
    Vec2 pos = b->GetPosition();
    printf("initial position: %.4f, %.4f\n", pos.x, pos.y);

    w.Step(1.0f / 60.0f);

    pos = b->GetPosition();
    printf("one step after: %.4f, %.4f\n\n", pos.x, pos.y);

    Vec2 closestPoint = get_closest_point(b, Vec2{ 0.0f, 10.0f });
    printf("%.4f, %.4f\n", closestPoint.x, closestPoint.y);
    printf("%.4f\n", compute_distance(b, Vec2{ 0.0f, 10.0f }));

    return 0;
}
