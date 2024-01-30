#include "test_helpers.hpp"
#include <catch2/catch_test_macros.hpp>
#include <Approvals.h>
#include <cmath>
#include <cstddef>
#include <numbers>
#include <sstream>

std::string test_helpers::floatToStringWithXDecimalDigits(
    float const number, unsigned number_of_decimal_digits)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(static_cast<int>(number_of_decimal_digits)) << number;
    return stream.str();
}

std::vector<float> test_helpers::createInputWithSine(float frequency_hz, float sampling_rate_hz)
{
    std::vector<float> input;
    auto const number_of_samples = static_cast<std::size_t>(sampling_rate_hz);
    input.resize(number_of_samples, 0.0f);

    for (auto i = 0u; i != number_of_samples; ++i) {
        auto const t = static_cast<float>(i) / sampling_rate_hz;
        input[i] = std::sin(t * static_cast<float>(std::numbers::pi) * 2.0f * frequency_hz);
    }

    return input;
}

TEST_CASE("generate test data")
{
    for (auto const freq : { 1.0f, 5.0f, 5000.0f }) {
        SECTION("sin f " + test_helpers::floatToStringWithXDecimalDigits(freq, 0))
        {
            auto const generated_waveform = test_helpers::createInputWithSine(freq, 44100.0f);
            ApprovalTests::Approvals::verifyAll(generated_waveform);
        }
    }
}
