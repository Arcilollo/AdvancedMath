#include <iostream>
#include <math.h>
#include <stdlib.h>

enum Types : int {
  Figures3D = 1,
  Figures2D,
  Special,
  NumTypes = Special,
};

enum Solid : int {
  Parallelepiped = 1,
  Cube,
  Cylinder,
  Cone,
  Pyramid,
  Sphere,
  NumSolid = Sphere,
};

enum Figures : int {
  Rectangle = 1,
  Square,
  EquiteralTriangle,
  IsoscelesTriangle,
  RectangleTriangle,
  Circle,
  RectangleTrapeze,
  IsoscelesTrapeze,
  Pentagon,
  Hexagon,
  Rhombus,
  NumFigures = Rhombus,
};
enum Specials : int {
  PitagoraTwo = 1,
  PitagoraOne,
  NumSpecials = PitagoraOne,
};
enum Time : int {
  TimePlus = 1,
  TimeMinus,
  NumTime = TimeMinus,
};

using PARALLELEPIPED = struct {
  double X, Y, Z, A0, A1, A2, Afull, V;
};

using CUBE = struct {
  double X, Afull, V;
};

using CYLINDER = struct {
  double R, h, C, A1, A0, Afull, V;
};

using CONE = struct {
  double R, h, a, A0, A1, Afull, V;
};

using PYRAMID = struct {
  double X, Y, h, A0, A1, A2, Afull, a1, a2, V;
};

using SPHERE = struct {
  double R, Afull, V;
};

using RECTANGLE = struct {
  double X, Y, Afull, P;
};

using SQUARE = struct
{
  double X, Afull, P;
};

using EQUITERALTRIANGLE = struct {
  double X, Y, Afull, P;
};

using ISOSCELESTRIANGLE = struct {
  double X, x, Y, L, Afull, P;
};

using RECTANGLETRIANGLE = struct {
  double X, Y, I, Afull, P;
};

using CIRCLE = struct {
  double R, C, Afull;
};

using RECTANGLETRAPEZE = struct {
  double X, Y, H, Z, L, Afull, P;
};

using ISOSCELESTRAPEZE = struct {
  double X, Y, H, Z, L, Afull, P;
};

using PENTAGON = struct {
  double X, P, Afull, a;
};

using HEXAGON = struct {
  double X, P, Afull, a;
};

using RHOMBUS = struct {
  double X, Y, L, P, Afull;
};

using TRIANGLE = struct { // Triangle, for Pythagoras
  double X, Y, I;
};

