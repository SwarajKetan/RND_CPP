
namespace MythOfConst {

	void Client() {

		int x = 5;
		const int* ConstIntPtr = &x; // changing the value pointed by the pointer is not allowed
		int* const IntPtrConst = &x; // changing the pointer is not allowed
		const int* const ConstIntPtrConst = &x; // changing the value and changing the pointer - both not allowed

		int y = 10;
		ConstIntPtr = &y; // allowed
		//(*ConstIntPtr) = y;// not allowed

		//IntPtrConst = &y; // not allowed
		(*IntPtrConst) = y;// allowed

		//ConstIntPtrConst = &y; // not allowed
		//(*ConstIntPtrConst) = y;// not allowed

	}
}