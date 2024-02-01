#include "test_helpers.hpp"
#include <catch2/catch_test_macros.hpp>
#include <filter_lib/fo_apf.hpp>
#include <Approvals.h>

TEST_CASE("FO APF does not affect intensity of any frequency")
{
    FO_APF filter;

    for (auto const filter_frequency : { 10.0f, 100.0f, 1000.0f, 10000.0f }) {
        SECTION("Filter Frequency "
            + test_helpers::floatToStringWithXDecimalDigits(filter_frequency, 0))
        {
            constexpr auto sampling_rate_hz = 44100.0f;
            filter.calculate_coeffs(filter_frequency, sampling_rate_hz);

            auto const input = test_helpers::createInputWithSine(5000.0f, 44100.0f);

            std::vector<float> output;
            output.resize(input.size(), 0.0f);

            for (auto i = 0u; i != input.size(); ++i) {
                output[i] = filter.process(input[i]);
            }

            constexpr float epsilon { 0.04f };
            auto const integral = test_helpers::integrate(output, 44100.0f);
            REQUIRE(abs(integral) < epsilon);
            auto const max = *std::max_element(output.cbegin(), output.cend());
            auto const min = *std::min_element(output.cbegin(), output.cend());
            REQUIRE(std::abs(max - 1.0f) < 4 * epsilon);
            REQUIRE(std::abs(min + 1.0f) < 4 * epsilon);
        }
    }
}
