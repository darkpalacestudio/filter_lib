#include "tests_common.hpp"

// Text fixture for Class-Under-Test (CUT)
struct so_parametric_cq_boost : public testing::Test {
    SO_PARAMETRIC_CQ_BOOST* m_filter;
    Biquad::CoefficientsType m_coeffs;

    void SetUp()
    {
        m_filter = new SO_PARAMETRIC_CQ_BOOST();
        m_coeffs = m_filter->calculate_coeffs(GAIN, Q_DEF, FC, SAMPLING_RATE);
    }

    void TearDown() { delete m_filter; }
};

TEST_F(so_parametric_cq_boost, coeff_calculation)
{
    // Assert
    EXPECT_NEAR(m_coeffs.a0, 1.02784, 0.00001);
#ifdef DEBUG_OUTPUT
    debug_print(m_coeffs);
#endif
}

TEST_F(so_parametric_cq_boost, process_0)
{
    // Act
    auto yn = m_filter->process(TEST_SAMPLE_0);
    // Assert
    EXPECT_DOUBLE_EQ(yn, 0);
#ifdef DEBUG_OUTPUT
    std::cout << "yn: " << yn << std::endl;
#endif
}

TEST_F(so_parametric_cq_boost, process_1)
{
    // Act
    auto yn = m_filter->process(TEST_SAMPLE_1);
    // Assert
    EXPECT_NEAR(yn, 1.02784, 0.00001);
#ifdef DEBUG_OUTPUT
    std::cout << "yn: " << yn << std::endl;
#endif
}
