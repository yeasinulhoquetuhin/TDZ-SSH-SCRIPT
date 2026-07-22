#include <vector>
#include <string>
#include <unordered_map>
#include <cstdint>
namespace tdz {

class Worker0 {
 public:
  explicit Worker0(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1 {
 public:
  explicit Worker1(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 85;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker2 {
 public:
  explicit Worker2(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 27) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker3 {
 public:
  explicit Worker3(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker4 {
 public:
  explicit Worker4(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 29;
    for (int x : xs) acc = (acc * 12) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker5 {
 public:
  explicit Worker5(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker6 {
 public:
  explicit Worker6(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker7 {
 public:
  explicit Worker7(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker8 {
 public:
  explicit Worker8(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker9 {
 public:
  explicit Worker9(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker10 {
 public:
  explicit Worker10(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 37) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker11 {
 public:
  explicit Worker11(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker12 {
 public:
  explicit Worker12(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 81) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker13 {
 public:
  explicit Worker13(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker14 {
 public:
  explicit Worker14(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 51) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker15 {
 public:
  explicit Worker15(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker16 {
 public:
  explicit Worker16(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker17 {
 public:
  explicit Worker17(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 112) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker18 {
 public:
  explicit Worker18(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker19 {
 public:
  explicit Worker19(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 66) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker20 {
 public:
  explicit Worker20(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 91;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker21 {
 public:
  explicit Worker21(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 75;
    for (int x : xs) acc = (acc * 79) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker22 {
 public:
  explicit Worker22(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 65;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker23 {
 public:
  explicit Worker23(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 21) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker24 {
 public:
  explicit Worker24(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker25 {
 public:
  explicit Worker25(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 45;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker26 {
 public:
  explicit Worker26(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker27 {
 public:
  explicit Worker27(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker28 {
 public:
  explicit Worker28(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 92) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker29 {
 public:
  explicit Worker29(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker30 {
 public:
  explicit Worker30(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 72) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker31 {
 public:
  explicit Worker31(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 91;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker32 {
 public:
  explicit Worker32(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker33 {
 public:
  explicit Worker33(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker34 {
 public:
  explicit Worker34(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 121) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker35 {
 public:
  explicit Worker35(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker36 {
 public:
  explicit Worker36(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker37 {
 public:
  explicit Worker37(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 66) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker38 {
 public:
  explicit Worker38(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker39 {
 public:
  explicit Worker39(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 117) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker40 {
 public:
  explicit Worker40(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 74) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker41 {
 public:
  explicit Worker41(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 74) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker42 {
 public:
  explicit Worker42(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 100) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker43 {
 public:
  explicit Worker43(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker44 {
 public:
  explicit Worker44(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker45 {
 public:
  explicit Worker45(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 127) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker46 {
 public:
  explicit Worker46(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 75) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker47 {
 public:
  explicit Worker47(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker48 {
 public:
  explicit Worker48(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 84) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker49 {
 public:
  explicit Worker49(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker50 {
 public:
  explicit Worker50(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker51 {
 public:
  explicit Worker51(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker52 {
 public:
  explicit Worker52(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 105) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker53 {
 public:
  explicit Worker53(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 26;
    for (int x : xs) acc = (acc * 20) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker54 {
 public:
  explicit Worker54(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker55 {
 public:
  explicit Worker55(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 45;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker56 {
 public:
  explicit Worker56(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker57 {
 public:
  explicit Worker57(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker58 {
 public:
  explicit Worker58(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker59 {
 public:
  explicit Worker59(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 67) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker60 {
 public:
  explicit Worker60(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker61 {
 public:
  explicit Worker61(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker62 {
 public:
  explicit Worker62(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 125) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker63 {
 public:
  explicit Worker63(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker64 {
 public:
  explicit Worker64(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker65 {
 public:
  explicit Worker65(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker66 {
 public:
  explicit Worker66(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker67 {
 public:
  explicit Worker67(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 40) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker68 {
 public:
  explicit Worker68(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 79) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker69 {
 public:
  explicit Worker69(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 91;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker70 {
 public:
  explicit Worker70(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 45) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker71 {
 public:
  explicit Worker71(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker72 {
 public:
  explicit Worker72(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 60) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker73 {
 public:
  explicit Worker73(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 105) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker74 {
 public:
  explicit Worker74(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker75 {
 public:
  explicit Worker75(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 10) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker76 {
 public:
  explicit Worker76(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker77 {
 public:
  explicit Worker77(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 26;
    for (int x : xs) acc = (acc * 91) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker78 {
 public:
  explicit Worker78(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 94;
    for (int x : xs) acc = (acc * 92) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker79 {
 public:
  explicit Worker79(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 12;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker80 {
 public:
  explicit Worker80(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker81 {
 public:
  explicit Worker81(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 45;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker82 {
 public:
  explicit Worker82(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 3) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker83 {
 public:
  explicit Worker83(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 85;
    for (int x : xs) acc = (acc * 91) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker84 {
 public:
  explicit Worker84(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker85 {
 public:
  explicit Worker85(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker86 {
 public:
  explicit Worker86(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 114) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker87 {
 public:
  explicit Worker87(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 104) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker88 {
 public:
  explicit Worker88(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker89 {
 public:
  explicit Worker89(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 35) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker90 {
 public:
  explicit Worker90(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker91 {
 public:
  explicit Worker91(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 80;
    for (int x : xs) acc = (acc * 124) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker92 {
 public:
  explicit Worker92(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker93 {
 public:
  explicit Worker93(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 29) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker94 {
 public:
  explicit Worker94(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 38) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker95 {
 public:
  explicit Worker95(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 26;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker96 {
 public:
  explicit Worker96(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker97 {
 public:
  explicit Worker97(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker98 {
 public:
  explicit Worker98(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker99 {
 public:
  explicit Worker99(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 93) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker100 {
 public:
  explicit Worker100(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker101 {
 public:
  explicit Worker101(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker102 {
 public:
  explicit Worker102(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 7) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker103 {
 public:
  explicit Worker103(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker104 {
 public:
  explicit Worker104(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker105 {
 public:
  explicit Worker105(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker106 {
 public:
  explicit Worker106(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker107 {
 public:
  explicit Worker107(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 126) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker108 {
 public:
  explicit Worker108(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker109 {
 public:
  explicit Worker109(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 26;
    for (int x : xs) acc = (acc * 73) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker110 {
 public:
  explicit Worker110(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 118) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker111 {
 public:
  explicit Worker111(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker112 {
 public:
  explicit Worker112(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker113 {
 public:
  explicit Worker113(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 59;
    for (int x : xs) acc = (acc * 125) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker114 {
 public:
  explicit Worker114(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker115 {
 public:
  explicit Worker115(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 117) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker116 {
 public:
  explicit Worker116(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 34) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker117 {
 public:
  explicit Worker117(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker118 {
 public:
  explicit Worker118(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker119 {
 public:
  explicit Worker119(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker120 {
 public:
  explicit Worker120(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker121 {
 public:
  explicit Worker121(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 67) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker122 {
 public:
  explicit Worker122(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker123 {
 public:
  explicit Worker123(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 127) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker124 {
 public:
  explicit Worker124(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 60) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker125 {
 public:
  explicit Worker125(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 113) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker126 {
 public:
  explicit Worker126(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker127 {
 public:
  explicit Worker127(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 94) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker128 {
 public:
  explicit Worker128(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker129 {
 public:
  explicit Worker129(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 45;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker130 {
 public:
  explicit Worker130(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 7) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker131 {
 public:
  explicit Worker131(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 78) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker132 {
 public:
  explicit Worker132(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker133 {
 public:
  explicit Worker133(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker134 {
 public:
  explicit Worker134(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker135 {
 public:
  explicit Worker135(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker136 {
 public:
  explicit Worker136(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker137 {
 public:
  explicit Worker137(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker138 {
 public:
  explicit Worker138(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 74) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker139 {
 public:
  explicit Worker139(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker140 {
 public:
  explicit Worker140(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 71) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker141 {
 public:
  explicit Worker141(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker142 {
 public:
  explicit Worker142(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 12;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker143 {
 public:
  explicit Worker143(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 34) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker144 {
 public:
  explicit Worker144(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker145 {
 public:
  explicit Worker145(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 71) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker146 {
 public:
  explicit Worker146(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker147 {
 public:
  explicit Worker147(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 70) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker148 {
 public:
  explicit Worker148(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker149 {
 public:
  explicit Worker149(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 81) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker150 {
 public:
  explicit Worker150(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 77) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker151 {
 public:
  explicit Worker151(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 48) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker152 {
 public:
  explicit Worker152(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 46;
    for (int x : xs) acc = (acc * 7) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker153 {
 public:
  explicit Worker153(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker154 {
 public:
  explicit Worker154(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 51) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker155 {
 public:
  explicit Worker155(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker156 {
 public:
  explicit Worker156(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 113) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker157 {
 public:
  explicit Worker157(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 71;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker158 {
 public:
  explicit Worker158(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker159 {
 public:
  explicit Worker159(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 45;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker160 {
 public:
  explicit Worker160(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 91) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker161 {
 public:
  explicit Worker161(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker162 {
 public:
  explicit Worker162(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker163 {
 public:
  explicit Worker163(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker164 {
 public:
  explicit Worker164(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 100) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker165 {
 public:
  explicit Worker165(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 75) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker166 {
 public:
  explicit Worker166(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 78) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker167 {
 public:
  explicit Worker167(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 60;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker168 {
 public:
  explicit Worker168(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 117) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker169 {
 public:
  explicit Worker169(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker170 {
 public:
  explicit Worker170(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 85) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker171 {
 public:
  explicit Worker171(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker172 {
 public:
  explicit Worker172(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker173 {
 public:
  explicit Worker173(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 100) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker174 {
 public:
  explicit Worker174(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 74) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker175 {
 public:
  explicit Worker175(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 85;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker176 {
 public:
  explicit Worker176(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker177 {
 public:
  explicit Worker177(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker178 {
 public:
  explicit Worker178(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker179 {
 public:
  explicit Worker179(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 79) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker180 {
 public:
  explicit Worker180(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker181 {
 public:
  explicit Worker181(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker182 {
 public:
  explicit Worker182(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker183 {
 public:
  explicit Worker183(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 40) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker184 {
 public:
  explicit Worker184(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 112) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker185 {
 public:
  explicit Worker185(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 7) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker186 {
 public:
  explicit Worker186(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 12;
    for (int x : xs) acc = (acc * 10) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker187 {
 public:
  explicit Worker187(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker188 {
 public:
  explicit Worker188(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 118) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker189 {
 public:
  explicit Worker189(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 7) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker190 {
 public:
  explicit Worker190(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker191 {
 public:
  explicit Worker191(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 3) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker192 {
 public:
  explicit Worker192(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker193 {
 public:
  explicit Worker193(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker194 {
 public:
  explicit Worker194(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 22) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker195 {
 public:
  explicit Worker195(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker196 {
 public:
  explicit Worker196(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker197 {
 public:
  explicit Worker197(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 22) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker198 {
 public:
  explicit Worker198(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker199 {
 public:
  explicit Worker199(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 80;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker200 {
 public:
  explicit Worker200(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 78;
    for (int x : xs) acc = (acc * 40) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker201 {
 public:
  explicit Worker201(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker202 {
 public:
  explicit Worker202(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 126) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker203 {
 public:
  explicit Worker203(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 64;
    for (int x : xs) acc = (acc * 71) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker204 {
 public:
  explicit Worker204(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker205 {
 public:
  explicit Worker205(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker206 {
 public:
  explicit Worker206(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker207 {
 public:
  explicit Worker207(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker208 {
 public:
  explicit Worker208(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 12;
    for (int x : xs) acc = (acc * 124) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker209 {
 public:
  explicit Worker209(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker210 {
 public:
  explicit Worker210(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 118) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker211 {
 public:
  explicit Worker211(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker212 {
 public:
  explicit Worker212(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker213 {
 public:
  explicit Worker213(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 70) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker214 {
 public:
  explicit Worker214(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 74) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker215 {
 public:
  explicit Worker215(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker216 {
 public:
  explicit Worker216(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 65;
    for (int x : xs) acc = (acc * 127) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker217 {
 public:
  explicit Worker217(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 43) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker218 {
 public:
  explicit Worker218(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 64;
    for (int x : xs) acc = (acc * 118) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker219 {
 public:
  explicit Worker219(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker220 {
 public:
  explicit Worker220(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 46;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker221 {
 public:
  explicit Worker221(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 87) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker222 {
 public:
  explicit Worker222(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker223 {
 public:
  explicit Worker223(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker224 {
 public:
  explicit Worker224(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 77) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker225 {
 public:
  explicit Worker225(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker226 {
 public:
  explicit Worker226(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 22) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker227 {
 public:
  explicit Worker227(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 73) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker228 {
 public:
  explicit Worker228(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 29) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker229 {
 public:
  explicit Worker229(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker230 {
 public:
  explicit Worker230(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 71) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker231 {
 public:
  explicit Worker231(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker232 {
 public:
  explicit Worker232(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 112) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker233 {
 public:
  explicit Worker233(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 105) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker234 {
 public:
  explicit Worker234(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker235 {
 public:
  explicit Worker235(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 108) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker236 {
 public:
  explicit Worker236(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 80;
    for (int x : xs) acc = (acc * 38) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker237 {
 public:
  explicit Worker237(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 64;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker238 {
 public:
  explicit Worker238(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 46) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker239 {
 public:
  explicit Worker239(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker240 {
 public:
  explicit Worker240(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker241 {
 public:
  explicit Worker241(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker242 {
 public:
  explicit Worker242(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker243 {
 public:
  explicit Worker243(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker244 {
 public:
  explicit Worker244(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker245 {
 public:
  explicit Worker245(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker246 {
 public:
  explicit Worker246(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 118) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker247 {
 public:
  explicit Worker247(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker248 {
 public:
  explicit Worker248(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 47) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker249 {
 public:
  explicit Worker249(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker250 {
 public:
  explicit Worker250(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 97) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker251 {
 public:
  explicit Worker251(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker252 {
 public:
  explicit Worker252(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 108) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker253 {
 public:
  explicit Worker253(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker254 {
 public:
  explicit Worker254(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker255 {
 public:
  explicit Worker255(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 65;
    for (int x : xs) acc = (acc * 74) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker256 {
 public:
  explicit Worker256(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker257 {
 public:
  explicit Worker257(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker258 {
 public:
  explicit Worker258(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 66) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker259 {
 public:
  explicit Worker259(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 117) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker260 {
 public:
  explicit Worker260(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker261 {
 public:
  explicit Worker261(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 111) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker262 {
 public:
  explicit Worker262(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker263 {
 public:
  explicit Worker263(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker264 {
 public:
  explicit Worker264(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 117) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker265 {
 public:
  explicit Worker265(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 60) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker266 {
 public:
  explicit Worker266(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker267 {
 public:
  explicit Worker267(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 12;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker268 {
 public:
  explicit Worker268(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker269 {
 public:
  explicit Worker269(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 84;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker270 {
 public:
  explicit Worker270(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 67) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker271 {
 public:
  explicit Worker271(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 114) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker272 {
 public:
  explicit Worker272(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 21) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker273 {
 public:
  explicit Worker273(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker274 {
 public:
  explicit Worker274(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 60) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker275 {
 public:
  explicit Worker275(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker276 {
 public:
  explicit Worker276(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker277 {
 public:
  explicit Worker277(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker278 {
 public:
  explicit Worker278(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 10) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker279 {
 public:
  explicit Worker279(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 81) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker280 {
 public:
  explicit Worker280(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker281 {
 public:
  explicit Worker281(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker282 {
 public:
  explicit Worker282(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker283 {
 public:
  explicit Worker283(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker284 {
 public:
  explicit Worker284(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker285 {
 public:
  explicit Worker285(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 104) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker286 {
 public:
  explicit Worker286(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 77) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker287 {
 public:
  explicit Worker287(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker288 {
 public:
  explicit Worker288(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker289 {
 public:
  explicit Worker289(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker290 {
 public:
  explicit Worker290(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 78) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker291 {
 public:
  explicit Worker291(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker292 {
 public:
  explicit Worker292(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 127) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker293 {
 public:
  explicit Worker293(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker294 {
 public:
  explicit Worker294(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker295 {
 public:
  explicit Worker295(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker296 {
 public:
  explicit Worker296(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker297 {
 public:
  explicit Worker297(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 118) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker298 {
 public:
  explicit Worker298(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker299 {
 public:
  explicit Worker299(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 87) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker300 {
 public:
  explicit Worker300(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker301 {
 public:
  explicit Worker301(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker302 {
 public:
  explicit Worker302(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 116) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker303 {
 public:
  explicit Worker303(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 3) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker304 {
 public:
  explicit Worker304(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 23) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker305 {
 public:
  explicit Worker305(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 34) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker306 {
 public:
  explicit Worker306(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 100) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker307 {
 public:
  explicit Worker307(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 113) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker308 {
 public:
  explicit Worker308(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 124) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker309 {
 public:
  explicit Worker309(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 117) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker310 {
 public:
  explicit Worker310(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker311 {
 public:
  explicit Worker311(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 108) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker312 {
 public:
  explicit Worker312(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker313 {
 public:
  explicit Worker313(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker314 {
 public:
  explicit Worker314(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker315 {
 public:
  explicit Worker315(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 26;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker316 {
 public:
  explicit Worker316(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 72) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker317 {
 public:
  explicit Worker317(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 80;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker318 {
 public:
  explicit Worker318(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 84) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker319 {
 public:
  explicit Worker319(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 3) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker320 {
 public:
  explicit Worker320(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker321 {
 public:
  explicit Worker321(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker322 {
 public:
  explicit Worker322(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 113) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker323 {
 public:
  explicit Worker323(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker324 {
 public:
  explicit Worker324(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker325 {
 public:
  explicit Worker325(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker326 {
 public:
  explicit Worker326(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker327 {
 public:
  explicit Worker327(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 78;
    for (int x : xs) acc = (acc * 23) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker328 {
 public:
  explicit Worker328(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker329 {
 public:
  explicit Worker329(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 107) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker330 {
 public:
  explicit Worker330(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 85;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker331 {
 public:
  explicit Worker331(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker332 {
 public:
  explicit Worker332(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 29) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker333 {
 public:
  explicit Worker333(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker334 {
 public:
  explicit Worker334(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker335 {
 public:
  explicit Worker335(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 117) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker336 {
 public:
  explicit Worker336(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 37) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker337 {
 public:
  explicit Worker337(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 60;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker338 {
 public:
  explicit Worker338(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 34) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker339 {
 public:
  explicit Worker339(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 74) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker340 {
 public:
  explicit Worker340(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker341 {
 public:
  explicit Worker341(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker342 {
 public:
  explicit Worker342(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker343 {
 public:
  explicit Worker343(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 75) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker344 {
 public:
  explicit Worker344(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker345 {
 public:
  explicit Worker345(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker346 {
 public:
  explicit Worker346(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker347 {
 public:
  explicit Worker347(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 85;
    for (int x : xs) acc = (acc * 121) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker348 {
 public:
  explicit Worker348(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker349 {
 public:
  explicit Worker349(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 117) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker350 {
 public:
  explicit Worker350(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 78) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker351 {
 public:
  explicit Worker351(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker352 {
 public:
  explicit Worker352(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 78;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker353 {
 public:
  explicit Worker353(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 48) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker354 {
 public:
  explicit Worker354(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker355 {
 public:
  explicit Worker355(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 92) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker356 {
 public:
  explicit Worker356(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 97) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker357 {
 public:
  explicit Worker357(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker358 {
 public:
  explicit Worker358(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 12) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker359 {
 public:
  explicit Worker359(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker360 {
 public:
  explicit Worker360(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 98) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker361 {
 public:
  explicit Worker361(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker362 {
 public:
  explicit Worker362(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker363 {
 public:
  explicit Worker363(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 126) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker364 {
 public:
  explicit Worker364(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker365 {
 public:
  explicit Worker365(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker366 {
 public:
  explicit Worker366(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker367 {
 public:
  explicit Worker367(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 91;
    for (int x : xs) acc = (acc * 72) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker368 {
 public:
  explicit Worker368(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 81) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker369 {
 public:
  explicit Worker369(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker370 {
 public:
  explicit Worker370(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 109) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker371 {
 public:
  explicit Worker371(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker372 {
 public:
  explicit Worker372(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker373 {
 public:
  explicit Worker373(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 114) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker374 {
 public:
  explicit Worker374(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker375 {
 public:
  explicit Worker375(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker376 {
 public:
  explicit Worker376(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker377 {
 public:
  explicit Worker377(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker378 {
 public:
  explicit Worker378(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 97) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker379 {
 public:
  explicit Worker379(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 40) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker380 {
 public:
  explicit Worker380(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker381 {
 public:
  explicit Worker381(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 20) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker382 {
 public:
  explicit Worker382(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker383 {
 public:
  explicit Worker383(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 35) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker384 {
 public:
  explicit Worker384(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker385 {
 public:
  explicit Worker385(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 102) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker386 {
 public:
  explicit Worker386(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker387 {
 public:
  explicit Worker387(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker388 {
 public:
  explicit Worker388(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker389 {
 public:
  explicit Worker389(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 105) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker390 {
 public:
  explicit Worker390(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker391 {
 public:
  explicit Worker391(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker392 {
 public:
  explicit Worker392(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 94;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker393 {
 public:
  explicit Worker393(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 12) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker394 {
 public:
  explicit Worker394(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 102) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker395 {
 public:
  explicit Worker395(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 81) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker396 {
 public:
  explicit Worker396(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 66) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker397 {
 public:
  explicit Worker397(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 97) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker398 {
 public:
  explicit Worker398(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker399 {
 public:
  explicit Worker399(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 3) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker400 {
 public:
  explicit Worker400(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker401 {
 public:
  explicit Worker401(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker402 {
 public:
  explicit Worker402(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 105) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker403 {
 public:
  explicit Worker403(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 35) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker404 {
 public:
  explicit Worker404(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker405 {
 public:
  explicit Worker405(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker406 {
 public:
  explicit Worker406(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker407 {
 public:
  explicit Worker407(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker408 {
 public:
  explicit Worker408(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 12;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker409 {
 public:
  explicit Worker409(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 37) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker410 {
 public:
  explicit Worker410(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker411 {
 public:
  explicit Worker411(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker412 {
 public:
  explicit Worker412(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker413 {
 public:
  explicit Worker413(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 46;
    for (int x : xs) acc = (acc * 67) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker414 {
 public:
  explicit Worker414(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 73) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker415 {
 public:
  explicit Worker415(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker416 {
 public:
  explicit Worker416(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker417 {
 public:
  explicit Worker417(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 80;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker418 {
 public:
  explicit Worker418(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 12) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker419 {
 public:
  explicit Worker419(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker420 {
 public:
  explicit Worker420(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 74) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker421 {
 public:
  explicit Worker421(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 46) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker422 {
 public:
  explicit Worker422(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker423 {
 public:
  explicit Worker423(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 59;
    for (int x : xs) acc = (acc * 29) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker424 {
 public:
  explicit Worker424(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker425 {
 public:
  explicit Worker425(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker426 {
 public:
  explicit Worker426(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 75;
    for (int x : xs) acc = (acc * 40) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker427 {
 public:
  explicit Worker427(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 23) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker428 {
 public:
  explicit Worker428(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 48) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker429 {
 public:
  explicit Worker429(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 67) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker430 {
 public:
  explicit Worker430(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker431 {
 public:
  explicit Worker431(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker432 {
 public:
  explicit Worker432(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 77) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker433 {
 public:
  explicit Worker433(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker434 {
 public:
  explicit Worker434(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker435 {
 public:
  explicit Worker435(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 80;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker436 {
 public:
  explicit Worker436(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 3) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker437 {
 public:
  explicit Worker437(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker438 {
 public:
  explicit Worker438(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 60) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker439 {
 public:
  explicit Worker439(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker440 {
 public:
  explicit Worker440(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker441 {
 public:
  explicit Worker441(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 37) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker442 {
 public:
  explicit Worker442(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker443 {
 public:
  explicit Worker443(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker444 {
 public:
  explicit Worker444(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 72) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker445 {
 public:
  explicit Worker445(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 5) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker446 {
 public:
  explicit Worker446(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 84;
    for (int x : xs) acc = (acc * 92) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker447 {
 public:
  explicit Worker447(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker448 {
 public:
  explicit Worker448(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 3) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker449 {
 public:
  explicit Worker449(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 9) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker450 {
 public:
  explicit Worker450(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker451 {
 public:
  explicit Worker451(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 29) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker452 {
 public:
  explicit Worker452(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 80;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker453 {
 public:
  explicit Worker453(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker454 {
 public:
  explicit Worker454(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 109) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker455 {
 public:
  explicit Worker455(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker456 {
 public:
  explicit Worker456(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker457 {
 public:
  explicit Worker457(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker458 {
 public:
  explicit Worker458(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker459 {
 public:
  explicit Worker459(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 118) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker460 {
 public:
  explicit Worker460(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 29) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker461 {
 public:
  explicit Worker461(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 12) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker462 {
 public:
  explicit Worker462(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 70) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker463 {
 public:
  explicit Worker463(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 114) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker464 {
 public:
  explicit Worker464(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 78) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker465 {
 public:
  explicit Worker465(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 12;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker466 {
 public:
  explicit Worker466(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker467 {
 public:
  explicit Worker467(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker468 {
 public:
  explicit Worker468(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 87) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker469 {
 public:
  explicit Worker469(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker470 {
 public:
  explicit Worker470(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker471 {
 public:
  explicit Worker471(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker472 {
 public:
  explicit Worker472(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 29;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker473 {
 public:
  explicit Worker473(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 46) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker474 {
 public:
  explicit Worker474(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 9) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker475 {
 public:
  explicit Worker475(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker476 {
 public:
  explicit Worker476(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 10) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker477 {
 public:
  explicit Worker477(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 38) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker478 {
 public:
  explicit Worker478(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 91;
    for (int x : xs) acc = (acc * 20) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker479 {
 public:
  explicit Worker479(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker480 {
 public:
  explicit Worker480(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker481 {
 public:
  explicit Worker481(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 66) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker482 {
 public:
  explicit Worker482(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker483 {
 public:
  explicit Worker483(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker484 {
 public:
  explicit Worker484(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker485 {
 public:
  explicit Worker485(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker486 {
 public:
  explicit Worker486(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker487 {
 public:
  explicit Worker487(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker488 {
 public:
  explicit Worker488(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 75) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker489 {
 public:
  explicit Worker489(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 97) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker490 {
 public:
  explicit Worker490(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker491 {
 public:
  explicit Worker491(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 10) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker492 {
 public:
  explicit Worker492(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 114) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker493 {
 public:
  explicit Worker493(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 91) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker494 {
 public:
  explicit Worker494(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker495 {
 public:
  explicit Worker495(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker496 {
 public:
  explicit Worker496(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 75;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker497 {
 public:
  explicit Worker497(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 3) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker498 {
 public:
  explicit Worker498(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker499 {
 public:
  explicit Worker499(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 92) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker500 {
 public:
  explicit Worker500(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker501 {
 public:
  explicit Worker501(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 65;
    for (int x : xs) acc = (acc * 91) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker502 {
 public:
  explicit Worker502(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 43) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker503 {
 public:
  explicit Worker503(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 29;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker504 {
 public:
  explicit Worker504(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker505 {
 public:
  explicit Worker505(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 64;
    for (int x : xs) acc = (acc * 29) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker506 {
 public:
  explicit Worker506(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 27) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker507 {
 public:
  explicit Worker507(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker508 {
 public:
  explicit Worker508(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 84;
    for (int x : xs) acc = (acc * 9) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker509 {
 public:
  explicit Worker509(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker510 {
 public:
  explicit Worker510(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker511 {
 public:
  explicit Worker511(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker512 {
 public:
  explicit Worker512(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker513 {
 public:
  explicit Worker513(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker514 {
 public:
  explicit Worker514(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 118) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker515 {
 public:
  explicit Worker515(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 85) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker516 {
 public:
  explicit Worker516(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker517 {
 public:
  explicit Worker517(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker518 {
 public:
  explicit Worker518(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 121) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker519 {
 public:
  explicit Worker519(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker520 {
 public:
  explicit Worker520(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker521 {
 public:
  explicit Worker521(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker522 {
 public:
  explicit Worker522(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 46;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker523 {
 public:
  explicit Worker523(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 51) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker524 {
 public:
  explicit Worker524(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 29) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker525 {
 public:
  explicit Worker525(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 29) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker526 {
 public:
  explicit Worker526(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker527 {
 public:
  explicit Worker527(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 79) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker528 {
 public:
  explicit Worker528(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker529 {
 public:
  explicit Worker529(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker530 {
 public:
  explicit Worker530(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 102) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker531 {
 public:
  explicit Worker531(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker532 {
 public:
  explicit Worker532(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker533 {
 public:
  explicit Worker533(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 78) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker534 {
 public:
  explicit Worker534(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker535 {
 public:
  explicit Worker535(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker536 {
 public:
  explicit Worker536(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker537 {
 public:
  explicit Worker537(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 91;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker538 {
 public:
  explicit Worker538(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker539 {
 public:
  explicit Worker539(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 84;
    for (int x : xs) acc = (acc * 34) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker540 {
 public:
  explicit Worker540(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker541 {
 public:
  explicit Worker541(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker542 {
 public:
  explicit Worker542(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 105) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker543 {
 public:
  explicit Worker543(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 111) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker544 {
 public:
  explicit Worker544(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 60;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker545 {
 public:
  explicit Worker545(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker546 {
 public:
  explicit Worker546(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 102) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker547 {
 public:
  explicit Worker547(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 12) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker548 {
 public:
  explicit Worker548(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 71;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker549 {
 public:
  explicit Worker549(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker550 {
 public:
  explicit Worker550(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 46;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker551 {
 public:
  explicit Worker551(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 71;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker552 {
 public:
  explicit Worker552(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 7) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker553 {
 public:
  explicit Worker553(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker554 {
 public:
  explicit Worker554(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker555 {
 public:
  explicit Worker555(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker556 {
 public:
  explicit Worker556(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 34) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker557 {
 public:
  explicit Worker557(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker558 {
 public:
  explicit Worker558(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 100) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker559 {
 public:
  explicit Worker559(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker560 {
 public:
  explicit Worker560(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker561 {
 public:
  explicit Worker561(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 70) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker562 {
 public:
  explicit Worker562(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker563 {
 public:
  explicit Worker563(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker564 {
 public:
  explicit Worker564(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker565 {
 public:
  explicit Worker565(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 20) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker566 {
 public:
  explicit Worker566(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 60) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker567 {
 public:
  explicit Worker567(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 108) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker568 {
 public:
  explicit Worker568(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 35) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker569 {
 public:
  explicit Worker569(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker570 {
 public:
  explicit Worker570(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker571 {
 public:
  explicit Worker571(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker572 {
 public:
  explicit Worker572(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 74) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker573 {
 public:
  explicit Worker573(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker574 {
 public:
  explicit Worker574(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 127) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker575 {
 public:
  explicit Worker575(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker576 {
 public:
  explicit Worker576(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker577 {
 public:
  explicit Worker577(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker578 {
 public:
  explicit Worker578(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 91) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker579 {
 public:
  explicit Worker579(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 5) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker580 {
 public:
  explicit Worker580(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 78) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker581 {
 public:
  explicit Worker581(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker582 {
 public:
  explicit Worker582(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker583 {
 public:
  explicit Worker583(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 46;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker584 {
 public:
  explicit Worker584(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 45) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker585 {
 public:
  explicit Worker585(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 79) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker586 {
 public:
  explicit Worker586(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 65;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker587 {
 public:
  explicit Worker587(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 12;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker588 {
 public:
  explicit Worker588(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker589 {
 public:
  explicit Worker589(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker590 {
 public:
  explicit Worker590(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker591 {
 public:
  explicit Worker591(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 126) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker592 {
 public:
  explicit Worker592(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker593 {
 public:
  explicit Worker593(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 65;
    for (int x : xs) acc = (acc * 45) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker594 {
 public:
  explicit Worker594(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 78;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker595 {
 public:
  explicit Worker595(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker596 {
 public:
  explicit Worker596(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 78) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker597 {
 public:
  explicit Worker597(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 112) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker598 {
 public:
  explicit Worker598(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 22) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker599 {
 public:
  explicit Worker599(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker600 {
 public:
  explicit Worker600(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker601 {
 public:
  explicit Worker601(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 126) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker602 {
 public:
  explicit Worker602(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker603 {
 public:
  explicit Worker603(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 109) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker604 {
 public:
  explicit Worker604(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 45;
    for (int x : xs) acc = (acc * 27) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker605 {
 public:
  explicit Worker605(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 45;
    for (int x : xs) acc = (acc * 124) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker606 {
 public:
  explicit Worker606(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker607 {
 public:
  explicit Worker607(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker608 {
 public:
  explicit Worker608(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker609 {
 public:
  explicit Worker609(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 93) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker610 {
 public:
  explicit Worker610(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 88) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker611 {
 public:
  explicit Worker611(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 91) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker612 {
 public:
  explicit Worker612(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 85;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker613 {
 public:
  explicit Worker613(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker614 {
 public:
  explicit Worker614(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 79) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker615 {
 public:
  explicit Worker615(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker616 {
 public:
  explicit Worker616(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker617 {
 public:
  explicit Worker617(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 75;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker618 {
 public:
  explicit Worker618(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker619 {
 public:
  explicit Worker619(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 51) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker620 {
 public:
  explicit Worker620(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker621 {
 public:
  explicit Worker621(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 71;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker622 {
 public:
  explicit Worker622(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker623 {
 public:
  explicit Worker623(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker624 {
 public:
  explicit Worker624(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker625 {
 public:
  explicit Worker625(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker626 {
 public:
  explicit Worker626(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 38) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker627 {
 public:
  explicit Worker627(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker628 {
 public:
  explicit Worker628(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker629 {
 public:
  explicit Worker629(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker630 {
 public:
  explicit Worker630(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker631 {
 public:
  explicit Worker631(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker632 {
 public:
  explicit Worker632(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker633 {
 public:
  explicit Worker633(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker634 {
 public:
  explicit Worker634(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 78;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker635 {
 public:
  explicit Worker635(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 29) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker636 {
 public:
  explicit Worker636(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 84;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker637 {
 public:
  explicit Worker637(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker638 {
 public:
  explicit Worker638(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 5) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker639 {
 public:
  explicit Worker639(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker640 {
 public:
  explicit Worker640(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker641 {
 public:
  explicit Worker641(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker642 {
 public:
  explicit Worker642(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker643 {
 public:
  explicit Worker643(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 40) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker644 {
 public:
  explicit Worker644(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker645 {
 public:
  explicit Worker645(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker646 {
 public:
  explicit Worker646(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker647 {
 public:
  explicit Worker647(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker648 {
 public:
  explicit Worker648(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker649 {
 public:
  explicit Worker649(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 45) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker650 {
 public:
  explicit Worker650(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker651 {
 public:
  explicit Worker651(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker652 {
 public:
  explicit Worker652(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 45) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker653 {
 public:
  explicit Worker653(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker654 {
 public:
  explicit Worker654(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 109) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker655 {
 public:
  explicit Worker655(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 118) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker656 {
 public:
  explicit Worker656(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 88) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker657 {
 public:
  explicit Worker657(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker658 {
 public:
  explicit Worker658(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker659 {
 public:
  explicit Worker659(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 78;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker660 {
 public:
  explicit Worker660(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker661 {
 public:
  explicit Worker661(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker662 {
 public:
  explicit Worker662(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 59;
    for (int x : xs) acc = (acc * 75) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker663 {
 public:
  explicit Worker663(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 70) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker664 {
 public:
  explicit Worker664(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 43) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker665 {
 public:
  explicit Worker665(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker666 {
 public:
  explicit Worker666(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker667 {
 public:
  explicit Worker667(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker668 {
 public:
  explicit Worker668(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 127) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker669 {
 public:
  explicit Worker669(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker670 {
 public:
  explicit Worker670(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker671 {
 public:
  explicit Worker671(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker672 {
 public:
  explicit Worker672(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 5) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker673 {
 public:
  explicit Worker673(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 60;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker674 {
 public:
  explicit Worker674(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker675 {
 public:
  explicit Worker675(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker676 {
 public:
  explicit Worker676(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 125) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker677 {
 public:
  explicit Worker677(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker678 {
 public:
  explicit Worker678(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 29;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker679 {
 public:
  explicit Worker679(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 77) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker680 {
 public:
  explicit Worker680(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 75;
    for (int x : xs) acc = (acc * 94) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker681 {
 public:
  explicit Worker681(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker682 {
 public:
  explicit Worker682(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker683 {
 public:
  explicit Worker683(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 98) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker684 {
 public:
  explicit Worker684(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 12;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker685 {
 public:
  explicit Worker685(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 78;
    for (int x : xs) acc = (acc * 10) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker686 {
 public:
  explicit Worker686(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker687 {
 public:
  explicit Worker687(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker688 {
 public:
  explicit Worker688(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker689 {
 public:
  explicit Worker689(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 112) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker690 {
 public:
  explicit Worker690(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 59;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker691 {
 public:
  explicit Worker691(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker692 {
 public:
  explicit Worker692(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker693 {
 public:
  explicit Worker693(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker694 {
 public:
  explicit Worker694(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 97) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker695 {
 public:
  explicit Worker695(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 64;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker696 {
 public:
  explicit Worker696(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker697 {
 public:
  explicit Worker697(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker698 {
 public:
  explicit Worker698(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker699 {
 public:
  explicit Worker699(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 59;
    for (int x : xs) acc = (acc * 43) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker700 {
 public:
  explicit Worker700(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker701 {
 public:
  explicit Worker701(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker702 {
 public:
  explicit Worker702(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 10) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker703 {
 public:
  explicit Worker703(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 126) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker704 {
 public:
  explicit Worker704(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 40) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker705 {
 public:
  explicit Worker705(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker706 {
 public:
  explicit Worker706(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker707 {
 public:
  explicit Worker707(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 85) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker708 {
 public:
  explicit Worker708(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 102) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker709 {
 public:
  explicit Worker709(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 126) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker710 {
 public:
  explicit Worker710(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker711 {
 public:
  explicit Worker711(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker712 {
 public:
  explicit Worker712(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker713 {
 public:
  explicit Worker713(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker714 {
 public:
  explicit Worker714(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 98) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker715 {
 public:
  explicit Worker715(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 59;
    for (int x : xs) acc = (acc * 27) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker716 {
 public:
  explicit Worker716(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 22) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker717 {
 public:
  explicit Worker717(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 45;
    for (int x : xs) acc = (acc * 85) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker718 {
 public:
  explicit Worker718(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker719 {
 public:
  explicit Worker719(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 87) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker720 {
 public:
  explicit Worker720(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker721 {
 public:
  explicit Worker721(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 118) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker722 {
 public:
  explicit Worker722(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker723 {
 public:
  explicit Worker723(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker724 {
 public:
  explicit Worker724(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker725 {
 public:
  explicit Worker725(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 78) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker726 {
 public:
  explicit Worker726(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker727 {
 public:
  explicit Worker727(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 84) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker728 {
 public:
  explicit Worker728(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker729 {
 public:
  explicit Worker729(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker730 {
 public:
  explicit Worker730(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 125) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker731 {
 public:
  explicit Worker731(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker732 {
 public:
  explicit Worker732(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 113) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker733 {
 public:
  explicit Worker733(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker734 {
 public:
  explicit Worker734(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 77) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker735 {
 public:
  explicit Worker735(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker736 {
 public:
  explicit Worker736(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 7) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker737 {
 public:
  explicit Worker737(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker738 {
 public:
  explicit Worker738(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 116) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker739 {
 public:
  explicit Worker739(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker740 {
 public:
  explicit Worker740(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 114) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker741 {
 public:
  explicit Worker741(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker742 {
 public:
  explicit Worker742(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 75;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker743 {
 public:
  explicit Worker743(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker744 {
 public:
  explicit Worker744(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 23) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker745 {
 public:
  explicit Worker745(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker746 {
 public:
  explicit Worker746(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker747 {
 public:
  explicit Worker747(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 80;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker748 {
 public:
  explicit Worker748(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 5) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker749 {
 public:
  explicit Worker749(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 107) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker750 {
 public:
  explicit Worker750(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 91) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker751 {
 public:
  explicit Worker751(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker752 {
 public:
  explicit Worker752(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 107) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker753 {
 public:
  explicit Worker753(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 71) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker754 {
 public:
  explicit Worker754(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker755 {
 public:
  explicit Worker755(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 98) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker756 {
 public:
  explicit Worker756(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 117) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker757 {
 public:
  explicit Worker757(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker758 {
 public:
  explicit Worker758(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker759 {
 public:
  explicit Worker759(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 100) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker760 {
 public:
  explicit Worker760(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker761 {
 public:
  explicit Worker761(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 59;
    for (int x : xs) acc = (acc * 9) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker762 {
 public:
  explicit Worker762(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 37) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker763 {
 public:
  explicit Worker763(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker764 {
 public:
  explicit Worker764(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker765 {
 public:
  explicit Worker765(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker766 {
 public:
  explicit Worker766(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 10) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker767 {
 public:
  explicit Worker767(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker768 {
 public:
  explicit Worker768(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 121) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker769 {
 public:
  explicit Worker769(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 116) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker770 {
 public:
  explicit Worker770(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 46;
    for (int x : xs) acc = (acc * 27) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker771 {
 public:
  explicit Worker771(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 72) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker772 {
 public:
  explicit Worker772(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker773 {
 public:
  explicit Worker773(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker774 {
 public:
  explicit Worker774(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker775 {
 public:
  explicit Worker775(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 71;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker776 {
 public:
  explicit Worker776(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 121) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker777 {
 public:
  explicit Worker777(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 7) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker778 {
 public:
  explicit Worker778(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker779 {
 public:
  explicit Worker779(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 104) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker780 {
 public:
  explicit Worker780(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker781 {
 public:
  explicit Worker781(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 88) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker782 {
 public:
  explicit Worker782(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 85) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker783 {
 public:
  explicit Worker783(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker784 {
 public:
  explicit Worker784(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 40) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker785 {
 public:
  explicit Worker785(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 111) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker786 {
 public:
  explicit Worker786(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker787 {
 public:
  explicit Worker787(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 20) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker788 {
 public:
  explicit Worker788(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker789 {
 public:
  explicit Worker789(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker790 {
 public:
  explicit Worker790(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker791 {
 public:
  explicit Worker791(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 60;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker792 {
 public:
  explicit Worker792(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 71) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker793 {
 public:
  explicit Worker793(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 12) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker794 {
 public:
  explicit Worker794(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 34) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker795 {
 public:
  explicit Worker795(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 114) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker796 {
 public:
  explicit Worker796(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker797 {
 public:
  explicit Worker797(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 91) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker798 {
 public:
  explicit Worker798(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker799 {
 public:
  explicit Worker799(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker800 {
 public:
  explicit Worker800(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 40) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker801 {
 public:
  explicit Worker801(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker802 {
 public:
  explicit Worker802(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker803 {
 public:
  explicit Worker803(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker804 {
 public:
  explicit Worker804(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker805 {
 public:
  explicit Worker805(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 85;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker806 {
 public:
  explicit Worker806(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker807 {
 public:
  explicit Worker807(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker808 {
 public:
  explicit Worker808(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker809 {
 public:
  explicit Worker809(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 88) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker810 {
 public:
  explicit Worker810(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 26;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker811 {
 public:
  explicit Worker811(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 93) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker812 {
 public:
  explicit Worker812(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 85) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker813 {
 public:
  explicit Worker813(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker814 {
 public:
  explicit Worker814(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker815 {
 public:
  explicit Worker815(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker816 {
 public:
  explicit Worker816(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 20) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker817 {
 public:
  explicit Worker817(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker818 {
 public:
  explicit Worker818(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker819 {
 public:
  explicit Worker819(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker820 {
 public:
  explicit Worker820(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker821 {
 public:
  explicit Worker821(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 45;
    for (int x : xs) acc = (acc * 93) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker822 {
 public:
  explicit Worker822(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker823 {
 public:
  explicit Worker823(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 27) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker824 {
 public:
  explicit Worker824(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 35) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker825 {
 public:
  explicit Worker825(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker826 {
 public:
  explicit Worker826(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker827 {
 public:
  explicit Worker827(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker828 {
 public:
  explicit Worker828(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker829 {
 public:
  explicit Worker829(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 59;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker830 {
 public:
  explicit Worker830(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 94;
    for (int x : xs) acc = (acc * 93) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker831 {
 public:
  explicit Worker831(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker832 {
 public:
  explicit Worker832(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker833 {
 public:
  explicit Worker833(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker834 {
 public:
  explicit Worker834(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 79) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker835 {
 public:
  explicit Worker835(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker836 {
 public:
  explicit Worker836(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker837 {
 public:
  explicit Worker837(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 87) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker838 {
 public:
  explicit Worker838(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker839 {
 public:
  explicit Worker839(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 112) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker840 {
 public:
  explicit Worker840(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker841 {
 public:
  explicit Worker841(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker842 {
 public:
  explicit Worker842(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker843 {
 public:
  explicit Worker843(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 114) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker844 {
 public:
  explicit Worker844(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 113) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker845 {
 public:
  explicit Worker845(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 94) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker846 {
 public:
  explicit Worker846(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 78;
    for (int x : xs) acc = (acc * 92) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker847 {
 public:
  explicit Worker847(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 20) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker848 {
 public:
  explicit Worker848(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker849 {
 public:
  explicit Worker849(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker850 {
 public:
  explicit Worker850(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 85;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker851 {
 public:
  explicit Worker851(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 127) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker852 {
 public:
  explicit Worker852(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker853 {
 public:
  explicit Worker853(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker854 {
 public:
  explicit Worker854(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 84) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker855 {
 public:
  explicit Worker855(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker856 {
 public:
  explicit Worker856(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker857 {
 public:
  explicit Worker857(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker858 {
 public:
  explicit Worker858(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 43) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker859 {
 public:
  explicit Worker859(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker860 {
 public:
  explicit Worker860(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 26;
    for (int x : xs) acc = (acc * 108) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker861 {
 public:
  explicit Worker861(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker862 {
 public:
  explicit Worker862(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker863 {
 public:
  explicit Worker863(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 3) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker864 {
 public:
  explicit Worker864(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker865 {
 public:
  explicit Worker865(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker866 {
 public:
  explicit Worker866(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 10) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker867 {
 public:
  explicit Worker867(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker868 {
 public:
  explicit Worker868(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 71) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker869 {
 public:
  explicit Worker869(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker870 {
 public:
  explicit Worker870(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 34) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker871 {
 public:
  explicit Worker871(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker872 {
 public:
  explicit Worker872(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 22) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker873 {
 public:
  explicit Worker873(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker874 {
 public:
  explicit Worker874(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 80;
    for (int x : xs) acc = (acc * 113) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker875 {
 public:
  explicit Worker875(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 85;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker876 {
 public:
  explicit Worker876(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker877 {
 public:
  explicit Worker877(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 46) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker878 {
 public:
  explicit Worker878(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker879 {
 public:
  explicit Worker879(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 46;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker880 {
 public:
  explicit Worker880(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker881 {
 public:
  explicit Worker881(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker882 {
 public:
  explicit Worker882(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker883 {
 public:
  explicit Worker883(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker884 {
 public:
  explicit Worker884(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker885 {
 public:
  explicit Worker885(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 47) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker886 {
 public:
  explicit Worker886(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker887 {
 public:
  explicit Worker887(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 67) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker888 {
 public:
  explicit Worker888(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker889 {
 public:
  explicit Worker889(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker890 {
 public:
  explicit Worker890(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 105) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker891 {
 public:
  explicit Worker891(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker892 {
 public:
  explicit Worker892(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 46) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker893 {
 public:
  explicit Worker893(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker894 {
 public:
  explicit Worker894(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 104) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker895 {
 public:
  explicit Worker895(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker896 {
 public:
  explicit Worker896(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker897 {
 public:
  explicit Worker897(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker898 {
 public:
  explicit Worker898(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 92) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker899 {
 public:
  explicit Worker899(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 102) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker900 {
 public:
  explicit Worker900(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 75) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker901 {
 public:
  explicit Worker901(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 114) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker902 {
 public:
  explicit Worker902(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 9) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker903 {
 public:
  explicit Worker903(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker904 {
 public:
  explicit Worker904(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker905 {
 public:
  explicit Worker905(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 71;
    for (int x : xs) acc = (acc * 35) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker906 {
 public:
  explicit Worker906(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker907 {
 public:
  explicit Worker907(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 97) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker908 {
 public:
  explicit Worker908(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 29;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker909 {
 public:
  explicit Worker909(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker910 {
 public:
  explicit Worker910(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker911 {
 public:
  explicit Worker911(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 59;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker912 {
 public:
  explicit Worker912(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 78;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker913 {
 public:
  explicit Worker913(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 66) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker914 {
 public:
  explicit Worker914(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker915 {
 public:
  explicit Worker915(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker916 {
 public:
  explicit Worker916(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker917 {
 public:
  explicit Worker917(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 40) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker918 {
 public:
  explicit Worker918(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 102) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker919 {
 public:
  explicit Worker919(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 48) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker920 {
 public:
  explicit Worker920(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 51) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker921 {
 public:
  explicit Worker921(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker922 {
 public:
  explicit Worker922(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker923 {
 public:
  explicit Worker923(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker924 {
 public:
  explicit Worker924(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker925 {
 public:
  explicit Worker925(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 105) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker926 {
 public:
  explicit Worker926(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker927 {
 public:
  explicit Worker927(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker928 {
 public:
  explicit Worker928(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 10) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker929 {
 public:
  explicit Worker929(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 92) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker930 {
 public:
  explicit Worker930(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 121) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker931 {
 public:
  explicit Worker931(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 93) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker932 {
 public:
  explicit Worker932(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 77) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker933 {
 public:
  explicit Worker933(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker934 {
 public:
  explicit Worker934(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker935 {
 public:
  explicit Worker935(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker936 {
 public:
  explicit Worker936(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 100) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker937 {
 public:
  explicit Worker937(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker938 {
 public:
  explicit Worker938(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker939 {
 public:
  explicit Worker939(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker940 {
 public:
  explicit Worker940(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 92) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker941 {
 public:
  explicit Worker941(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker942 {
 public:
  explicit Worker942(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker943 {
 public:
  explicit Worker943(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker944 {
 public:
  explicit Worker944(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker945 {
 public:
  explicit Worker945(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker946 {
 public:
  explicit Worker946(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker947 {
 public:
  explicit Worker947(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker948 {
 public:
  explicit Worker948(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 116) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker949 {
 public:
  explicit Worker949(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker950 {
 public:
  explicit Worker950(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker951 {
 public:
  explicit Worker951(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 35) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker952 {
 public:
  explicit Worker952(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 26;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker953 {
 public:
  explicit Worker953(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 47) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker954 {
 public:
  explicit Worker954(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker955 {
 public:
  explicit Worker955(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 66) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker956 {
 public:
  explicit Worker956(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 94) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker957 {
 public:
  explicit Worker957(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker958 {
 public:
  explicit Worker958(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker959 {
 public:
  explicit Worker959(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 127) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker960 {
 public:
  explicit Worker960(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker961 {
 public:
  explicit Worker961(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 116) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker962 {
 public:
  explicit Worker962(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 84;
    for (int x : xs) acc = (acc * 92) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker963 {
 public:
  explicit Worker963(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker964 {
 public:
  explicit Worker964(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker965 {
 public:
  explicit Worker965(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 46) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker966 {
 public:
  explicit Worker966(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 78;
    for (int x : xs) acc = (acc * 121) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker967 {
 public:
  explicit Worker967(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker968 {
 public:
  explicit Worker968(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker969 {
 public:
  explicit Worker969(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker970 {
 public:
  explicit Worker970(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker971 {
 public:
  explicit Worker971(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker972 {
 public:
  explicit Worker972(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker973 {
 public:
  explicit Worker973(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker974 {
 public:
  explicit Worker974(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 46) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker975 {
 public:
  explicit Worker975(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker976 {
 public:
  explicit Worker976(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 127) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker977 {
 public:
  explicit Worker977(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 87) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker978 {
 public:
  explicit Worker978(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker979 {
 public:
  explicit Worker979(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 64;
    for (int x : xs) acc = (acc * 51) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker980 {
 public:
  explicit Worker980(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 5) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker981 {
 public:
  explicit Worker981(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker982 {
 public:
  explicit Worker982(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 85;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker983 {
 public:
  explicit Worker983(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 10) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker984 {
 public:
  explicit Worker984(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 40) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker985 {
 public:
  explicit Worker985(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker986 {
 public:
  explicit Worker986(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 46) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker987 {
 public:
  explicit Worker987(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 94;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker988 {
 public:
  explicit Worker988(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker989 {
 public:
  explicit Worker989(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker990 {
 public:
  explicit Worker990(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 97) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker991 {
 public:
  explicit Worker991(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker992 {
 public:
  explicit Worker992(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker993 {
 public:
  explicit Worker993(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 29;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker994 {
 public:
  explicit Worker994(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 65;
    for (int x : xs) acc = (acc * 43) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker995 {
 public:
  explicit Worker995(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 23) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker996 {
 public:
  explicit Worker996(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker997 {
 public:
  explicit Worker997(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 116) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker998 {
 public:
  explicit Worker998(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker999 {
 public:
  explicit Worker999(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 51) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1000 {
 public:
  explicit Worker1000(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 94;
    for (int x : xs) acc = (acc * 98) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1001 {
 public:
  explicit Worker1001(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 111) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1002 {
 public:
  explicit Worker1002(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 21) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1003 {
 public:
  explicit Worker1003(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1004 {
 public:
  explicit Worker1004(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1005 {
 public:
  explicit Worker1005(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 48) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1006 {
 public:
  explicit Worker1006(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 78) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1007 {
 public:
  explicit Worker1007(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 92) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1008 {
 public:
  explicit Worker1008(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1009 {
 public:
  explicit Worker1009(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1010 {
 public:
  explicit Worker1010(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1011 {
 public:
  explicit Worker1011(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 23) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1012 {
 public:
  explicit Worker1012(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 94;
    for (int x : xs) acc = (acc * 87) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1013 {
 public:
  explicit Worker1013(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1014 {
 public:
  explicit Worker1014(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 38) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1015 {
 public:
  explicit Worker1015(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 45;
    for (int x : xs) acc = (acc * 10) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1016 {
 public:
  explicit Worker1016(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 117) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1017 {
 public:
  explicit Worker1017(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 98) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1018 {
 public:
  explicit Worker1018(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 109) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1019 {
 public:
  explicit Worker1019(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1020 {
 public:
  explicit Worker1020(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1021 {
 public:
  explicit Worker1021(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1022 {
 public:
  explicit Worker1022(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1023 {
 public:
  explicit Worker1023(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 27) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1024 {
 public:
  explicit Worker1024(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 67) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1025 {
 public:
  explicit Worker1025(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1026 {
 public:
  explicit Worker1026(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 71;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1027 {
 public:
  explicit Worker1027(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 23) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1028 {
 public:
  explicit Worker1028(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 21) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1029 {
 public:
  explicit Worker1029(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1030 {
 public:
  explicit Worker1030(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1031 {
 public:
  explicit Worker1031(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1032 {
 public:
  explicit Worker1032(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 71;
    for (int x : xs) acc = (acc * 46) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1033 {
 public:
  explicit Worker1033(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 124) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1034 {
 public:
  explicit Worker1034(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 98) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1035 {
 public:
  explicit Worker1035(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1036 {
 public:
  explicit Worker1036(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1037 {
 public:
  explicit Worker1037(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 91;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1038 {
 public:
  explicit Worker1038(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1039 {
 public:
  explicit Worker1039(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1040 {
 public:
  explicit Worker1040(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1041 {
 public:
  explicit Worker1041(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1042 {
 public:
  explicit Worker1042(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 5) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1043 {
 public:
  explicit Worker1043(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1044 {
 public:
  explicit Worker1044(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 94) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1045 {
 public:
  explicit Worker1045(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 93) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1046 {
 public:
  explicit Worker1046(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1047 {
 public:
  explicit Worker1047(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1048 {
 public:
  explicit Worker1048(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1049 {
 public:
  explicit Worker1049(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1050 {
 public:
  explicit Worker1050(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 127) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1051 {
 public:
  explicit Worker1051(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1052 {
 public:
  explicit Worker1052(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 77) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1053 {
 public:
  explicit Worker1053(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 67) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1054 {
 public:
  explicit Worker1054(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 71) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1055 {
 public:
  explicit Worker1055(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 9) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1056 {
 public:
  explicit Worker1056(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 127) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1057 {
 public:
  explicit Worker1057(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1058 {
 public:
  explicit Worker1058(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1059 {
 public:
  explicit Worker1059(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 43) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1060 {
 public:
  explicit Worker1060(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1061 {
 public:
  explicit Worker1061(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1062 {
 public:
  explicit Worker1062(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1063 {
 public:
  explicit Worker1063(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1064 {
 public:
  explicit Worker1064(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1065 {
 public:
  explicit Worker1065(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1066 {
 public:
  explicit Worker1066(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1067 {
 public:
  explicit Worker1067(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 126) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1068 {
 public:
  explicit Worker1068(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1069 {
 public:
  explicit Worker1069(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 60;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1070 {
 public:
  explicit Worker1070(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1071 {
 public:
  explicit Worker1071(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 72) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1072 {
 public:
  explicit Worker1072(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 70) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1073 {
 public:
  explicit Worker1073(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 38) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1074 {
 public:
  explicit Worker1074(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 27) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1075 {
 public:
  explicit Worker1075(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1076 {
 public:
  explicit Worker1076(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1077 {
 public:
  explicit Worker1077(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 21) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1078 {
 public:
  explicit Worker1078(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 45;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1079 {
 public:
  explicit Worker1079(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1080 {
 public:
  explicit Worker1080(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1081 {
 public:
  explicit Worker1081(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1082 {
 public:
  explicit Worker1082(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1083 {
 public:
  explicit Worker1083(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1084 {
 public:
  explicit Worker1084(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 37) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1085 {
 public:
  explicit Worker1085(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1086 {
 public:
  explicit Worker1086(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 59;
    for (int x : xs) acc = (acc * 104) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1087 {
 public:
  explicit Worker1087(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1088 {
 public:
  explicit Worker1088(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 81) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1089 {
 public:
  explicit Worker1089(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1090 {
 public:
  explicit Worker1090(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 26;
    for (int x : xs) acc = (acc * 23) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1091 {
 public:
  explicit Worker1091(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 93) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1092 {
 public:
  explicit Worker1092(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 112) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1093 {
 public:
  explicit Worker1093(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 64;
    for (int x : xs) acc = (acc * 84) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1094 {
 public:
  explicit Worker1094(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1095 {
 public:
  explicit Worker1095(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 45) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1096 {
 public:
  explicit Worker1096(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1097 {
 public:
  explicit Worker1097(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 105) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1098 {
 public:
  explicit Worker1098(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 75) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1099 {
 public:
  explicit Worker1099(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 84;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1100 {
 public:
  explicit Worker1100(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1101 {
 public:
  explicit Worker1101(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 78;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1102 {
 public:
  explicit Worker1102(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1103 {
 public:
  explicit Worker1103(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 51) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1104 {
 public:
  explicit Worker1104(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1105 {
 public:
  explicit Worker1105(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1106 {
 public:
  explicit Worker1106(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 9) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1107 {
 public:
  explicit Worker1107(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1108 {
 public:
  explicit Worker1108(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 109) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1109 {
 public:
  explicit Worker1109(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 88) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1110 {
 public:
  explicit Worker1110(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 78;
    for (int x : xs) acc = (acc * 105) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1111 {
 public:
  explicit Worker1111(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1112 {
 public:
  explicit Worker1112(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1113 {
 public:
  explicit Worker1113(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 87) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1114 {
 public:
  explicit Worker1114(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 7) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1115 {
 public:
  explicit Worker1115(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1116 {
 public:
  explicit Worker1116(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 94) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1117 {
 public:
  explicit Worker1117(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 91) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1118 {
 public:
  explicit Worker1118(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1119 {
 public:
  explicit Worker1119(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1120 {
 public:
  explicit Worker1120(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1121 {
 public:
  explicit Worker1121(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1122 {
 public:
  explicit Worker1122(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1123 {
 public:
  explicit Worker1123(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 73) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1124 {
 public:
  explicit Worker1124(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 5) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1125 {
 public:
  explicit Worker1125(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1126 {
 public:
  explicit Worker1126(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1127 {
 public:
  explicit Worker1127(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 10) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1128 {
 public:
  explicit Worker1128(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1129 {
 public:
  explicit Worker1129(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1130 {
 public:
  explicit Worker1130(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1131 {
 public:
  explicit Worker1131(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1132 {
 public:
  explicit Worker1132(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1133 {
 public:
  explicit Worker1133(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 92) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1134 {
 public:
  explicit Worker1134(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1135 {
 public:
  explicit Worker1135(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 91) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1136 {
 public:
  explicit Worker1136(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 60;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1137 {
 public:
  explicit Worker1137(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1138 {
 public:
  explicit Worker1138(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 105) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1139 {
 public:
  explicit Worker1139(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1140 {
 public:
  explicit Worker1140(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1141 {
 public:
  explicit Worker1141(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 67) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1142 {
 public:
  explicit Worker1142(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 114) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1143 {
 public:
  explicit Worker1143(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 93) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1144 {
 public:
  explicit Worker1144(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 111) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1145 {
 public:
  explicit Worker1145(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1146 {
 public:
  explicit Worker1146(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 43) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1147 {
 public:
  explicit Worker1147(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 37) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1148 {
 public:
  explicit Worker1148(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1149 {
 public:
  explicit Worker1149(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 127) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1150 {
 public:
  explicit Worker1150(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 84) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1151 {
 public:
  explicit Worker1151(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 29;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1152 {
 public:
  explicit Worker1152(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1153 {
 public:
  explicit Worker1153(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1154 {
 public:
  explicit Worker1154(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 79) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1155 {
 public:
  explicit Worker1155(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1156 {
 public:
  explicit Worker1156(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1157 {
 public:
  explicit Worker1157(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 93) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1158 {
 public:
  explicit Worker1158(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 121) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1159 {
 public:
  explicit Worker1159(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 109) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1160 {
 public:
  explicit Worker1160(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 84;
    for (int x : xs) acc = (acc * 104) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1161 {
 public:
  explicit Worker1161(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1162 {
 public:
  explicit Worker1162(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1163 {
 public:
  explicit Worker1163(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1164 {
 public:
  explicit Worker1164(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 91;
    for (int x : xs) acc = (acc * 29) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1165 {
 public:
  explicit Worker1165(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 84) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1166 {
 public:
  explicit Worker1166(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1167 {
 public:
  explicit Worker1167(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 112) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1168 {
 public:
  explicit Worker1168(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 60) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1169 {
 public:
  explicit Worker1169(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1170 {
 public:
  explicit Worker1170(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 93) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1171 {
 public:
  explicit Worker1171(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 92) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1172 {
 public:
  explicit Worker1172(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 21) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1173 {
 public:
  explicit Worker1173(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 48) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1174 {
 public:
  explicit Worker1174(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 71) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1175 {
 public:
  explicit Worker1175(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1176 {
 public:
  explicit Worker1176(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 107) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1177 {
 public:
  explicit Worker1177(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 71) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1178 {
 public:
  explicit Worker1178(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1179 {
 public:
  explicit Worker1179(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 71;
    for (int x : xs) acc = (acc * 75) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1180 {
 public:
  explicit Worker1180(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 108) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1181 {
 public:
  explicit Worker1181(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 111) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1182 {
 public:
  explicit Worker1182(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 71;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1183 {
 public:
  explicit Worker1183(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 102) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1184 {
 public:
  explicit Worker1184(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1185 {
 public:
  explicit Worker1185(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1186 {
 public:
  explicit Worker1186(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1187 {
 public:
  explicit Worker1187(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1188 {
 public:
  explicit Worker1188(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1189 {
 public:
  explicit Worker1189(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1190 {
 public:
  explicit Worker1190(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1191 {
 public:
  explicit Worker1191(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 75;
    for (int x : xs) acc = (acc * 3) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1192 {
 public:
  explicit Worker1192(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1193 {
 public:
  explicit Worker1193(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 45;
    for (int x : xs) acc = (acc * 100) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1194 {
 public:
  explicit Worker1194(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1195 {
 public:
  explicit Worker1195(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1196 {
 public:
  explicit Worker1196(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 71) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1197 {
 public:
  explicit Worker1197(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 60) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1198 {
 public:
  explicit Worker1198(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 124) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1199 {
 public:
  explicit Worker1199(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 125) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1200 {
 public:
  explicit Worker1200(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1201 {
 public:
  explicit Worker1201(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1202 {
 public:
  explicit Worker1202(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1203 {
 public:
  explicit Worker1203(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 47) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1204 {
 public:
  explicit Worker1204(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1205 {
 public:
  explicit Worker1205(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1206 {
 public:
  explicit Worker1206(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1207 {
 public:
  explicit Worker1207(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 107) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1208 {
 public:
  explicit Worker1208(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 91;
    for (int x : xs) acc = (acc * 67) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1209 {
 public:
  explicit Worker1209(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1210 {
 public:
  explicit Worker1210(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1211 {
 public:
  explicit Worker1211(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1212 {
 public:
  explicit Worker1212(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 77) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1213 {
 public:
  explicit Worker1213(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1214 {
 public:
  explicit Worker1214(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 125) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1215 {
 public:
  explicit Worker1215(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1216 {
 public:
  explicit Worker1216(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1217 {
 public:
  explicit Worker1217(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 64;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1218 {
 public:
  explicit Worker1218(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1219 {
 public:
  explicit Worker1219(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 7) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1220 {
 public:
  explicit Worker1220(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 3) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1221 {
 public:
  explicit Worker1221(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 48) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1222 {
 public:
  explicit Worker1222(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 73) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1223 {
 public:
  explicit Worker1223(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1224 {
 public:
  explicit Worker1224(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1225 {
 public:
  explicit Worker1225(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1226 {
 public:
  explicit Worker1226(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 35) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1227 {
 public:
  explicit Worker1227(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 98) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1228 {
 public:
  explicit Worker1228(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 116) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1229 {
 public:
  explicit Worker1229(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1230 {
 public:
  explicit Worker1230(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 113) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1231 {
 public:
  explicit Worker1231(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1232 {
 public:
  explicit Worker1232(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1233 {
 public:
  explicit Worker1233(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 98) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1234 {
 public:
  explicit Worker1234(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1235 {
 public:
  explicit Worker1235(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 23) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1236 {
 public:
  explicit Worker1236(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1237 {
 public:
  explicit Worker1237(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1238 {
 public:
  explicit Worker1238(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 121) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1239 {
 public:
  explicit Worker1239(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 91;
    for (int x : xs) acc = (acc * 114) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1240 {
 public:
  explicit Worker1240(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 48) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1241 {
 public:
  explicit Worker1241(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 104) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1242 {
 public:
  explicit Worker1242(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 5) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1243 {
 public:
  explicit Worker1243(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1244 {
 public:
  explicit Worker1244(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 71;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1245 {
 public:
  explicit Worker1245(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 87) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1246 {
 public:
  explicit Worker1246(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 60;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1247 {
 public:
  explicit Worker1247(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 22) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1248 {
 public:
  explicit Worker1248(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1249 {
 public:
  explicit Worker1249(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 29;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1250 {
 public:
  explicit Worker1250(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1251 {
 public:
  explicit Worker1251(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1252 {
 public:
  explicit Worker1252(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 109) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1253 {
 public:
  explicit Worker1253(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1254 {
 public:
  explicit Worker1254(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 88) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1255 {
 public:
  explicit Worker1255(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1256 {
 public:
  explicit Worker1256(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 73) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1257 {
 public:
  explicit Worker1257(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1258 {
 public:
  explicit Worker1258(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1259 {
 public:
  explicit Worker1259(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 104) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1260 {
 public:
  explicit Worker1260(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1261 {
 public:
  explicit Worker1261(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 66) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1262 {
 public:
  explicit Worker1262(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1263 {
 public:
  explicit Worker1263(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1264 {
 public:
  explicit Worker1264(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 98) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1265 {
 public:
  explicit Worker1265(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1266 {
 public:
  explicit Worker1266(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1267 {
 public:
  explicit Worker1267(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 60;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1268 {
 public:
  explicit Worker1268(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 20) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1269 {
 public:
  explicit Worker1269(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 85) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1270 {
 public:
  explicit Worker1270(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1271 {
 public:
  explicit Worker1271(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1272 {
 public:
  explicit Worker1272(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1273 {
 public:
  explicit Worker1273(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 116) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1274 {
 public:
  explicit Worker1274(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1275 {
 public:
  explicit Worker1275(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 34) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1276 {
 public:
  explicit Worker1276(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 21) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1277 {
 public:
  explicit Worker1277(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1278 {
 public:
  explicit Worker1278(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 45) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1279 {
 public:
  explicit Worker1279(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 78) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1280 {
 public:
  explicit Worker1280(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 43) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1281 {
 public:
  explicit Worker1281(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1282 {
 public:
  explicit Worker1282(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1283 {
 public:
  explicit Worker1283(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1284 {
 public:
  explicit Worker1284(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 60) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1285 {
 public:
  explicit Worker1285(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 116) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1286 {
 public:
  explicit Worker1286(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1287 {
 public:
  explicit Worker1287(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 43) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1288 {
 public:
  explicit Worker1288(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1289 {
 public:
  explicit Worker1289(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1290 {
 public:
  explicit Worker1290(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1291 {
 public:
  explicit Worker1291(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 29;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1292 {
 public:
  explicit Worker1292(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1293 {
 public:
  explicit Worker1293(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1294 {
 public:
  explicit Worker1294(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1295 {
 public:
  explicit Worker1295(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1296 {
 public:
  explicit Worker1296(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 88) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1297 {
 public:
  explicit Worker1297(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 12) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1298 {
 public:
  explicit Worker1298(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1299 {
 public:
  explicit Worker1299(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 21) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1300 {
 public:
  explicit Worker1300(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 64;
    for (int x : xs) acc = (acc * 92) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1301 {
 public:
  explicit Worker1301(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 65;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1302 {
 public:
  explicit Worker1302(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 64;
    for (int x : xs) acc = (acc * 74) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1303 {
 public:
  explicit Worker1303(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 78;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1304 {
 public:
  explicit Worker1304(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1305 {
 public:
  explicit Worker1305(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 79) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1306 {
 public:
  explicit Worker1306(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1307 {
 public:
  explicit Worker1307(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 46;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1308 {
 public:
  explicit Worker1308(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 79) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1309 {
 public:
  explicit Worker1309(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 88) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1310 {
 public:
  explicit Worker1310(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 59;
    for (int x : xs) acc = (acc * 126) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1311 {
 public:
  explicit Worker1311(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1312 {
 public:
  explicit Worker1312(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 79) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1313 {
 public:
  explicit Worker1313(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 94;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1314 {
 public:
  explicit Worker1314(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1315 {
 public:
  explicit Worker1315(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 78;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1316 {
 public:
  explicit Worker1316(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1317 {
 public:
  explicit Worker1317(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 27) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1318 {
 public:
  explicit Worker1318(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 84;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1319 {
 public:
  explicit Worker1319(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 75;
    for (int x : xs) acc = (acc * 93) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1320 {
 public:
  explicit Worker1320(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1321 {
 public:
  explicit Worker1321(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1322 {
 public:
  explicit Worker1322(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 125) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1323 {
 public:
  explicit Worker1323(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1324 {
 public:
  explicit Worker1324(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1325 {
 public:
  explicit Worker1325(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1326 {
 public:
  explicit Worker1326(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1327 {
 public:
  explicit Worker1327(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1328 {
 public:
  explicit Worker1328(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1329 {
 public:
  explicit Worker1329(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1330 {
 public:
  explicit Worker1330(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1331 {
 public:
  explicit Worker1331(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 35) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1332 {
 public:
  explicit Worker1332(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1333 {
 public:
  explicit Worker1333(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1334 {
 public:
  explicit Worker1334(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1335 {
 public:
  explicit Worker1335(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1336 {
 public:
  explicit Worker1336(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1337 {
 public:
  explicit Worker1337(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 111) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1338 {
 public:
  explicit Worker1338(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1339 {
 public:
  explicit Worker1339(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1340 {
 public:
  explicit Worker1340(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1341 {
 public:
  explicit Worker1341(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1342 {
 public:
  explicit Worker1342(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1343 {
 public:
  explicit Worker1343(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1344 {
 public:
  explicit Worker1344(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1345 {
 public:
  explicit Worker1345(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1346 {
 public:
  explicit Worker1346(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 108) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1347 {
 public:
  explicit Worker1347(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1348 {
 public:
  explicit Worker1348(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 45) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1349 {
 public:
  explicit Worker1349(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 46;
    for (int x : xs) acc = (acc * 38) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1350 {
 public:
  explicit Worker1350(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1351 {
 public:
  explicit Worker1351(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 20) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1352 {
 public:
  explicit Worker1352(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 12) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1353 {
 public:
  explicit Worker1353(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 87) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1354 {
 public:
  explicit Worker1354(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1355 {
 public:
  explicit Worker1355(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1356 {
 public:
  explicit Worker1356(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1357 {
 public:
  explicit Worker1357(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1358 {
 public:
  explicit Worker1358(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1359 {
 public:
  explicit Worker1359(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1360 {
 public:
  explicit Worker1360(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1361 {
 public:
  explicit Worker1361(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1362 {
 public:
  explicit Worker1362(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1363 {
 public:
  explicit Worker1363(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1364 {
 public:
  explicit Worker1364(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1365 {
 public:
  explicit Worker1365(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1366 {
 public:
  explicit Worker1366(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 104) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1367 {
 public:
  explicit Worker1367(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1368 {
 public:
  explicit Worker1368(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1369 {
 public:
  explicit Worker1369(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1370 {
 public:
  explicit Worker1370(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 64;
    for (int x : xs) acc = (acc * 7) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1371 {
 public:
  explicit Worker1371(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1372 {
 public:
  explicit Worker1372(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 79) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1373 {
 public:
  explicit Worker1373(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 88) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1374 {
 public:
  explicit Worker1374(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 29;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1375 {
 public:
  explicit Worker1375(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1376 {
 public:
  explicit Worker1376(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 88) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1377 {
 public:
  explicit Worker1377(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1378 {
 public:
  explicit Worker1378(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1379 {
 public:
  explicit Worker1379(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 29;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1380 {
 public:
  explicit Worker1380(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 102) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1381 {
 public:
  explicit Worker1381(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1382 {
 public:
  explicit Worker1382(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 60) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1383 {
 public:
  explicit Worker1383(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 80;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1384 {
 public:
  explicit Worker1384(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 65;
    for (int x : xs) acc = (acc * 84) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1385 {
 public:
  explicit Worker1385(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 51) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1386 {
 public:
  explicit Worker1386(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 5) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1387 {
 public:
  explicit Worker1387(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 29) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1388 {
 public:
  explicit Worker1388(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 60;
    for (int x : xs) acc = (acc * 67) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1389 {
 public:
  explicit Worker1389(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1390 {
 public:
  explicit Worker1390(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1391 {
 public:
  explicit Worker1391(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 109) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1392 {
 public:
  explicit Worker1392(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 87) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1393 {
 public:
  explicit Worker1393(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 78) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1394 {
 public:
  explicit Worker1394(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1395 {
 public:
  explicit Worker1395(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1396 {
 public:
  explicit Worker1396(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 65;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1397 {
 public:
  explicit Worker1397(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1398 {
 public:
  explicit Worker1398(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 117) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1399 {
 public:
  explicit Worker1399(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1400 {
 public:
  explicit Worker1400(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1401 {
 public:
  explicit Worker1401(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1402 {
 public:
  explicit Worker1402(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 51) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1403 {
 public:
  explicit Worker1403(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1404 {
 public:
  explicit Worker1404(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 74) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1405 {
 public:
  explicit Worker1405(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 9) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1406 {
 public:
  explicit Worker1406(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 107) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1407 {
 public:
  explicit Worker1407(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 100) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1408 {
 public:
  explicit Worker1408(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1409 {
 public:
  explicit Worker1409(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1410 {
 public:
  explicit Worker1410(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 91) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1411 {
 public:
  explicit Worker1411(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1412 {
 public:
  explicit Worker1412(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 46) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1413 {
 public:
  explicit Worker1413(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 79) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1414 {
 public:
  explicit Worker1414(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1415 {
 public:
  explicit Worker1415(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 124) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1416 {
 public:
  explicit Worker1416(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 85) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1417 {
 public:
  explicit Worker1417(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1418 {
 public:
  explicit Worker1418(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1419 {
 public:
  explicit Worker1419(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1420 {
 public:
  explicit Worker1420(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1421 {
 public:
  explicit Worker1421(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 107) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1422 {
 public:
  explicit Worker1422(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1423 {
 public:
  explicit Worker1423(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1424 {
 public:
  explicit Worker1424(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 108) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1425 {
 public:
  explicit Worker1425(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1426 {
 public:
  explicit Worker1426(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 104) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1427 {
 public:
  explicit Worker1427(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 34) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1428 {
 public:
  explicit Worker1428(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 59;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1429 {
 public:
  explicit Worker1429(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 81) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1430 {
 public:
  explicit Worker1430(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1431 {
 public:
  explicit Worker1431(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 20) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1432 {
 public:
  explicit Worker1432(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 108) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1433 {
 public:
  explicit Worker1433(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 45) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1434 {
 public:
  explicit Worker1434(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 94;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1435 {
 public:
  explicit Worker1435(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1436 {
 public:
  explicit Worker1436(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1437 {
 public:
  explicit Worker1437(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 46;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1438 {
 public:
  explicit Worker1438(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 108) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1439 {
 public:
  explicit Worker1439(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1440 {
 public:
  explicit Worker1440(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1441 {
 public:
  explicit Worker1441(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1442 {
 public:
  explicit Worker1442(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 75;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1443 {
 public:
  explicit Worker1443(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1444 {
 public:
  explicit Worker1444(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1445 {
 public:
  explicit Worker1445(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1446 {
 public:
  explicit Worker1446(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 75) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1447 {
 public:
  explicit Worker1447(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 100) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1448 {
 public:
  explicit Worker1448(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1449 {
 public:
  explicit Worker1449(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 20) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1450 {
 public:
  explicit Worker1450(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1451 {
 public:
  explicit Worker1451(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 27) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1452 {
 public:
  explicit Worker1452(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 23) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1453 {
 public:
  explicit Worker1453(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 21) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1454 {
 public:
  explicit Worker1454(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1455 {
 public:
  explicit Worker1455(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 60;
    for (int x : xs) acc = (acc * 38) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1456 {
 public:
  explicit Worker1456(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1457 {
 public:
  explicit Worker1457(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 59;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1458 {
 public:
  explicit Worker1458(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1459 {
 public:
  explicit Worker1459(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 60) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1460 {
 public:
  explicit Worker1460(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1461 {
 public:
  explicit Worker1461(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1462 {
 public:
  explicit Worker1462(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1463 {
 public:
  explicit Worker1463(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 75;
    for (int x : xs) acc = (acc * 10) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1464 {
 public:
  explicit Worker1464(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 10) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1465 {
 public:
  explicit Worker1465(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 111) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1466 {
 public:
  explicit Worker1466(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 73) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1467 {
 public:
  explicit Worker1467(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1468 {
 public:
  explicit Worker1468(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 107) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1469 {
 public:
  explicit Worker1469(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1470 {
 public:
  explicit Worker1470(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 87) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1471 {
 public:
  explicit Worker1471(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 125) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1472 {
 public:
  explicit Worker1472(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1473 {
 public:
  explicit Worker1473(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 26;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1474 {
 public:
  explicit Worker1474(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1475 {
 public:
  explicit Worker1475(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1476 {
 public:
  explicit Worker1476(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 7) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1477 {
 public:
  explicit Worker1477(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1478 {
 public:
  explicit Worker1478(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 78) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1479 {
 public:
  explicit Worker1479(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 7) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1480 {
 public:
  explicit Worker1480(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1481 {
 public:
  explicit Worker1481(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 70) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1482 {
 public:
  explicit Worker1482(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1483 {
 public:
  explicit Worker1483(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 81) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1484 {
 public:
  explicit Worker1484(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 47) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1485 {
 public:
  explicit Worker1485(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 10) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1486 {
 public:
  explicit Worker1486(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1487 {
 public:
  explicit Worker1487(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1488 {
 public:
  explicit Worker1488(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 64;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1489 {
 public:
  explicit Worker1489(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 124) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1490 {
 public:
  explicit Worker1490(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 67) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1491 {
 public:
  explicit Worker1491(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1492 {
 public:
  explicit Worker1492(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1493 {
 public:
  explicit Worker1493(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 74) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1494 {
 public:
  explicit Worker1494(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1495 {
 public:
  explicit Worker1495(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 37) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1496 {
 public:
  explicit Worker1496(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1497 {
 public:
  explicit Worker1497(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 100) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1498 {
 public:
  explicit Worker1498(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1499 {
 public:
  explicit Worker1499(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1500 {
 public:
  explicit Worker1500(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 85) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1501 {
 public:
  explicit Worker1501(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 121) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1502 {
 public:
  explicit Worker1502(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1503 {
 public:
  explicit Worker1503(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1504 {
 public:
  explicit Worker1504(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 29) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1505 {
 public:
  explicit Worker1505(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 35) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1506 {
 public:
  explicit Worker1506(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1507 {
 public:
  explicit Worker1507(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1508 {
 public:
  explicit Worker1508(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 105) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1509 {
 public:
  explicit Worker1509(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1510 {
 public:
  explicit Worker1510(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1511 {
 public:
  explicit Worker1511(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 65;
    for (int x : xs) acc = (acc * 100) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1512 {
 public:
  explicit Worker1512(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 91;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1513 {
 public:
  explicit Worker1513(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1514 {
 public:
  explicit Worker1514(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 12) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1515 {
 public:
  explicit Worker1515(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1516 {
 public:
  explicit Worker1516(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1517 {
 public:
  explicit Worker1517(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1518 {
 public:
  explicit Worker1518(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1519 {
 public:
  explicit Worker1519(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 108) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1520 {
 public:
  explicit Worker1520(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1521 {
 public:
  explicit Worker1521(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 125) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1522 {
 public:
  explicit Worker1522(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 27) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1523 {
 public:
  explicit Worker1523(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1524 {
 public:
  explicit Worker1524(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1525 {
 public:
  explicit Worker1525(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 3) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1526 {
 public:
  explicit Worker1526(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1527 {
 public:
  explicit Worker1527(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 22) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1528 {
 public:
  explicit Worker1528(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 77) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1529 {
 public:
  explicit Worker1529(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1530 {
 public:
  explicit Worker1530(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1531 {
 public:
  explicit Worker1531(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1532 {
 public:
  explicit Worker1532(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1533 {
 public:
  explicit Worker1533(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1534 {
 public:
  explicit Worker1534(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 93) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1535 {
 public:
  explicit Worker1535(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1536 {
 public:
  explicit Worker1536(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 97) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1537 {
 public:
  explicit Worker1537(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1538 {
 public:
  explicit Worker1538(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1539 {
 public:
  explicit Worker1539(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 26;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1540 {
 public:
  explicit Worker1540(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1541 {
 public:
  explicit Worker1541(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1542 {
 public:
  explicit Worker1542(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1543 {
 public:
  explicit Worker1543(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 80;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1544 {
 public:
  explicit Worker1544(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1545 {
 public:
  explicit Worker1545(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 37) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1546 {
 public:
  explicit Worker1546(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1547 {
 public:
  explicit Worker1547(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1548 {
 public:
  explicit Worker1548(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 79) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1549 {
 public:
  explicit Worker1549(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1550 {
 public:
  explicit Worker1550(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1551 {
 public:
  explicit Worker1551(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 124) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1552 {
 public:
  explicit Worker1552(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 66) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1553 {
 public:
  explicit Worker1553(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1554 {
 public:
  explicit Worker1554(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 94) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1555 {
 public:
  explicit Worker1555(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1556 {
 public:
  explicit Worker1556(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 12;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1557 {
 public:
  explicit Worker1557(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1558 {
 public:
  explicit Worker1558(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1559 {
 public:
  explicit Worker1559(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 34) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1560 {
 public:
  explicit Worker1560(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1561 {
 public:
  explicit Worker1561(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1562 {
 public:
  explicit Worker1562(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1563 {
 public:
  explicit Worker1563(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 29;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1564 {
 public:
  explicit Worker1564(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1565 {
 public:
  explicit Worker1565(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1566 {
 public:
  explicit Worker1566(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 80;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1567 {
 public:
  explicit Worker1567(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 75) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1568 {
 public:
  explicit Worker1568(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1569 {
 public:
  explicit Worker1569(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1570 {
 public:
  explicit Worker1570(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 84;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1571 {
 public:
  explicit Worker1571(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 85;
    for (int x : xs) acc = (acc * 20) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1572 {
 public:
  explicit Worker1572(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1573 {
 public:
  explicit Worker1573(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1574 {
 public:
  explicit Worker1574(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1575 {
 public:
  explicit Worker1575(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 22) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1576 {
 public:
  explicit Worker1576(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1577 {
 public:
  explicit Worker1577(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 84;
    for (int x : xs) acc = (acc * 73) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1578 {
 public:
  explicit Worker1578(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1579 {
 public:
  explicit Worker1579(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 104) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1580 {
 public:
  explicit Worker1580(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 91;
    for (int x : xs) acc = (acc * 47) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1581 {
 public:
  explicit Worker1581(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 27) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1582 {
 public:
  explicit Worker1582(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 45;
    for (int x : xs) acc = (acc * 85) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1583 {
 public:
  explicit Worker1583(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 102) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1584 {
 public:
  explicit Worker1584(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1585 {
 public:
  explicit Worker1585(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 88) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1586 {
 public:
  explicit Worker1586(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 5) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1587 {
 public:
  explicit Worker1587(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1588 {
 public:
  explicit Worker1588(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1589 {
 public:
  explicit Worker1589(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 14) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1590 {
 public:
  explicit Worker1590(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 27) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1591 {
 public:
  explicit Worker1591(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1592 {
 public:
  explicit Worker1592(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 60) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1593 {
 public:
  explicit Worker1593(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 78) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1594 {
 public:
  explicit Worker1594(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1595 {
 public:
  explicit Worker1595(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 48) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1596 {
 public:
  explicit Worker1596(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 67) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1597 {
 public:
  explicit Worker1597(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 45) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1598 {
 public:
  explicit Worker1598(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1599 {
 public:
  explicit Worker1599(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1600 {
 public:
  explicit Worker1600(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 60) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1601 {
 public:
  explicit Worker1601(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1602 {
 public:
  explicit Worker1602(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1603 {
 public:
  explicit Worker1603(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1604 {
 public:
  explicit Worker1604(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1605 {
 public:
  explicit Worker1605(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 75) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1606 {
 public:
  explicit Worker1606(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1607 {
 public:
  explicit Worker1607(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1608 {
 public:
  explicit Worker1608(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1609 {
 public:
  explicit Worker1609(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1610 {
 public:
  explicit Worker1610(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 47) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1611 {
 public:
  explicit Worker1611(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1612 {
 public:
  explicit Worker1612(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 51) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1613 {
 public:
  explicit Worker1613(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1614 {
 public:
  explicit Worker1614(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1615 {
 public:
  explicit Worker1615(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1616 {
 public:
  explicit Worker1616(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1617 {
 public:
  explicit Worker1617(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1618 {
 public:
  explicit Worker1618(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1619 {
 public:
  explicit Worker1619(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1620 {
 public:
  explicit Worker1620(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 46) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1621 {
 public:
  explicit Worker1621(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1622 {
 public:
  explicit Worker1622(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 12;
    for (int x : xs) acc = (acc * 125) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1623 {
 public:
  explicit Worker1623(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1624 {
 public:
  explicit Worker1624(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 118) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1625 {
 public:
  explicit Worker1625(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1626 {
 public:
  explicit Worker1626(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1627 {
 public:
  explicit Worker1627(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 124) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1628 {
 public:
  explicit Worker1628(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1629 {
 public:
  explicit Worker1629(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 9) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1630 {
 public:
  explicit Worker1630(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1631 {
 public:
  explicit Worker1631(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 84;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1632 {
 public:
  explicit Worker1632(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 38) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1633 {
 public:
  explicit Worker1633(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 102) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1634 {
 public:
  explicit Worker1634(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1635 {
 public:
  explicit Worker1635(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1636 {
 public:
  explicit Worker1636(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1637 {
 public:
  explicit Worker1637(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 59;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1638 {
 public:
  explicit Worker1638(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1639 {
 public:
  explicit Worker1639(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 26;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1640 {
 public:
  explicit Worker1640(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1641 {
 public:
  explicit Worker1641(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 9) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1642 {
 public:
  explicit Worker1642(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1643 {
 public:
  explicit Worker1643(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1644 {
 public:
  explicit Worker1644(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1645 {
 public:
  explicit Worker1645(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1646 {
 public:
  explicit Worker1646(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 54) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1647 {
 public:
  explicit Worker1647(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 60;
    for (int x : xs) acc = (acc * 72) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1648 {
 public:
  explicit Worker1648(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1649 {
 public:
  explicit Worker1649(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1650 {
 public:
  explicit Worker1650(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1651 {
 public:
  explicit Worker1651(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1652 {
 public:
  explicit Worker1652(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1653 {
 public:
  explicit Worker1653(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1654 {
 public:
  explicit Worker1654(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1655 {
 public:
  explicit Worker1655(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 73) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1656 {
 public:
  explicit Worker1656(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 38) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1657 {
 public:
  explicit Worker1657(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 85) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1658 {
 public:
  explicit Worker1658(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1659 {
 public:
  explicit Worker1659(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 23) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1660 {
 public:
  explicit Worker1660(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 67) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1661 {
 public:
  explicit Worker1661(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 71) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1662 {
 public:
  explicit Worker1662(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1663 {
 public:
  explicit Worker1663(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 7) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1664 {
 public:
  explicit Worker1664(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1665 {
 public:
  explicit Worker1665(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1666 {
 public:
  explicit Worker1666(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1667 {
 public:
  explicit Worker1667(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1668 {
 public:
  explicit Worker1668(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 33;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1669 {
 public:
  explicit Worker1669(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 97) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1670 {
 public:
  explicit Worker1670(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1671 {
 public:
  explicit Worker1671(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 67) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1672 {
 public:
  explicit Worker1672(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1673 {
 public:
  explicit Worker1673(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1674 {
 public:
  explicit Worker1674(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 21) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1675 {
 public:
  explicit Worker1675(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1676 {
 public:
  explicit Worker1676(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1677 {
 public:
  explicit Worker1677(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 124) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1678 {
 public:
  explicit Worker1678(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1679 {
 public:
  explicit Worker1679(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1680 {
 public:
  explicit Worker1680(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1681 {
 public:
  explicit Worker1681(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 105) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1682 {
 public:
  explicit Worker1682(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1683 {
 public:
  explicit Worker1683(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 96;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1684 {
 public:
  explicit Worker1684(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1685 {
 public:
  explicit Worker1685(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1686 {
 public:
  explicit Worker1686(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1687 {
 public:
  explicit Worker1687(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 37) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1688 {
 public:
  explicit Worker1688(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 80;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1689 {
 public:
  explicit Worker1689(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1690 {
 public:
  explicit Worker1690(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 75;
    for (int x : xs) acc = (acc * 94) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1691 {
 public:
  explicit Worker1691(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 114) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1692 {
 public:
  explicit Worker1692(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 126) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1693 {
 public:
  explicit Worker1693(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1694 {
 public:
  explicit Worker1694(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1695 {
 public:
  explicit Worker1695(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1696 {
 public:
  explicit Worker1696(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1697 {
 public:
  explicit Worker1697(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1698 {
 public:
  explicit Worker1698(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1699 {
 public:
  explicit Worker1699(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1700 {
 public:
  explicit Worker1700(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 72) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1701 {
 public:
  explicit Worker1701(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1702 {
 public:
  explicit Worker1702(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 12;
    for (int x : xs) acc = (acc * 66) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1703 {
 public:
  explicit Worker1703(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1704 {
 public:
  explicit Worker1704(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1705 {
 public:
  explicit Worker1705(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1706 {
 public:
  explicit Worker1706(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1707 {
 public:
  explicit Worker1707(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 88) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1708 {
 public:
  explicit Worker1708(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 92) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1709 {
 public:
  explicit Worker1709(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 109) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1710 {
 public:
  explicit Worker1710(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 88) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1711 {
 public:
  explicit Worker1711(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 12;
    for (int x : xs) acc = (acc * 70) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1712 {
 public:
  explicit Worker1712(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1713 {
 public:
  explicit Worker1713(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1714 {
 public:
  explicit Worker1714(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 87) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1715 {
 public:
  explicit Worker1715(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1716 {
 public:
  explicit Worker1716(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 26;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1717 {
 public:
  explicit Worker1717(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 111) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1718 {
 public:
  explicit Worker1718(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 7) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1719 {
 public:
  explicit Worker1719(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 21) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1720 {
 public:
  explicit Worker1720(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 19) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1721 {
 public:
  explicit Worker1721(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 26;
    for (int x : xs) acc = (acc * 118) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1722 {
 public:
  explicit Worker1722(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1723 {
 public:
  explicit Worker1723(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 114) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1724 {
 public:
  explicit Worker1724(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1725 {
 public:
  explicit Worker1725(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1726 {
 public:
  explicit Worker1726(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1727 {
 public:
  explicit Worker1727(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 87) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1728 {
 public:
  explicit Worker1728(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1729 {
 public:
  explicit Worker1729(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 77) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1730 {
 public:
  explicit Worker1730(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1731 {
 public:
  explicit Worker1731(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1732 {
 public:
  explicit Worker1732(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1733 {
 public:
  explicit Worker1733(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1734 {
 public:
  explicit Worker1734(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1735 {
 public:
  explicit Worker1735(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1736 {
 public:
  explicit Worker1736(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 94;
    for (int x : xs) acc = (acc * 81) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1737 {
 public:
  explicit Worker1737(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1738 {
 public:
  explicit Worker1738(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1739 {
 public:
  explicit Worker1739(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 63) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1740 {
 public:
  explicit Worker1740(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1741 {
 public:
  explicit Worker1741(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1742 {
 public:
  explicit Worker1742(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1743 {
 public:
  explicit Worker1743(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1744 {
 public:
  explicit Worker1744(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 20) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1745 {
 public:
  explicit Worker1745(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 126) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1746 {
 public:
  explicit Worker1746(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1747 {
 public:
  explicit Worker1747(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 125) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1748 {
 public:
  explicit Worker1748(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 92;
    for (int x : xs) acc = (acc * 98) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1749 {
 public:
  explicit Worker1749(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 59;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1750 {
 public:
  explicit Worker1750(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1751 {
 public:
  explicit Worker1751(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 74) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1752 {
 public:
  explicit Worker1752(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1753 {
 public:
  explicit Worker1753(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1754 {
 public:
  explicit Worker1754(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 20) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1755 {
 public:
  explicit Worker1755(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1756 {
 public:
  explicit Worker1756(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 27) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1757 {
 public:
  explicit Worker1757(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1758 {
 public:
  explicit Worker1758(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1759 {
 public:
  explicit Worker1759(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1760 {
 public:
  explicit Worker1760(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 107) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1761 {
 public:
  explicit Worker1761(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 47) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1762 {
 public:
  explicit Worker1762(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1763 {
 public:
  explicit Worker1763(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1764 {
 public:
  explicit Worker1764(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1765 {
 public:
  explicit Worker1765(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1766 {
 public:
  explicit Worker1766(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1767 {
 public:
  explicit Worker1767(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1768 {
 public:
  explicit Worker1768(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1769 {
 public:
  explicit Worker1769(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 64;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1770 {
 public:
  explicit Worker1770(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 45;
    for (int x : xs) acc = (acc * 66) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1771 {
 public:
  explicit Worker1771(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1772 {
 public:
  explicit Worker1772(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 80;
    for (int x : xs) acc = (acc * 85) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1773 {
 public:
  explicit Worker1773(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1774 {
 public:
  explicit Worker1774(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 110) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1775 {
 public:
  explicit Worker1775(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 62) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1776 {
 public:
  explicit Worker1776(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 3;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1777 {
 public:
  explicit Worker1777(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1778 {
 public:
  explicit Worker1778(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 71) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1779 {
 public:
  explicit Worker1779(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 98) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1780 {
 public:
  explicit Worker1780(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 52;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1781 {
 public:
  explicit Worker1781(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1782 {
 public:
  explicit Worker1782(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 88;
    for (int x : xs) acc = (acc * 108) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1783 {
 public:
  explicit Worker1783(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 84;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1784 {
 public:
  explicit Worker1784(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 81) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1785 {
 public:
  explicit Worker1785(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1786 {
 public:
  explicit Worker1786(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 81) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1787 {
 public:
  explicit Worker1787(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1788 {
 public:
  explicit Worker1788(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 46;
    for (int x : xs) acc = (acc * 47) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1789 {
 public:
  explicit Worker1789(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1790 {
 public:
  explicit Worker1790(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 60;
    for (int x : xs) acc = (acc * 89) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1791 {
 public:
  explicit Worker1791(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 57) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1792 {
 public:
  explicit Worker1792(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 66) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1793 {
 public:
  explicit Worker1793(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1794 {
 public:
  explicit Worker1794(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 9) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1795 {
 public:
  explicit Worker1795(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 21) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1796 {
 public:
  explicit Worker1796(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 65;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1797 {
 public:
  explicit Worker1797(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 105) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1798 {
 public:
  explicit Worker1798(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1799 {
 public:
  explicit Worker1799(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1800 {
 public:
  explicit Worker1800(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 46;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1801 {
 public:
  explicit Worker1801(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 75;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1802 {
 public:
  explicit Worker1802(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 126) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1803 {
 public:
  explicit Worker1803(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1804 {
 public:
  explicit Worker1804(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1805 {
 public:
  explicit Worker1805(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 71;
    for (int x : xs) acc = (acc * 95) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1806 {
 public:
  explicit Worker1806(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 85;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1807 {
 public:
  explicit Worker1807(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 113) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1808 {
 public:
  explicit Worker1808(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1809 {
 public:
  explicit Worker1809(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1810 {
 public:
  explicit Worker1810(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 94) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1811 {
 public:
  explicit Worker1811(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1812 {
 public:
  explicit Worker1812(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 113) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1813 {
 public:
  explicit Worker1813(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 22) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1814 {
 public:
  explicit Worker1814(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1815 {
 public:
  explicit Worker1815(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1816 {
 public:
  explicit Worker1816(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 71;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1817 {
 public:
  explicit Worker1817(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1818 {
 public:
  explicit Worker1818(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 45) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1819 {
 public:
  explicit Worker1819(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1820 {
 public:
  explicit Worker1820(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1821 {
 public:
  explicit Worker1821(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1822 {
 public:
  explicit Worker1822(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1823 {
 public:
  explicit Worker1823(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1824 {
 public:
  explicit Worker1824(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 29;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1825 {
 public:
  explicit Worker1825(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1826 {
 public:
  explicit Worker1826(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 37) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1827 {
 public:
  explicit Worker1827(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 73) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1828 {
 public:
  explicit Worker1828(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1829 {
 public:
  explicit Worker1829(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1830 {
 public:
  explicit Worker1830(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1831 {
 public:
  explicit Worker1831(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 45) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1832 {
 public:
  explicit Worker1832(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1833 {
 public:
  explicit Worker1833(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 47) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1834 {
 public:
  explicit Worker1834(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 47) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1835 {
 public:
  explicit Worker1835(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1836 {
 public:
  explicit Worker1836(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1837 {
 public:
  explicit Worker1837(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 16) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1838 {
 public:
  explicit Worker1838(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 116) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1839 {
 public:
  explicit Worker1839(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 109) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1840 {
 public:
  explicit Worker1840(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 120) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1841 {
 public:
  explicit Worker1841(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1842 {
 public:
  explicit Worker1842(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 45;
    for (int x : xs) acc = (acc * 107) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1843 {
 public:
  explicit Worker1843(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1844 {
 public:
  explicit Worker1844(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 54;
    for (int x : xs) acc = (acc * 94) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1845 {
 public:
  explicit Worker1845(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 40;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1846 {
 public:
  explicit Worker1846(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 58) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1847 {
 public:
  explicit Worker1847(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 12;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1848 {
 public:
  explicit Worker1848(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1849 {
 public:
  explicit Worker1849(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 78) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1850 {
 public:
  explicit Worker1850(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 125) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1851 {
 public:
  explicit Worker1851(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 127) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1852 {
 public:
  explicit Worker1852(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 37;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1853 {
 public:
  explicit Worker1853(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1854 {
 public:
  explicit Worker1854(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1855 {
 public:
  explicit Worker1855(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 21) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1856 {
 public:
  explicit Worker1856(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 91;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1857 {
 public:
  explicit Worker1857(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1858 {
 public:
  explicit Worker1858(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 111) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1859 {
 public:
  explicit Worker1859(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1860 {
 public:
  explicit Worker1860(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1861 {
 public:
  explicit Worker1861(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 125) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1862 {
 public:
  explicit Worker1862(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 105) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1863 {
 public:
  explicit Worker1863(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 79) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1864 {
 public:
  explicit Worker1864(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1865 {
 public:
  explicit Worker1865(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1866 {
 public:
  explicit Worker1866(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1867 {
 public:
  explicit Worker1867(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1868 {
 public:
  explicit Worker1868(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 38;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1869 {
 public:
  explicit Worker1869(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 5;
    for (int x : xs) acc = (acc * 85) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1870 {
 public:
  explicit Worker1870(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 129) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1871 {
 public:
  explicit Worker1871(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1872 {
 public:
  explicit Worker1872(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1873 {
 public:
  explicit Worker1873(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 88) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1874 {
 public:
  explicit Worker1874(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 51;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1875 {
 public:
  explicit Worker1875(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 102) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1876 {
 public:
  explicit Worker1876(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1877 {
 public:
  explicit Worker1877(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1878 {
 public:
  explicit Worker1878(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1879 {
 public:
  explicit Worker1879(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 11;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1880 {
 public:
  explicit Worker1880(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 38) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1881 {
 public:
  explicit Worker1881(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 61) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1882 {
 public:
  explicit Worker1882(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 114) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1883 {
 public:
  explicit Worker1883(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1884 {
 public:
  explicit Worker1884(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1885 {
 public:
  explicit Worker1885(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1886 {
 public:
  explicit Worker1886(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1887 {
 public:
  explicit Worker1887(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1888 {
 public:
  explicit Worker1888(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 78;
    for (int x : xs) acc = (acc * 35) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1889 {
 public:
  explicit Worker1889(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1890 {
 public:
  explicit Worker1890(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 34) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1891 {
 public:
  explicit Worker1891(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 4;
    for (int x : xs) acc = (acc * 86) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1892 {
 public:
  explicit Worker1892(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 121) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1893 {
 public:
  explicit Worker1893(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 15;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1894 {
 public:
  explicit Worker1894(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 94) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1895 {
 public:
  explicit Worker1895(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 48;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1896 {
 public:
  explicit Worker1896(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 103) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1897 {
 public:
  explicit Worker1897(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 117) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1898 {
 public:
  explicit Worker1898(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 9) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1899 {
 public:
  explicit Worker1899(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1900 {
 public:
  explicit Worker1900(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 46;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1901 {
 public:
  explicit Worker1901(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1902 {
 public:
  explicit Worker1902(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1903 {
 public:
  explicit Worker1903(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1904 {
 public:
  explicit Worker1904(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 104) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1905 {
 public:
  explicit Worker1905(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1906 {
 public:
  explicit Worker1906(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 68;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1907 {
 public:
  explicit Worker1907(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1908 {
 public:
  explicit Worker1908(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1909 {
 public:
  explicit Worker1909(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 91;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1910 {
 public:
  explicit Worker1910(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 51) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1911 {
 public:
  explicit Worker1911(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 107) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1912 {
 public:
  explicit Worker1912(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1913 {
 public:
  explicit Worker1913(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 51) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1914 {
 public:
  explicit Worker1914(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 29;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1915 {
 public:
  explicit Worker1915(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 70) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1916 {
 public:
  explicit Worker1916(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1917 {
 public:
  explicit Worker1917(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 12;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1918 {
 public:
  explicit Worker1918(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 112) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1919 {
 public:
  explicit Worker1919(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 75;
    for (int x : xs) acc = (acc * 109) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1920 {
 public:
  explicit Worker1920(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 112) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1921 {
 public:
  explicit Worker1921(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 37) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1922 {
 public:
  explicit Worker1922(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 73) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1923 {
 public:
  explicit Worker1923(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 114) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1924 {
 public:
  explicit Worker1924(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 94;
    for (int x : xs) acc = (acc * 68) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1925 {
 public:
  explicit Worker1925(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 117) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1926 {
 public:
  explicit Worker1926(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 12) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1927 {
 public:
  explicit Worker1927(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 94;
    for (int x : xs) acc = (acc * 79) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1928 {
 public:
  explicit Worker1928(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1929 {
 public:
  explicit Worker1929(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1930 {
 public:
  explicit Worker1930(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 112) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1931 {
 public:
  explicit Worker1931(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 60;
    for (int x : xs) acc = (acc * 84) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1932 {
 public:
  explicit Worker1932(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 89;
    for (int x : xs) acc = (acc * 124) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1933 {
 public:
  explicit Worker1933(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 7;
    for (int x : xs) acc = (acc * 40) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1934 {
 public:
  explicit Worker1934(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1935 {
 public:
  explicit Worker1935(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 99) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1936 {
 public:
  explicit Worker1936(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1937 {
 public:
  explicit Worker1937(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 9) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1938 {
 public:
  explicit Worker1938(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 12;
    for (int x : xs) acc = (acc * 11) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1939 {
 public:
  explicit Worker1939(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1940 {
 public:
  explicit Worker1940(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 95;
    for (int x : xs) acc = (acc * 77) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1941 {
 public:
  explicit Worker1941(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1942 {
 public:
  explicit Worker1942(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 84;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1943 {
 public:
  explicit Worker1943(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1944 {
 public:
  explicit Worker1944(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 44) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1945 {
 public:
  explicit Worker1945(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 62;
    for (int x : xs) acc = (acc * 60) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1946 {
 public:
  explicit Worker1946(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1947 {
 public:
  explicit Worker1947(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 80) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1948 {
 public:
  explicit Worker1948(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1949 {
 public:
  explicit Worker1949(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 81;
    for (int x : xs) acc = (acc * 116) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1950 {
 public:
  explicit Worker1950(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 109) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1951 {
 public:
  explicit Worker1951(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 18) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1952 {
 public:
  explicit Worker1952(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 31;
    for (int x : xs) acc = (acc * 121) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1953 {
 public:
  explicit Worker1953(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 69;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1954 {
 public:
  explicit Worker1954(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1955 {
 public:
  explicit Worker1955(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 106) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1956 {
 public:
  explicit Worker1956(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 123) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1957 {
 public:
  explicit Worker1957(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 65;
    for (int x : xs) acc = (acc * 71) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1958 {
 public:
  explicit Worker1958(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1959 {
 public:
  explicit Worker1959(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 90) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1960 {
 public:
  explicit Worker1960(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 100) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1961 {
 public:
  explicit Worker1961(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1962 {
 public:
  explicit Worker1962(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1963 {
 public:
  explicit Worker1963(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 83) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1964 {
 public:
  explicit Worker1964(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 42;
    for (int x : xs) acc = (acc * 55) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1965 {
 public:
  explicit Worker1965(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 17;
    for (int x : xs) acc = (acc * 75) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker1966 {
 public:
  explicit Worker1966(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 97) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1967 {
 public:
  explicit Worker1967(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1968 {
 public:
  explicit Worker1968(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 47) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1969 {
 public:
  explicit Worker1969(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 26;
    for (int x : xs) acc = (acc * 51) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1970 {
 public:
  explicit Worker1970(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 39;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1971 {
 public:
  explicit Worker1971(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 5) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1972 {
 public:
  explicit Worker1972(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 72;
    for (int x : xs) acc = (acc * 21) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1973 {
 public:
  explicit Worker1973(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 33) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1974 {
 public:
  explicit Worker1974(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 31) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1975 {
 public:
  explicit Worker1975(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1976 {
 public:
  explicit Worker1976(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 36;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1977 {
 public:
  explicit Worker1977(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 74) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1978 {
 public:
  explicit Worker1978(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 5) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1979 {
 public:
  explicit Worker1979(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 55;
    for (int x : xs) acc = (acc * 92) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1980 {
 public:
  explicit Worker1980(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 25;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker1981 {
 public:
  explicit Worker1981(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 60) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1982 {
 public:
  explicit Worker1982(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 34) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker1983 {
 public:
  explicit Worker1983(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 76;
    for (int x : xs) acc = (acc * 85) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1984 {
 public:
  explicit Worker1984(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 9) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1985 {
 public:
  explicit Worker1985(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 78;
    for (int x : xs) acc = (acc * 111) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1986 {
 public:
  explicit Worker1986(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 72) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1987 {
 public:
  explicit Worker1987(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 112) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1988 {
 public:
  explicit Worker1988(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1989 {
 public:
  explicit Worker1989(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 112) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1990 {
 public:
  explicit Worker1990(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 85;
    for (int x : xs) acc = (acc * 101) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1991 {
 public:
  explicit Worker1991(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 49;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker1992 {
 public:
  explicit Worker1992(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 19;
    for (int x : xs) acc = (acc * 94) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker1993 {
 public:
  explicit Worker1993(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 34;
    for (int x : xs) acc = (acc * 39) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1994 {
 public:
  explicit Worker1994(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 22;
    for (int x : xs) acc = (acc * 41) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1995 {
 public:
  explicit Worker1995(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 16;
    for (int x : xs) acc = (acc * 34) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker1996 {
 public:
  explicit Worker1996(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker1997 {
 public:
  explicit Worker1997(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 73;
    for (int x : xs) acc = (acc * 130) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker1998 {
 public:
  explicit Worker1998(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 61;
    for (int x : xs) acc = (acc * 6) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker1999 {
 public:
  explicit Worker1999(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 111) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker2000 {
 public:
  explicit Worker2000(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 4) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker2001 {
 public:
  explicit Worker2001(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker2002 {
 public:
  explicit Worker2002(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 63;
    for (int x : xs) acc = (acc * 102) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker2003 {
 public:
  explicit Worker2003(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 124) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker2004 {
 public:
  explicit Worker2004(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 15) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker2005 {
 public:
  explicit Worker2005(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker2006 {
 public:
  explicit Worker2006(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 79;
    for (int x : xs) acc = (acc * 49) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker2007 {
 public:
  explicit Worker2007(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 69) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker2008 {
 public:
  explicit Worker2008(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 25) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker2009 {
 public:
  explicit Worker2009(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 85;
    for (int x : xs) acc = (acc * 23) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker2010 {
 public:
  explicit Worker2010(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 41;
    for (int x : xs) acc = (acc * 21) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker2011 {
 public:
  explicit Worker2011(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 59;
    for (int x : xs) acc = (acc * 65) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker2012 {
 public:
  explicit Worker2012(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 24;
    for (int x : xs) acc = (acc * 81) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker2013 {
 public:
  explicit Worker2013(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 30) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker2014 {
 public:
  explicit Worker2014(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 56;
    for (int x : xs) acc = (acc * 45) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker2015 {
 public:
  explicit Worker2015(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 65;
    for (int x : xs) acc = (acc * 34) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker2016 {
 public:
  explicit Worker2016(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 17) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker2017 {
 public:
  explicit Worker2017(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 13) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker2018 {
 public:
  explicit Worker2018(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 8;
    for (int x : xs) acc = (acc * 29) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker2019 {
 public:
  explicit Worker2019(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 97;
    for (int x : xs) acc = (acc * 51) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker2020 {
 public:
  explicit Worker2020(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 53;
    for (int x : xs) acc = (acc * 46) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker2021 {
 public:
  explicit Worker2021(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 87;
    for (int x : xs) acc = (acc * 56) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker2022 {
 public:
  explicit Worker2022(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 35;
    for (int x : xs) acc = (acc * 119) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker2023 {
 public:
  explicit Worker2023(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 32;
    for (int x : xs) acc = (acc * 122) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker2024 {
 public:
  explicit Worker2024(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 91;
    for (int x : xs) acc = (acc * 60) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker2025 {
 public:
  explicit Worker2025(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 14;
    for (int x : xs) acc = (acc * 53) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker2026 {
 public:
  explicit Worker2026(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 13;
    for (int x : xs) acc = (acc * 76) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker2027 {
 public:
  explicit Worker2027(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 44;
    for (int x : xs) acc = (acc * 66) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker2028 {
 public:
  explicit Worker2028(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 87) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker2029 {
 public:
  explicit Worker2029(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 6;
    for (int x : xs) acc = (acc * 105) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker2030 {
 public:
  explicit Worker2030(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 90;
    for (int x : xs) acc = (acc * 113) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker2031 {
 public:
  explicit Worker2031(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 21;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker2032 {
 public:
  explicit Worker2032(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 9;
    for (int x : xs) acc = (acc * 52) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker2033 {
 public:
  explicit Worker2033(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 82;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker2034 {
 public:
  explicit Worker2034(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 128) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker2035 {
 public:
  explicit Worker2035(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 26;
    for (int x : xs) acc = (acc * 28) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker2036 {
 public:
  explicit Worker2036(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 74;
    for (int x : xs) acc = (acc * 117) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker2037 {
 public:
  explicit Worker2037(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 10;
    for (int x : xs) acc = (acc * 124) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker2038 {
 public:
  explicit Worker2038(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 20;
    for (int x : xs) acc = (acc * 20) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 8); }
 private:
  int id_;
};

class Worker2039 {
 public:
  explicit Worker2039(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 35) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker2040 {
 public:
  explicit Worker2040(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 91;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker2041 {
 public:
  explicit Worker2041(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 22) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker2042 {
 public:
  explicit Worker2042(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 43;
    for (int x : xs) acc = (acc * 64) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker2043 {
 public:
  explicit Worker2043(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 30;
    for (int x : xs) acc = (acc * 71) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker2044 {
 public:
  explicit Worker2044(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 23;
    for (int x : xs) acc = (acc * 96) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker2045 {
 public:
  explicit Worker2045(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 73) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker2046 {
 public:
  explicit Worker2046(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 58;
    for (int x : xs) acc = (acc * 115) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker2047 {
 public:
  explicit Worker2047(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 36) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker2048 {
 public:
  explicit Worker2048(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 71;
    for (int x : xs) acc = (acc * 113) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker2049 {
 public:
  explicit Worker2049(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 83;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker2050 {
 public:
  explicit Worker2050(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 93;
    for (int x : xs) acc = (acc * 32) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 2); }
 private:
  int id_;
};

class Worker2051 {
 public:
  explicit Worker2051(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 50;
    for (int x : xs) acc = (acc * 26) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 4); }
 private:
  int id_;
};

class Worker2052 {
 public:
  explicit Worker2052(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 2;
    for (int x : xs) acc = (acc * 42) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker2053 {
 public:
  explicit Worker2053(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 47;
    for (int x : xs) acc = (acc * 24) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker2054 {
 public:
  explicit Worker2054(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 84) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker2055 {
 public:
  explicit Worker2055(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 77;
    for (int x : xs) acc = (acc * 116) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker2056 {
 public:
  explicit Worker2056(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 27;
    for (int x : xs) acc = (acc * 82) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 9); }
 private:
  int id_;
};

class Worker2057 {
 public:
  explicit Worker2057(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 28;
    for (int x : xs) acc = (acc * 126) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker2058 {
 public:
  explicit Worker2058(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 18;
    for (int x : xs) acc = (acc * 98) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 6); }
 private:
  int id_;
};

class Worker2059 {
 public:
  explicit Worker2059(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 67;
    for (int x : xs) acc = (acc * 59) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};

class Worker2060 {
 public:
  explicit Worker2060(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 86;
    for (int x : xs) acc = (acc * 131) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 3); }
 private:
  int id_;
};

class Worker2061 {
 public:
  explicit Worker2061(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 66;
    for (int x : xs) acc = (acc * 8) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 7); }
 private:
  int id_;
};

class Worker2062 {
 public:
  explicit Worker2062(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 57;
    for (int x : xs) acc = (acc * 50) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 1); }
 private:
  int id_;
};

class Worker2063 {
 public:
  explicit Worker2063(int id) : id_(id) {}
  std::int64_t process(const std::vector<int>& xs) const {
    std::int64_t acc = 70;
    for (int x : xs) acc = (acc * 78) + x * id_;
    return acc & 0x7fffffffffffffffLL;
  }
  std::string label() const { return std::string("worker-") + std::to_string(id_ * 5); }
 private:
  int id_;
};
}  // namespace tdz
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
