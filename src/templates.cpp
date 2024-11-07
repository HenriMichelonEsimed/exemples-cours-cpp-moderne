module;
import std;

module examples_templates;

namespace example {

    void example_templates() {
        const auto p1 = Point{12, 34};
        const auto p2 = Point{56, 78};
        const auto pos1 = Position<Point>{p1, p2};
        const auto pos2 = Position{p1, p2};

        const auto min = minimum(p1, p2);
    }
}
