
class Box {
private:
	double width_;

public:
	double length;
	// This is a friend method of Box. Its not a member function of class Box
	friend void printWidth(Box& box);
	//
	friend void doSomething();
	void setWidth(double width);
};


void
Box::setWidth(double width) {
	width_ = width;
}

void
printWidth(Box& box) {
	box.setWidth(20);
}
