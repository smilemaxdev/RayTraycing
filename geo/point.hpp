#ifndef POINT_HPP
#define POINT_HPP
#include <limits>

namespace rytg{

    inline double deps = std::numeric_limits<double>::epsilon();

    struct Point{

        double x = 0.0,
               y = 0.0,
               z = 0.0;

        bool operator==(const Point& p) const noexcept;

        double get(size_t idx) const noexcept;

    };
}

#endif