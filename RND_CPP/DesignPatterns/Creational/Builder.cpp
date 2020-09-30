#include <string>
#include <iostream>

class Car {
public:
	void BuildEngine() {};
	void BuildCabin() {};
	void PaintCar() {};
};

//************************************************************************************************************************************


class Builder {
public:
	virtual ~Builder() {};
	virtual Builder& BuildPart1() = 0;
	virtual Builder& BuildPart2() = 0;
	virtual Builder& BuildPart3() = 0;
};
//************************************************************************************************************************************

class CarBuilder1 : public Builder {

	Car* m_car;

private:
	void Reset() {
		m_car = new Car();
	}
public:
	// Inherited via Builder
	virtual Builder& BuildPart1() override
	{
		m_car->BuildEngine();
		return *this;
	}
	virtual Builder& BuildPart2() override
	{
		m_car->BuildCabin();
		return *this;
	}
	virtual Builder& BuildPart3() override
	{
		m_car->PaintCar();
		return *this;
	}
	CarBuilder1() {
		this->Reset();
	}
	;
	~CarBuilder1() {
		delete m_car;
	}
};

//************************************************************************************************************************************
class Director {
	Builder& m_carBuilder;

public:
	Director() = delete;
	Director(Builder& builder) : m_carBuilder(builder) {

	}

	void BuildCar() {
		m_carBuilder
			.BuildPart1()
			.BuildPart2()
			.BuildPart3();
	};

};
//************************************************************************************************************************************
void ClientCode() {
	
	CarBuilder1 carBuilder;
	Director dir(carBuilder);
	dir.BuildCar();
};