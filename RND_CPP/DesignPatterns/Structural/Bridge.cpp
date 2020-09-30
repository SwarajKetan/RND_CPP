#include <string>
#include <iostream>
#include <memory>

namespace Structural_Bridge {

	class Weapon {
	public:
		virtual ~Weapon() {};
		virtual void Use() = 0;
	};

	class Dagger : public Weapon {
	public:
		virtual void Use() override {
			std::cout << "using dagger" << std::endl;
		}
	};

	class Gun : public Weapon {
	public:
		virtual void Use() override {
			std::cout << "using gun" << std::endl;
		}
	};

	// abstraction
	class WeaponController {
	private:
		Weapon* weapon_;
	public:
		void setWeapon(Weapon* weapon) {
			weapon_ = weapon;
		}

		virtual void Use() {
			weapon_->Use();
		}
	};

	// player specific controller
	class PlayerOneWeaponController :public WeaponController {

		virtual void Use() override {
			WeaponController::Use();
		}

	};


	void Client() {

		std::unique_ptr<WeaponController> wc = std::make_unique<PlayerOneWeaponController>();
		// time 1
		auto dagger = new Dagger();
		auto gun = new Gun();

		// at some time
		wc->setWeapon(dagger);
		wc->Use();

		// at another time
		wc->setWeapon(gun);
		wc->Use();

	}
}

