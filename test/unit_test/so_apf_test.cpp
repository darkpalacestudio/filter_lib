#include "tests_common.hpp"

// Text fixture for Class-Under-Test (CUT)
struct so_apf : public testing::Test {
    SO_APF* m_filter;
    Biquad::CoefficientsType m_coeffs;

    void SetUp()
    {
        m_filter = new SO_APF();
        m_coeffs = m_filter->calculate_coeffs(Q_DEF, FC, SAMPLING_RATE);
    }

    void TearDown() { delete m_filter; }
};

TEST_F(so_apf, coeff_calculation)
{
    // Assert
    EXPECT_NEAR(m_coeffs.a0, 0.999934, 0.00001);
#ifdef DEBUG_OUTPUT
    debug_print(m_coeffs);
#endif
}

TEST_F(so_apf, process_0)
{
    // Act
    auto yn = m_filter->process(TEST_SAMPLE_0);
    // Assert
    EXPECT_DOUBLE_EQ(yn, 0);
#ifdef DEBUG_OUTPUT
    std::cout << "yn: " << yn << std::endl;
#endif
}

TEST_F(so_apf, process_1)
{
    // Act
    auto yn = m_filter->process(TEST_SAMPLE_1);
    // Assert
    EXPECT_NEAR(yn, 0.999934, 0.00001);
#ifdef DEBUG_OUTPUT
    std::cout << "yn: " << yn << std::endl;
#endif
}
