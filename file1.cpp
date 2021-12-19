
#include <iostream>
using namespace std;
template <class T>
class Rectangle {
private:
	T Height;
	T Width;
public:
	// Constructor default
	Rectangle() {
		Height = 297; // mm
		Width = 210; // mm
	}
	//Constructor overloaded
	Rectangle(T heightMM, T widthMM) {
		Height = heightMM;
		Width = widthMM;
	}
	// get Perimeter, ((set height and width) option)
	T Perimeter(T hMM = 0, T wMM = 0) { 
		if (hMM != 0 )
			Height = hMM;
		if(wMM != 0)
			Width = wMM;
		return (Height + Width) * 2;
	}
	void SetRectangle(float hMM = 0, float wMM = 0) {
		if (hMM != 0 && wMM != 0) {
			Height = hMM; Width = wMM;
		}
	}
	void SetHeight(float height) {
		Height = height;
	}

	T GetHeightCentimeter() {
		return Height / 10;
	}
	T GetWidthCentimeter() {
		return Width / 10;
	}
};

int main()
{
	Rectangle<float> rec1; // call default constructor
	cout << "default Perimeter = " << rec1.Perimeter() <<" MM" << endl; // 1014
	cout << "perimeter of rectangle rec1= " << rec1.Perimeter(8, 4) << " MM" << endl; // 24

	Rectangle<float> rec2(rec1); // this is copy costructor
	rec2.SetHeight(9);// Width of rec2 == Width of rec1
	cout << "perimeter of rectangle rec2= " << rec2.Perimeter() << " MM" << endl; // (9+4)*2 = 26
	cout << "perimeter of rectangle rec2= " << rec2.Perimeter(0,9) << " MM" << endl; // (9+9) *2 = 36

	Rectangle<float> rec3(8, 4); // call overloaded constructor
	cout << "perimeter of rectangle rec3= " << rec3.Perimeter() << " MM" << endl; // (8 + 4) * 2 = 24
	cout << "rec2: Height= " << rec3.GetHeightCentimeter() << " cm" << " Width= " << rec3.GetWidthCentimeter() << " cm .";
}
