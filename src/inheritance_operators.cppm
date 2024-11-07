module;
import std;

export module examples_inheritance;

import examples_classes_objects;

export namespace example {

    class Point {
    public:
        Point(int x, int y);

        Point operator + (const Point& point) const;
        friend Point operator - (const Point&, const Point&);
        bool operator < (const Point& point) const;

        /* conversion de Point en int */
        operator int ();

        /* Convertion de Point vers Position */
        operator Position();

        inline int GetX() const { return x; }
        inline int GetY() const { return y; }

        void Affiche() const;
        virtual void Affiche2() const;

    protected:
        int x;
        int y;
    };

    class Point3D : public Point {
    public:
        Point3D(int x, int y, int z);

        inline int GetZ() const { return z; }

        void Affiche() const;
        void Affiche2() const override;

    private:
        int z;
    };

    void example_inheritance();
}
