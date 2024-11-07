module;
import std;

export module examples_arrays;

struct Personne {
    std::string nom;
    int age;
    int notes[3];
};

/* déclaration d'un tableau non initialisé de 5 éléments */
int tab1[5];
/* déclaration et initialisation de tableaux */
int tab2[3] = {9, 4, 3};
/* déclaration d'un tableau dont la taille est calculée à partir
   des données d'initialisation */
const Personne tab3[] = {
    {"Jean Dupont", 12, {0, 12, 6}},
    {"Julie Machin", 14, {20, 18, 16}}
};

export void example_arrays() {
    /* modification du dernier élément du tableau tab1 */
    tab1[4] = 3;
    /* lecture du premier élément du tableau tab2 */
    std::cout << "valeur de tab2[0] = " << tab2[0] << std::endl;
    /* lecture de la totalité du tableau tab3 */
    for (auto i = 0; i < 2; i++) {
        std::cout << "Notes de " << tab3[i].nom << " (" << tab3[i].age << " ans) : " << std::endl;
        for (int j = 0; j < 3; j++) {
            std::cout << " " << tab3[i].notes[j];
        }
        std::cout <<std:: endl;
    }
    /* idem avec des foreach */
    for (const auto & i : tab3) {
        std::cout << "Notes de " << i.nom << " (" << i.age << " ans) : " << std::endl;
        for (int note : i.notes) {
            std::cout << " " << note;
        }
        std::cout <<std:: endl;
    }
}
