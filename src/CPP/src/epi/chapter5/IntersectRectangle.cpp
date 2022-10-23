#include "IntersectRectangle.hpp"

#include <iostream>
#include <algorithm>

using std::ostream;
using std::max;
using std::min;
using std::cout;
using std::endl;

namespace epi {
namespace chapter5 {

    struct IntersectRectangle::Rectangle {
        bool operator==(const Rectangle &other);

        bool operator!=(const Rectangle &other);

        int x, y, width, height;
    };

    struct IntersectRectangle::Dot {
        int x, y;
    };

    bool IntersectRectangle::Rectangle::operator==(const Rectangle &other) {
        if (x == other.x && y == other.y && width == other.width && height == other.height)
            return true;

        return false;
    }

    bool IntersectRectangle::Rectangle::operator!=(const Rectangle &other) {
        return !( (*this) == other );
    }

    bool IntersectRectangle::isInside(const Dot &dot, const Rectangle &rec) {
        if (dot.x >= rec.x && dot.x <= rec.x + rec.width
                && dot.y >= rec.y && dot.y <= rec.y + rec.height)
            return true;

        return false;
    }

    IntersectRectangle::Rectangle IntersectRectangle::generateRectangleFromTwoDots(
            const Dot &upLeft, const Dot &downRight) {
        return {upLeft.x, upLeft.y, downRight.x - upLeft.x, downRight.y - upLeft.y};
    }

    IntersectRectangle::Rectangle IntersectRectangle::intersectBruteForce(
            const Rectangle &r1, const Rectangle &r2) {
        Dot upLeft = {r1.x, r1.y};
        if ( isInside(upLeft, r2) )
            return generateRectangleFromTwoDots(upLeft, {r2.x + r2.width, r2.y + r2.height});

        Dot upRight = {r1.x + r1.width, r1.y};
        if ( isInside(upRight, r2) )
            return generateRectangleFromTwoDots({r2.x, upRight.y}, {upRight.x, r2.y + r2.height});

        Dot downLeft = {r1.x, r1.y + r1.height};
        if ( isInside(downLeft, r2) )
            return generateRectangleFromTwoDots({downLeft.x, r2.y}, {r2.x + r2.width, downLeft.y});

        Dot downRight = {r1.x + r1.width, r1.y + r1.height};
        if ( isInside(downRight, r2) )
            return generateRectangleFromTwoDots({r2.x, r2.y}, downRight);

        return{ 0, 0, -1, -1 };
    }

    bool IntersectRectangle::isIntersect(const Rectangle &R1, const Rectangle &R2) {
        // Draw a graph, with 5 rectangle to see the relation
        return R1.x <= R2.x + R2.width && R1.x + R1.width >= R2.x &&
            R1.y <= R2.y + R2.height && R1.y + R1.height >= R2.y;
    }

    IntersectRectangle::Rectangle IntersectRectangle::intersectRectangle(
            const Rectangle &R1, const Rectangle &R2) {
        if ( isIntersect(R1, R2) ) {
            return {
                max(R1.x, R2.x),
                max(R1.y, R2.y),
                min(R1.x + R1.width, R2.x + R2.width) - max(R1.x, R2.x),
                min(R1.y + R1.height, R2.y + R2.height) - max(R1.y, R2.y)
            };
        }
        return { 0, 0, -1, -1 };
    }

    ostream& operator<<(ostream &os, const IntersectRectangle::Rectangle &rec) {
        os << "(" << rec.x << "," << rec.y << ") " << "w: " << rec.width << " h: " << rec.height;
        return os;
    }

    bool IntersectRectangle::test() {
        Rectangle r1 = { 1, 2, 3, 2 };
        Rectangle r2 = { 2, 1, 3, 2 };

        cout << intersectRectangle(r1, r2) << endl;
        cout << intersectBruteForce(r1, r2) << endl;

        if ( intersectRectangle(r1, r2) != intersectBruteForce(r1, r2) ) {
            cout << intersectRectangle(r1, r2) << endl;
            cout << intersectBruteForce(r1, r2) << endl;
            return false;
        }

        return true;
    }
} // chapter 5
} // epi
