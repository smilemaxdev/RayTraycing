#include "vector3d.hpp"
#include <stdexcept>

namespace rytg{

        Vector3D::Vector3D(Point end, Point start) noexcept{
            direction_.x = end.x - start.x;
            direction_.y = end.y - start.y;
            direction_.z = end.z - start.z;
        }

        Vector3D::Vector3D(double x, double y, double z) noexcept{
            direction_.x = x;
            direction_.y = y;
            direction_.z = z;
        }

        bool Vector3D::isNull() const noexcept{
            return direction_.x == 0 && direction_.y == 0 && direction_.z == 0;
        }

        double Vector3D::get(std::size_t index) const{
            switch(index) {
                case 0: return direction_.x;
                case 1: return direction_.y;
                case 2: return direction_.z;
                default: throw std::out_of_range("Wrong vector index");
            }
        }

        double Vector3D::dot(const Vector3D& v) const noexcept{
            return v.get(0) * get(0) + v.get(1) * get(1) + v.get(2) * get(2);
        }

        Vector3D Vector3D::cross(const Vector3D& v) const noexcept{
            return Vector3D(get(1) * v.get(2) - get(2) * v.get(1), get(2) * v.get(0) - get(0) * v.get(2), get(0) * v.get(1) - get(1) * v.get(0));
        }

        Vector3D Vector3D::operator+(const Vector3D& v) const noexcept{
            return Vector3D(get(0) + v.get(0), get(1) + v.get(1), get(2) + v.get(2));
        }

        Vector3D Vector3D::operator-(const Vector3D& v) const noexcept{
            return Vector3D(get(0) - v.get(0), get(1) - v.get(1), get(2) - v.get(2));
        }

        Vector3D& Vector3D::operator+=(const Vector3D& v) noexcept{
            direction_.x += v.get(0);
            direction_.y += v.get(1);
            direction_.z += v.get(2);
            return *this;
        }

        Vector3D& Vector3D::operator-=(const Vector3D& v) noexcept{
            direction_.x -= v.get(0);
            direction_.y -= v.get(1);
            direction_.z -= v.get(2);
            return *this;
        }

        bool Vector3D::operator==(const Vector3D& v) const noexcept{
            return direction_ == v.direction_;
        }

}