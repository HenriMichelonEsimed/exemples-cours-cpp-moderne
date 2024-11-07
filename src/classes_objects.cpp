module;
import std;

module examples_classes_objects;

namespace example {

    int Position::init_count{0};

    void Position::Initialise(const int top, const int left)  {
        if ((top > 768) || (left > 1024) || (top < 0) || (left < 0)) {
            throw ExceptionPositionLimites();
        }
        this->top = top;
        this->left = left;
        init_count++;
    }

    void Position::Affiche() const {
        std::cout << std::format("[{},{}]", top, left) << std::endl;
    }

    int Position::GetCount() {
        return init_count;
    }

    Position::Position(const int top, const int left): top{top}, left {left} {
        init_count++;
    }

    // Appel de l'autre constructeur
    Position::Position(): Position{-1, -1} {}

    Position::~Position() {
        init_count--;
    }

    void example_classes_objects() {
        const auto position = Position{1, 2};
        // position.Initialise(10, 10);
        position.Affiche();
        std::cout << "init_count: " << Position::GetCount() << std::endl;

        /* instanciation automatique, objet alloué sur la pile
         * p1 contient l'objet */
        auto p1 = Position{};
        // p1.Initialise(10, 20);
        std::cout << "init_count: " << Position::GetCount() << std::endl;

        /* instanciation dynamique, objet alloué sur le tas
         * p2 contient un smart pointer vers l'objet */
        const auto p2 = std::make_unique<Position>();
        p2->Initialise(10, 20);

        auto p3 = Position{};
        p3.Initialise(12, 34);
        const auto p4 = p3;
        p4.Affiche();
        p3.Initialise(56, 78);
        p4.Affiche();

    }
}
