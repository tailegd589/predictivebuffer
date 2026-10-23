#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/mapping/vector.hpp>

class tk_spline {
public:
    static constexpr auto CLASS_NAME = "tk_spline";
    gd::vector<double> m_x;
    gd::vector<double> m_y;
    gd::vector<double> m_b;
    gd::vector<double> m_c;
    gd::vector<double> m_d;
    double m_c0;
    int m_type;
    int m_left;
    int m_right;
    double m_leftValue;
    double m_rightValue;
    bool m_madeMonotonic;
};
