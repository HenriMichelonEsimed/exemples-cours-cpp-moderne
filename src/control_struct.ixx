module;
import std;

export module examples_control_struct;

export void example_if() {
    // Initialisation du générateur de nombres aléatoires
    std::srand(std::time(nullptr));
    // Génération d'un nombre aléatoire sur 32 bits
    auto i = std::rand();

    if ((i < 5000) || (i > 1000000000)) {
        std::cout << "i est inférieur à 5 000 ou supérieur à 1 000 000 000 \n";
    }

    if (i % 2) {
        std::cout << "i est impair\n";
    } else {
        std::cout << "i est pair\n";
    }

    std::cout << "i=" << i << std::endl;
}

export void example_while() {
    // Initialisation du générateur de nombres aléatoires
    std::srand(std::time(nullptr));
    // Génération d'un nombre aléatoire
    auto i = std::rand();

    while (i > 400000000) {
        auto j = i;
        i = std::rand();
        if (j > 2000000000) {
            std::cout << "i > 2000000000 , arrêt du while()\n";
            break;
        }
        if (j < 600000000) {
            std::cout << "i < 600000000, on reprend au while()\n";
            continue;
        }
        std::cout << "i=" << j << std::endl;
    }
}

export void example_do() {
    // Initialisation du générateur de nombres aléatoires
    std::srand(std::time(nullptr));
    int i;
    do {
        // Génération d'un nombre aléatoire
        i = std::rand();
        if (i > 2000000000) {
            std::cout << "i > 2000000000 , arrêt du do()\n";
            break;
        }
        if (i < 600000000) {
            std::cout << "i < 600000000, on reprend au do()\n";
            continue;
        }
        std::cout << "i=" << i << std::endl;
    } while (i > 400000000);
}


export void example_for() {
    // Initialisation du générateur de nombres aléatoires
    std::srand(std::time(nullptr));
    for (auto i = 0; i < 10; i++) {
        // Génération d'un nombre aléatoire
        auto j = std::rand();
        if (j > 2000000000) {
            std::cout << "j > 2000000000 , arrêt du for()\n";
            break;
        }
        if (j < 600000000) {
            std::cout << "j < 600000000, on reprend au for()\n";
            continue;
        }
        std::cout << "i=" << i << ", j=" << j << std::endl;
    }
}


export void example_foreach() {
    std::srand(std::time(nullptr));
    auto list_rand = std::list<int>{};
    for (auto i = 0; i < 10; i++) {
        list_rand.push_back(std::rand());
    }
    for(auto i : list_rand) {
        std::cout << "i=" << i << std::endl;
    }
}