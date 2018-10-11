#include <iostream>
#include <cmath>
using namespace std;

#define PG 3.14

int main(){
	int Solido;

        cout << "Enter the number of the solid which you want to calculate area and volume" << endl;
        cout << "1. Parallelepiped" << endl;
        cout << "2. Cube" << endl;
        cout << "3. Cylinder" << endl;
        cout << "4. Cone" << endl;
        cout << "5. Pyramid" <<endl;
        cout << "6. Sphere" <<endl;
        cin >> Solido;

	if(Solido == 1){         // Parallelepiped

        float X,Y,Z,A0,A1,A2,Afull,V;

        cout << "Enter the side 1 of parallelepiped" << endl;
        cin >> X;
        cout << "Enter the side 2 of parallelepiped" << endl;
        cin >> Y;
        cout << "Enter the side 3 of parallelepiped" << endl;
        cin >> Z;

        V = X*Y*Z;
        A0 = X*Y*2;
        A1 = X*Z*2;
        A2 = Y*Z*2;
        Afull = A0+A1+A2;

        cout << "Area = " << Afull << endl;
        cout << "Volume = " << V << endl;
	}

	else if(Solido == 2){            // Cube

        float X,Afull,V;

        cout << "Enter the side of the cube" << endl;
        cin >> X;

        V = X*X*X;
        Afull = X*X*6;

        cout << "Area = " << Afull << endl;
        cout << "Volume = " << V << endl;
	}

	else if(Solido == 3){             // Cylinder

        float R,h,C,A1,A0,Afull,V;

        cout << "Enter the radius of the cylinder" << endl;
        cin >> R;
        cout << "Enter the height of the cylinder" << endl;
        cin >> h;

        A0 = R*R*PG;
        C = R*2*PG;
        A1 = C*h;
        Afull = A0*2+A1;
        V = A0*h;

        cout << "Area = " << Afull << endl;
        cout << "Volume = " << V << endl;
	}

    else if(Solido == 4){              // Cone

        float R,h,a,A0,A1,Afull,V;

        cout << "Enter the radius of the cone" << endl;
        cin >> R;
        cout << "Enter the height of the cone" << endl;
        cin >> h;

        a = sqrt(R*R+h*h);
        A0 = R*R*PG;
        A1 = PG*R*a;
        Afull = A0+A1;
        V =A0*h/3;

        cout << "Area = " << Afull << endl;
        cout << "Volume = " << V << endl;
    }

    else if(Solido == 5){                 // Pyramid

        float X,Y,h,A0,A1,A2,Afull,a1,a2,V;

        cout << "Enter the side 1 of the base" << endl;
        cin >> X;
        cout << "Enter the side 2 of the base" << endl;
        cin >> Y;
        cout << "Enter the height of the pyramid" << endl;
        cin >> h;

        A0 = X*Y;
        V  = A0*h;
        a1 = sqrt((X/2)*(X/2)+h*h);
        a2 = sqrt((Y/2)*(Y/2)+h*h);
        A1 = X*a1;
        A2 = Y*a2;
        Afull = A0+A1+A2;

        cout << "Area = " << Afull << endl;
        cout << "Volume = " << V << endl;
    }

    else if(Solido == 6){                   //Sphere

        float R,Afull,V;

        cout << "Enter the radius of the sphere" << endl;
        cin >> R;

        V = 4*PG/3*R*R*R;
        Afull = 4*PG*R*R;

        cout << "Area = " << Afull << endl;
        cout << "Volume = " << V << endl;
    }
}
