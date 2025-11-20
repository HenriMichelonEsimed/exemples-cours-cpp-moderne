module;
import std;

export module examples_templates;

import examples_inheritance;

export namespace example {

    template<typename T>
    class Position {
    public:
        Position() = default;
        Position(T top, T left): top{top}, left{left} {}

        void Initialise(T top, T left) {
          this->top = top;
          this->left = left;
        }

        inline T GetTop() const { return top; }
        inline T GetLeft() const { return left; }

    private:
        T top{};
        T left{};
    };

    template <typename T>
    T minimum(const T& lhs, const T& rhs) {
        return lhs < rhs ? lhs : rhs;
    }

    template<typename T, std::size_t L>
    class MyArray {
        T arr[L];
    public:
        MyArray() { /* initialiser le contenu de arr */ }
    };

    template<typename T = Point, std::size_t L = 10>
    class MyArray2 {
        T arr[L];
    public:
        MyArray2() { /* initialiser le contenu de arr */ }
    };

    void example_templates();
}
