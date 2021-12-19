
#include <iostream>
using namespace std;
class Rectangle {
private:
	float Height;
	float Width;
public:
	// Constructor default
	Rectangle() {
		Height = 297; // mm
		Width = 210; // mm
	}
	//Constructor overloaded
	Rectangle(float height, float width) {
		Height = height;
		Width = width;
	}
	// get Perimeter, ((set height and width) option)
	float Perimeter(float h = 0, float w = 0) {
		if (h != 0 || w != 0) {
			Height = h;
			Width = w;
		}
		return (Height + Width) * 2;
	}
	void SetHeight(float height) {
		Height = height;
	}
	void SetRectangle(float h = 0, float w = 0) {
		if (h != 0 || w != 0) {
			Height = h; Width = w;
		}
	}
	float GetHeight() {
		return Height;
	}
};

int main()
{
	Rectangle rec1; // call default constructor
	cout << "default Perimeter = " << rec1.Perimeter() << endl;
	cout << "perimeter of rectangle rec1= " << rec1.Perimeter(8, 4) << endl;

	Rectangle rec2(rec1); // this is copy costructor
	rec2.SetHeight(9);// Width of rec2 == Width of rec1
	cout << "perimeter of rectangle rec2= " << rec2.Perimeter() << endl;

	Rectangle rec3(8,4); // call overloaded constructor
	cout << "perimeter of rectangle rec3= " << rec3.Perimeter() << endl;
}
