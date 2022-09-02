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

    Settings s;

    World w = World(s);
    auto b = w.CreateBox(1.0f);

    std::cout << "mass: " << b->GetMass() << '\n';
    std::cout << "moment of inertia: " << b->GetInertia() << '\n';
    std::cout << "initial position: " << *b->position << '\n';

    w.Step(1.0f / 60.0f);

    std::cout << "one step after: " << *b->position << '\n';

    std::cout << *get_closest_point(b, { 0.0f, 10.0f }) << '\n';
    std::cout << compute_distance(b, { 0.0f, 10.0f }) << '\n';

    return 0;
}
