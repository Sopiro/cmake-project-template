#include <crtdbg.h>

#include "test/test.h"

using namespace muli;

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

    return 0;
}
