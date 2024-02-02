#include "tests_common.hpp"

// Text fixture for Class-Under-Test (CUT)
struct fo_lpf : public testing::Test {
    FO_LPF* m_filter;
    Biquad::tp_coeffs m_coeffs;

    void SetUp()
    {
        m_filter = new FO_LPF();
        m_coeffs = m_filter->calculate_coeffs(FC, SAMPLING_RATE);
    }

    void TearDown() { delete m_filter; }
};

TEST_F(fo_lpf, coeff_calculation)
{
    // Assert
    EXPECT_NEAR(m_coeffs.a0, 0.141705, 0.00001);
#ifdef DEBUG_OUTPUT
    debug_print(m_coeffs);
#endif
}

TEST_F(fo_lpf, process_0)
{
    // Act
    auto yn = m_filter->process(TEST_SAMPLE_0);
    // Assert
    EXPECT_DOUBLE_EQ(yn, 0);
#ifdef DEBUG_OUTPUT
    std::cout << "yn: " << yn << std::endl;
#endif
}

TEST_F(fo_lpf, process_1)
{
    // Act
    auto yn = m_filter->process(TEST_SAMPLE_1);
    // Assert
    EXPECT_NEAR(yn, 0.141705, 0.00001);
#ifdef DEBUG_OUTPUT
    std::cout << "yn: " << yn << std::endl;
#endif
}
