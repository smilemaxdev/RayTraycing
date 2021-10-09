#ifndef LINE_HPP
#define LINE_HPP

#include "../polygon/triangle.hpp"
#include "vector3d.hpp"
#include "section.hpp"
#include "plane.hpp"

namespace rytg{

    class Line{
        Point P0_;
        Vector3D L_;

        public:

        Line(const Plane& lhs, const Plane& rhs) noexcept;

        Vector3D getDirection() const noexcept;

        Point getConstant() const noexcept;

        double intersection(const Section& sec, double s) const noexcept;

        std::array<double, 2> intersection(const Triangle& t, const Plane& oth) const noexcept;

    };

}
#endif