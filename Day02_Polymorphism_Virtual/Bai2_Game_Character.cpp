// Họ và Tên: [Điền tên của bạn]
// MSSV: [Điền MSSV]
// ============================================================================
// DAY 02 - BÀI TẬP 2: ĐA HÌNH VÀ TƯƠNG TÁC ĐỐI TƯỢNG (RPG CHARACTERS)
// ============================================================================

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// ----------------------------------------------------------------------------
// 1. LỚP CƠ SỞ: Character
// ----------------------------------------------------------------------------
class Character {
protected:
    string name;
    int hp;
    int maxHp;

public:
    Character(string name, int maxHp) : name(name), hp(maxHp), maxHp(maxHp) {}
    virtual ~Character() {}

    string getName() const { return name; }
    int getHp() const { return hp; }
    bool isAlive() const { return hp > 0; }

    // Nhận sát thương cơ bản (trừ HP, tối thiểu về 0)
    virtual void takeDamage(int dmg) {
        hp -= dmg;
        if (hp < 0) hp = 0;
    }

    // TODO: Hàm thuần ảo tấn công mục tiêu khác
    virtual void attack(Character& target) = 0;
};

// ----------------------------------------------------------------------------
// 2. LỚP CON 1: Warrior (Chiến binh)
// ----------------------------------------------------------------------------
class Warrior : public Character {
private:
    int armor;       // Giáp giảm trừ sát thương
    int attackPower; // Sức mạnh tấn công vật lý

public:
    Warrior(string name, int maxHp, int armor, int power)
        : Character(name, maxHp), armor(armor), attackPower(power) {}

    // Warrior có giáp: Sát thương nhận thực tế = dmg - armor (nếu dmg <= armor thì nhận 1 sát thương)
    void takeDamage(int dmg) override {
        // TODO: Tính toán sát thương sau khi qua giáp và cập nhật hp
    }

    // Tấn công: Gây sát thương bằng attackPower lên target
    void attack(Character& target) override {
        // TODO: Gọi hàm target.takeDamage(attackPower)
    }
};

// ----------------------------------------------------------------------------
// 3. LỚP CON 2: Mage (Pháp sư)
// ----------------------------------------------------------------------------
class Mage : public Character {
private:
    int mp;          // Điểm ma pháp hiện tại
    int maxMp;       // Điểm ma pháp tối đa
    int spellPower;  // Sức mạnh phép thuật

public:
    Mage(string name, int maxHp, int maxMp, int spellPower)
        : Character(name, maxHp), mp(maxMp), maxMp(maxMp), spellPower(spellPower) {}

    int getMp() const { return mp; }

    // Pháp sư không có giáp, nhận sát thương thông thường từ Character
    // Nhưng khi tấn công:
    // Nếu MP >= 15: Tiêu hao 15 MP và gây sát thương bằng spellPower lên target.
    // Nếu MP < 15: Tấn công cơ bản yếu (chỉ gây 5 sát thương) và hồi lại 5 MP (tối đa bằng maxMp).
    void attack(Character& target) override {
        // TODO: Hoàn thành logic tung chiêu hoặc hồi ma pháp
    }
};

// ----------------------------------------------------------------------------
// HÀM KIỂM THỬ TỰ ĐỘNG
// ----------------------------------------------------------------------------
int main() {
    cout << "=== KIỂM THỬ DAY 02 - BÀI 2 ===" << endl;

    Warrior warrior("Thor", 100, 10, 30); // HP 100, Giáp 10, Đòn đánh 30
    Mage mage("Loki", 60, 30, 40);         // HP 60, MP 30, Phép 40

    // 1. Warrior đánh Mage (Mage không có giáp, nhận đủ 30 dame -> còn 30 HP)
    warrior.attack(mage);
    assert(mage.getHp() == 30);

    // 2. Mage dùng phép đánh Warrior (Sát thương phép 40 - Giáp 10 = 30 dame -> Warrior còn 70 HP)
    // MP của Mage giảm từ 30 -> 15
    mage.attack(warrior);
    assert(warrior.getHp() == 70);
    assert(mage.getMp() == 15);

    // 3. Mage dùng phép lần 2 (MP giảm từ 15 -> 0, Warrior nhận thêm 30 dame -> còn 40 HP)
    mage.attack(warrior);
    assert(warrior.getHp() == 40);
    assert(mage.getMp() == 0);

    // 4. Mage hết MP (< 15) -> Đánh cơ bản 5 dame.
    // Giáp Warrior 10 > 5 dame -> nhận tối thiểu 1 dame -> Warrior còn 39 HP.
    // Mage được hồi 5 MP -> MP = 5.
    mage.attack(warrior);
    assert(warrior.getHp() == 39);
    assert(mage.getMp() == 5);

    cout << "\n✅ CHÚC MỪNG: BẠN ĐÃ VƯỢT QUA TOÀN BỘ TEST CASES BÀI 2!" << endl;
    return 0;
}
