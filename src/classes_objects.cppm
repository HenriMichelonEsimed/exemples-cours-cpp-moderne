module;
import std;

export module examples_classes_objects;

export namespace example {
    class ExceptionPositionLimites : public std ::exception { };

    class Position {
    public:
        Position();
        Position(int top, int left);
        ~Position();

        void Initialise(int top, int left);

        void Affiche() const;

        static int GetCount();

        inline int GetTop() const { return top; }
        inline int GetLeft() const { return left; }

    private:
        int top{};
        int left{};

        static int init_count;
    };

    void example_classes_objects();
}