int main() {

  static const double PG = 3.14159;
  static const double NFP = 0.688;
  static const double NFH = sqrt(3)/2;

  int type = 0;
  char restart;


  do {
    do {
      std::cout << "Enter type of calculations you want to do\n";
      std::cout << "1. 3D figures\n";
      std::cout << "2. 2D figures\n";
      std::cout << "3. Specials\n";
      std::cin >> type;
      std::cout << std::endl;
    } while ((type <= 0) || (type > Types::NumTypes));

    switch (type)
    {
      case Types::Figures3D:
      int solid;

      do {
        std::cout << "Enter the number of the solid which you want to calculate area and volume\n";
        std::cout << "1. Parallelepiped\n";
        std::cout << "2. Cube\n";
        std::cout << "3. Cylinder\n";
        std::cout << "4. Cone\n";
        std::cout << "5. Pyramid\n";
        std::cout << "6. Sphere\n";
        std::cin >> solid;
        std::cout << "\n";
      } while ((solid <= 0) || (solid > Solid::NumSolid));

      switch (solid)
      {
        case Solid::Parallelepiped:
        PARALLELEPIPED pa;

        do {
          std::cout << "Enter the side 1 of parallelepiped\n";
          std::cin >> pa.X;
        } while (pa.X <= 0.0);

        do {
          std::cout << "Enter the side 2 of parallelepiped\n";
          std::cin >> pa.Y;
        } while (pa.Y <= 0.0);

        do {
          std::cout << "Enter the side 3 of parallelepiped\n";
          std::cin >> pa.Z;
        } while (pa.Z <= 0.0);

        pa.V = pa.X * pa.Y* pa.Z;
        pa.A0 = pa.X * pa.Y * 2;
        pa.A1 = pa.X *pa.Z * 2;
        pa.A2 = pa.Y * pa.Z * 2;
        pa.Afull = pa.A0 + pa.A1 + pa.A2;

        std::cout << "Area = " << pa.Afull << std::endl;
        std::cout << "Volume = " << pa.V << std::endl;
        break;

        case Solid::Cube:

        CUBE cb;

        do {
          std::cout << "Enter the side of the cube\n";
          std::cin >> cb.X;
        } while (cb.X <= 0.0);

        cb.V = cb.X * cb.X* cb.X;
        cb.Afull = cb.X * cb.X * 6;

        std::cout << "Area = " << cb.Afull << std::endl;
        std::cout << "Volume = " << cb.V << std::endl;
        break;

        case Solid::Cylinder:

        CYLINDER cy;

        do {
          std::cout << "Enter the radius of the cylinder\n";
          std::cin >> cy.R;
        } while (cy.R <= 0.0);

        do {
          std::cout << "Enter the height of the cylinder\n";
          std::cin >> cy.h;
        } while (cy.h <= 0.0);

        cy.A0 = cy.R * cy.R*PG;
        cy.C = cy.R * 2 * PG;
        cy.A1 = cy.C * cy.h;
        cy.Afull = cy.A0 * 2 + cy.A1;
        cy.V = cy.A0 * cy.h;

        std::cout << "Area = " << cy.Afull << std::endl;
        std::cout << "Volume = " << cy.V << std::endl;
        break;

        case Solid::Cone:

        CONE co;

        do {
          std::cout << "Enter the radius of the cone\n";
          std::cin >> co.R;
        } while (co.R <= 0.0);

        do {
          std::cout << "Enter the height of the cone\n";
          std::cin >> co.h;
        } while (co.h <= 0.0);

        co.a = sqrt(co.R*co.R + co.h * co.h);
        co.A0 = co.R * co.R*PG;
        co.A1 = PG * co.R*co.a;
        co.Afull = co.A0 + co.A1;
        co.V = co.A0 * co.h / 3;

        std::cout << "Area = " << co.Afull << std::endl;
        std::cout << "Volume = " << co.V << std::endl;

        break;

        case Solid::Pyramid:

        PYRAMID py;

        do {
          std::cout << "Enter the side 1 of the base\n";
          std::cin >> py.X;
        } while (py.X <= 0.0);

        do
        {
          std::cout << "Enter the side 2 of the base\n";
          std::cin >> py.Y;
        } while (py.Y <= 0.0);

        do {
          std::cout << "Enter the height of the pyramid\n";
          std::cin >> py.h;
        } while (py.h <= 0.0);

        py.A0 = py.X * py.Y;
        py.V = (py.A0 * py.h) / 3;
        py.a1 = sqrt((py.X / 2)*(py.X / 2) + py.h * py.h);
        py.a2 = sqrt((py.Y / 2)*(py.Y / 2) + py.h * py.h);
        py.A1 = (py.X * py.a1);
        py.A2 = (py.Y * py.a2);
        py.Afull = py.A0 + py.A1 + py.A2;

        std::cout << "Area = " << py.Afull << std::endl;
        std::cout << "Volume = " << py.V << std::endl;

        break;

        case Solid::Sphere:

        SPHERE sp;

        do {
          std::cout << "Enter the radius of the sphere\n";
          std::cin >> sp.R;
        } while (sp.R <= 0.0);

        sp.V = 4 * PG / 3 * sp.R* sp.R* sp.R;
        sp.Afull = 4 * PG* sp.R* sp.R;

        std::cout << "Area = " << sp.Afull << std::endl;
        std::cout << "Volume = " << sp.V << std::endl;
        break;
      }
      break;

      case Types::Figures2D:

      int figure;

      do {
        std::cout << "Enter the number of the figure which you want to calculate area and perimeter\n";
        std::cout << "1. Rectangle\n";
        std::cout << "2. Square\n";
        std::cout << "3. Equilateral triangle\n";
        std::cout << "4. Isosceles triangle\n";
        std::cout << "5. Rectangle triangle\n";
        std::cout << "6. Circle\n";
        std::cout << "7. Rectangle trapeze\n";
        std::cout << "8. Isosceles trapeze\n";
        std::cout << "9. Pentagon\n";
        std::cout << "10. Hexagon\n";
        std::cout << "11. Rhombus\n";
        std::cin >> figure;
        std::cout << "\n";
      } while ((figure <= 0) || (figure > Figures::NumFigures));

      switch (figure)
      {
        case Figures::Rectangle:

        RECTANGLE re;

        do {
          std::cout << "Insert the side 1 of the rectangle\n";
          std::cin >> re.X;
        } while (re.X <= 0.0);

        do {
          std::cout << "Insert the side 2 of the rectangle\n";
          std::cin >> re.Y;
        } while (re.Y <= 0.0);

        re.Afull = re.X *re.Y;
        re.P = re.X + re.X + re.Y + re.Y;

        std::cout << "Area = " << re.Afull << std::endl;
        std::cout << "Perimeter = " << re.P << std::endl;
        break;

        case Figures::Square:

        SQUARE sq;

        do {
          std::cout << "Insert the side of the square\n";
          std::cin >> sq.X;
        } while (sq.X <= 0.0);

        sq.Afull = sq.X * sq.X;
        sq.P = sq.X * 4;

        std::cout << "Area = " << sq.Afull << std::endl;
        std::cout << "Perimeter = " << sq.P << std::endl;
        break;

        case Figures::EquiteralTriangle:

        EQUITERALTRIANGLE et;

        do {
          std::cout << "Insert the base of equilateral triangle\n";
          std::cin >> et.X;
        } while (et.X <= 0.0);

        do {
          std::cout << "Insert the height of the equilateral triangle\n";
          std::cin >> et.Y;
        } while (et.Y <= 0.0);

        et.Afull = et.X *et.Y / 2;
        et.P = et.X * 3;

        std::cout << "Area = " << et.Afull << std::endl;
        std::cout << "Perimeter = " << et.P << std::endl;
        break;

        case Figures::IsoscelesTriangle:

        ISOSCELESTRIANGLE it;

        do {
          std::cout << "Insert the base of isosceles triangle\n";
          std::cin >> it.X;
        } while (it.X <= 0.0);

        do {
          std::cout << "Insert the height of the isosceles triangle\n";
          std::cin >> it.Y;
        } while (it.Y <= 0.0);

        it.Afull = it.X * it.Y / 2;
        it.x = it.X / 2;
        it.L = sqrt(it.x*it.x + it.Y * it.Y);
        it.P = it.X + it.L + it.L;

        std::cout << "Area = " << it.Afull << std::endl;
        std::cout << "Perimeter = " << it.P << std::endl;
        break;

        case Figures::RectangleTriangle:

        RECTANGLETRIANGLE rt;

        do {
          std::cout << "Insert the side 1 of the rectangle triangle\n";
          std::cin >> rt.X;
        } while (rt.X <= 0.0);

        do {
          std::cout << "Insert the side 2 of the rectangle triangle\n";
          std::cin >> rt.Y;
        } while (rt.Y <= 0.0);

        rt.Afull = rt.X * rt.Y / 2;
        rt.I = sqrt(rt.X*rt.X + rt.Y * rt.Y);
        rt.P = rt.X + rt.Y + rt.I;

        std::cout << "Area = " << rt.Afull << std::endl;
        std::cout << "Perimeter = " << rt.P << std::endl;
        break;

        case Figures::Circle:

        CIRCLE ci;

        do {
          std::cout << "Enter the radius of the circle\n";
          std::cin >> ci.R;
        } while (ci.R <= 0.0);

        ci.C = ci.R * 2 * PG;
        ci.Afull = ci.R * ci.R*PG;

        std::cout << "Area = " << ci.Afull << std::endl;
        std::cout << "Circumference = " << ci.C << std::endl;
        break;

        case Figures::RectangleTrapeze:

        RECTANGLETRAPEZE ret;

        do {
          std::cout << "Enter the major base\n";
          std::cin >> ret.X;
        } while (ret.X <= 0.0);

        do {
          std::cout << "Enter the minor base\n";
          std::cin >> ret.Y;
        } while (ret.Y <= 0.0);

        do {
          std::cout << "Enter the height\n";
          std::cin >> ret.H;
        } while (ret.H <= 0.0);

        ret.Afull = ret.X * ret.Y*ret.H / 2;
        ret.Z = ret.X - ret.Y;
        ret.L = sqrt(ret.H*ret.H + ret.Z * ret.Z);
        ret.P = ret.X + ret.Y + ret.L + ret.H;

        std::cout << "Area = " << ret.Afull << std::endl;
        std::cout << "Perimeter = " << ret.P << std::endl;
        break;

        case Figures::IsoscelesTrapeze:

        ISOSCELESTRAPEZE ist;

        do {
          std::cout << "Enter the major base\n";
          std::cin >> ist.X;
        } while (ist.X <= 0.0);

        do {
          std::cout << "Enter the minor base\n";
          std::cin >> ist.Y;
        } while (ist.Y <= 0.0);

        do {
          std::cout << "Enter the height\n";
          std::cin >> ist.H;
        } while (ist.H <= 0.0);

        ist.Afull = ist.X * ist.Y*ist.H / 2;
        ist.Z = (ist.X - ist.Y) / 2;
        ist.L = sqrt(ist.H*ist.H + ist.Z * ist.Z);
        ist.P = ist.X + ist.Y + ist.L + ist.H;

        std::cout << "Area = " << ist.Afull << std::endl;
        std::cout << "Perimeter = " << ist.P << std::endl;
        break;

        case Figures::Pentagon:

        PENTAGON pe;

        do {
          std::cout << "Enter the side of pentagon\n";
          std::cin >> pe.X;
        } while (pe.X <= 0.0);

        pe.P = pe.X * 5;
        pe.a = pe.X * NFP;
        pe.Afull = pe.P * pe.a / 2;

        std::cout << "Area = " << pe.Afull << std::endl;
        std::cout << "Perimeter = " << pe.P << std::endl;
        break;

        case Figures::Hexagon:

        HEXAGON he;

        do {
          std::cout << "Enter the side of hexagon\n";
          std::cin >> he.X;
        } while (he.X <= 0.0);

        he.P = he.X * 6;
        he.a = he.X * NFH;
        he.Afull = he.P * he.a / 2;

        std::cout << "Area = " << he.Afull << std::endl;
        std::cout << "Perimeter = " << he.P << std::endl;
        break;

        case Figures::Rhombus:

        RHOMBUS ro;

        do {
          std::cout << "Insert the diagonal 1 of the rectangle\n";
          std::cin >> ro.X;
        } while (ro.X <= 0.0);

        do {
          std::cout << "Insert the diagonal 2 of the rectangle\n";
          std::cin >> ro.Y;
        } while (ro.Y <= 0.0);

        ro.Afull = ro.X * ro.Y / 2;
        ro.L = sqrt( (ro.X / 2) * (ro.X / 2) + (ro.Y / 2) * (ro.Y / 2) );
        ro.P = ro.L * 4;

        std::cout << "Area = " << ro.Afull << std::endl;
        std::cout << "Perimeter = " << ro.P << std::endl;
        break;
      }
      break;

      case Types::Special:

      int special;

      do {
        std::cout << "1. Pythagorean theorem (with 2 side)\n";
        std::cout << "2. Pythagorean theorem (with hypotenuse and 1 side)\n";
        std::cin >> special;
        std::cout << "\n";
      } while ((special <= 0) || (special > Specials::NumSpecials));

      switch (special) {
        case Specials::PitagoraTwo:

        TRIANGLE t2;

        do {
          std::cout << "Enter the side 1\n";
          std::cin >> t2.X;
        } while (t2.X <= 0.0);

        do {
          std::cout << "Enter the side 2\n";
          std::cin >> t2.Y;
        } while (t2.Y <= 0.0);

        t2.I = sqrt(t2.X*t2.X + t2.Y * t2.Y);

        std::cout << "Hypotenuse = " << t2.I << std::endl;
        break;

        case Specials::PitagoraOne:
        TRIANGLE t1;

        do {
          std::cout << "Enter the side 1\n";
          std::cin >> t1.X;
        } while (t1.X <= 0.0);

        do {
          std::cout << "Enter the Hypotenuse\n";
          std::cin >> t1.I;
        } while (t1.I <= t1.X);

        t1.Y = sqrt(t1.I*t1.I - t1.X * t1.X);

        std::cout << "Side 2 = " << t1.Y << std::endl;
      }
      break;
    }

    std::cout << "\n" << "Restart the program? (Y/n)\n";
    std::cin >> restart;
    system("cls");        // Windows
    //system("clear");    // GNU/linux
  } while ((restart == 'Y') || (restart == 'y'));

  return 0;
}
