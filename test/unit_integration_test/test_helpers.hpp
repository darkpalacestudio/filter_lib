#ifndef TEST_HELPERS_HPP
#define TEST_HELPERS_HPP

#include <iomanip>
#include <string>
#include <vector>

namespace test_helpers {

std::string floatToStringWithXDecimalDigits(float const number, unsigned number_of_decimal_digits);

std::vector<float> createInputWithSine(float frequency_hz, float sampling_rate_hz);

float integrate(std::vector<float> const& data, float sample_rate);

std::string getOSName();

} // namespace test_helpers
#endif // TEST_HELPERS_HPP
