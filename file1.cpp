
#include <iostream>
using namespace std;
template <class T>
class Rectangle{
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
	Rectangle(T height, T width) {
		Height = height;
		Width = width;
	}
	// get Perimeter, ((set height and width) option)
	T Perimeter(T h = 0, T w = 0) {
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
	Rectangle<float> rec1; // call default constructor
	cout << "default Perimeter = " << rec1.Perimeter() << endl;
	cout << "perimeter of rectangle rec1= " << rec1.Perimeter(8, 4) << endl;

	Rectangle<float> rec2(rec1); // this is copy costructor
	rec2.SetHeight(9);// Width of rec2 == Width of rec1
	cout << "perimeter of rectangle rec2= " << rec2.Perimeter() << endl;

	Rectangle<float> rec3(8,4); // call overloaded constructor
	cout << "perimeter of rectangle rec3= " << rec3.Perimeter() << endl;
}
