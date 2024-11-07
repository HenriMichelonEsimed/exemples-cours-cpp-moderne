module;
import std;

module examples_inheritance;

namespace example {

    Point::Point(int x, int y): x{x}, y{y} {
    }

    void Point::Affiche() const {
        std::cout << std::format("Point({},{})", x, y) << std::endl;
    }

    void Point::Affiche2() const {
        std::cout << std::format("Point({},{})", x, y) << std::endl;
    }

    Point3D::Point3D(int x, int y, int z): Point{x, y}, z{z} {
    }

    void Point3D::Affiche() const {
        std::cout << std::format("Point3D({},{},{})", x, y, z) << std::endl;
    }

    void Point3D::Affiche2() const {
        Point::Affiche();
        std::cout << std::format("Point3D({},{},{})", x, y, z) << std::endl;
    }

    Point Point::operator + (const Point& point) const {
        //équivalant à return Point{x + point.x, y + point.y};
        return {x + point.x, y + point.y};
    }

    Point operator - (const Point&p1, const Point&p2) {
        return {p1.x - p2.x, p1.y + p2.y};
    }

    bool Point::operator < (const Point& point) const {
        return (x + y) < (point.x + point.y);
    }

    Point::operator int () {
        return x + y;
    }

    Point::operator Position() {
        return {x, y}; // Position{x, y}
    }

    void example_inheritance() {
        auto p1 = Point{1, 2};
        // Appel de Point::Affiche()
        p1.Affiche();
        auto p2 = Point3D{3, 4, 5};
        // Appel de Point3D::Affiche()
        p2.Affiche();
        // Appel de Point::Affiche() via un objet Point3D
        p2.Point::Affiche();
        // On stocke la référence d'une Point3D dans une variable Point
        Point& p3 = p2;
        // Il n'y a pas de polymorphisme, Point::Affiche() est appelée
        p3.Affiche();

        auto p4 = Point3D{7, 8, 9};
        // Appel de Point3D::Affiche()
        p4.Affiche2();
        Point& p5 = p4;
        // Appel de Point3D::Affiche()
        p5.Affiche2();

        auto p6 = Point{1, 2};
        auto p7 = p6 + Point{3, 4};
        p7.Affiche();
        auto p8 = p6 - Point{3, 4};
        p8.Affiche();

        //////////// opérateur de conversion "classique"
        std::cout << "Casts avec () :\n";
        int i1 = p8;
        std::cout << i1 << std::endl;
        auto i2 = (int)p8;
        std::cout << i2 << std::endl;
        // opérateur casting "classique" vers Position
        Position p9 = p8;
        p9.Affiche();
        auto p10 = (Position)p8;
        p10.Affiche();

        //////////// opérateurs de conversion moderne
        std::cout << "Casts avec dynamic_cast() :\n";
        // Opérateur moderne de conversion de type objets, avec contrôle à l'exécution
        auto p8b = Point{3, 4};
        try {
            auto& p11 = dynamic_cast<Position&>(p8b);
        } catch (const std::bad_cast& e) {
            std::cout << "Conversion impossible de Point vers Position (famille differente)" << std::endl;
        }
        // A remplacer par une instanciation d'objets avec initialisation :
        const auto p12 = Position{p8b};
        p12.Affiche();
        // Conversion entre types de même famille
        try {
            auto& p13 = dynamic_cast<Point3D&>(p8b);
            p13.Affiche();
        } catch (const std::bad_cast& e) {
            std::cout << "Conversion impossible de Point vers Point3D (mauvaise direction d'héritage)" << std::endl;
        }
        // Uniquement possible si le type réel est compatible
        Point& p14 = p2; // on stocke un Point3D dans une variable de type Point
        // ... beaucoup plus loin ou dans une autre classe ...
        const auto& p15 = dynamic_cast<Point3D&>(p14); // on fait l'inverse, avec un contrôle à l'exécution
        p15.Affiche();
        // Utilisation de l'opérateur pour tester un type
        if (auto& point3D = dynamic_cast<Point3D&>(p14)) {
            // p14 référence un objet de type Point3D
        } else {
            // p14 référence un objet de type Point
        }
        std::cout << "Casts avec static_cast() :\n";
        const auto floatNumber{12.5f};
        const auto intNumber = static_cast<int>(floatNumber);
        std::cout << floatNumber << " -> " << intNumber << std::endl;
    }
}
