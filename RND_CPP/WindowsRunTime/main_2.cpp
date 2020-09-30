#include <Windows.h>
#include <wrl.h>
#include <type_traits>

#define Trace(x) __noop

using Microsoft::WRL::ComPtr;

//__declspce(novtable) not working hav to see
template<typename ... Interfaces>
class  Implements : public Interfaces...{
	volatile long m_reference = 1;

	template<int = 0>
	void* QueryInterface(const GUID& id) noexcept {
		return nullptr;
	};

	template<typename First, typename... Rest>
	void* QueryInterface(const GUID& id) noexcept {
		if (id == __uuidof(First))
			return static_cast<First*>(this);

		return QueryInterface<Rest...>(id);
	};

	template<typename First, typename... Rest>
	void* BaseQueryInterface(const GUID& id) noexcept {
		if (id == __uuidof(First) || id == __uuidof(IUnknown)
			|| (std::is_base_of<IInspectable, First>::value && id == __uuidof(IInspectable))) {
			return static_cast<First*>(this);
		}
		return QueryInterface<Rest...>(id);
	}

protected:
	virtual ~Implements() noexcept {

	}

public:
	unsigned long __stdcall AddRef() noexcept {
		return InterlockedIncrement(&m_reference);
	}

	unsigned long __stdcall Release() noexcept {
		auto const count = InterlockedDecrement(&m_reference);
		if (count == 0)
			delete this;
		return count;
	}

	HRESULT __stdcall QueryInterface(const GUID& id, void** object)  noexcept {
		return S_OK;
	}
};
// 85312265-9a64-48a9-b688-5b3c557582b8
 
struct __declspec(uuid("85312265-9a64-48a9-b688-5b3c557582b8")) __declspec(novtable) IHen : IUnknown {
	virtual HRESULT __stdcall Cluck() = 0;
};

class Hen : public Implements<IHen> {
	volatile long m_references = 1;
public:
	Hen() {
		Trace(L"Cheep\n");
	}
	~Hen() {
		Trace(L"destryed\n");
	}

	/*unsigned long __stdcall AddRef() noexcept {
		return InterlockedIncrement(&m_references);
	}

	unsigned long __stdcall Release() noexcept {
		unsigned long const count = InterlockedDecrement(&m_references);
		if (count == 0) {
			delete this;
		}
		return count;
	};*/

	/*HRESULT __stdcall QueryInterface(const GUID& id, void** object) noexcept {
		if (id == __uuidof(IHen) || id == __uuidof(IUnknown)) {
			*object = static_cast<IHen*>(this);
		}
		else {
			*object = nullptr;
			return E_NOINTERFACE;
		}

		static_cast<IUnknown*>(*object)->AddRef();
		return S_OK;
	}*/

	HRESULT __stdcall Cluck() noexcept {
		Trace(L"Succe");
		return S_OK;
	};

};

template<typename T>
ComPtr<T> Make() noexcept {
	ComPtr<T> result;
	result.Attach(new (std::nothrow) T());
	return result;
};

HRESULT CreateHen(IHen** hen) noexcept {
	ComPtr<IHen> temp = Make<Hen>();
	if (!temp) {
		*hen = nullptr;
		return E_OUTOFMEMORY;
	}
	*hen = temp.Detach();
	return S_OK;

};

int main_2() {
	ComPtr<IHen> hen;
	HRESULT hr = CreateHen(hen.GetAddressOf());
	if (S_OK == hr) {
		hen->Cluck();
	}

	return 0;
};