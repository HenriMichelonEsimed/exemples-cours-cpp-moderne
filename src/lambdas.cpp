module;
import std;

module examples_lambdas;

namespace example {

    // Définition d'un type expression lambda avec 2 int en paramètre et qui retourne un std::string
    typedef std::function<std::string(int, int)> Operation;

    // Utilisation du type précédent
    void affiche_operation(const int a, const int b, const Operation& operation) {
        std::cout << operation(a, b) << '\n';
    }

    void example_lambdas() {
        // Lambda simple sans capture
        auto add = [](const int a, const int b) {
            return a + b;
        };
        std::cout << add(3, 5) << std::endl;

        // Lambda simple par valeur (copie)
        int x = 10;
        auto multiply1 = [x](const int y) {
            return x * y;
        };
        x = 20;
        // Affiche 50 car x a été capturé alors qu'il avait la valeur 10
        std::cout << multiply1(5) << std::endl;

        // Lambda simple par valeur (copie)
        auto multiply2 = [&x](const int y) {
            return x * y;
        };
        // Affiche 100
        std::cout << multiply2(5) << std::endl;
        x = 30;
        // Affiche 150 car x a été capturé par référence
        std::cout << multiply2(5) << std::endl;

        // Généricité avec l'inférence de type
        auto sayHello = [](auto value) {
            std::cout << "Bonjour " << value << std::endl;
        };
        sayHello(42);
        sayHello("Hello");

        // Utilisation du type expression lambda défini ci-dessus
        affiche_operation(2, 3, [](int a, int b) {
            return std::format("{} + {} = {}", a, b, a + b);
        });
        affiche_operation(4, 5, [](int a, int b) {
            return std::format("{} * {} = {}", a, b, a * b);
        });

    }
}
