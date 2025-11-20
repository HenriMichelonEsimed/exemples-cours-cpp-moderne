module;
import std;

export module examples_enum_structs;

export enum Sexe {
    // valeur : 0
    T_SEXE_HOMME,
    // valeur : 1
    T_SEXE_FEMME,
    // valeur : 123
    T_SEXE_AUTRE = 123,
};

export struct Personne {
    struct {
        std::string nom_de_famille{};
        std::string prenom{};
    } nom;

    int age{};
    Sexe sexe{T_SEXE_AUTRE};
};

export void example_enum() {
    auto sexe_personne = T_SEXE_HOMME;
    if (sexe_personne == T_SEXE_AUTRE) {
        std::cout << "Sexe de la personne inconnu!" << std::endl;
    }
}

export void example_structs() {
    auto lui = Personne{}; // structure initialisée aux valeurs par défaut
    lui.nom.nom_de_famille = "Duschmoll";
    lui.nom.prenom = "Jean";
    lui.age = 98;
    lui.sexe = T_SEXE_HOMME;
    std::cout
        << "Lui: " << lui.nom.nom_de_famille
        << " " << lui.nom.prenom
        << ", " << lui.age
        << ", " << (lui.sexe == T_SEXE_HOMME ? "homme" : "femme")
        << std::endl;

    // déclaration et initialisation d'une structure
    // const auto elle = Personne{
    //     .nom = {"Machin", "Germaine"},
    //     .age = 112,
    //     .sexe = T_SEXE_FEMME
    // };
    const auto elle = Personne{
        {"Machin", "Germaine"},
        112,
        T_SEXE_FEMME
    };

    std::cout
        << "Elle: " << elle.nom.nom_de_famille
        << " " << elle.nom.prenom
        << ", " << elle.age
        << ", " << (elle.sexe == T_SEXE_HOMME ? "homme" : "femme")
        << std::endl;
}
