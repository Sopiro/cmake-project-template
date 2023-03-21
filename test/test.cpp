#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "omp.h"
#include <thread>

TEST_CASE("Memory leak check")
{
#if defined(_WIN32) && defined(_DEBUG)
    // Enable memory-leak reports
    _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG));
#endif
}

TEST_CASE("Test 1")
{
    int a = 1;
    int b = 2;
    int c = a + b;

    REQUIRE_EQ(c, 3);
}

TEST_CASE("Test 2")
{
    const int size = 100000;
    int a[size];

    REQUIRE_EQ(omp_get_num_threads(), 1);

#pragma omp parallel
    {
#pragma omp master
        {
            int thread_count = omp_get_num_threads();
            std::cout << "thread count: " << thread_count << std::endl;
            REQUIRE_EQ(thread_count, std::thread::hardware_concurrency());
        }

#pragma omp for schedule(static)
        for (int i = 0; i < size; ++i)
        {
            a[i] = i * i;
        }
    }

    REQUIRE_EQ(a[777], 777 * 777);
}