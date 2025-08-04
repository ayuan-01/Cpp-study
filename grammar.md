# C++基本语法

- 变量，数据类型

```cpp
bool flag = true;
```

- 命名空间的概念

​		最常用的是标准库的命名空间了。在C++项目中，同一个函数名称可能会在不同的文件中多次出现，为了解决这种命名冲突，就有了命名空间的概念。
​		std是C++标准库的命名空间，是一个庞大的工具集。

```cpp
// 使用std命名空间的内容
std::string

using std::cout;
cout << "This is a message." << endl;

using namespace std; 
cout << greeting << "World!" << endl;
vector<int> numbers = {1, 2, 3};
```

- 常用头文件

```cpp
<iostream>	输入输出：cin, cout
<string>	字符串类 std::string
<vector>	向量容器（动态数组）
<algorithm>	排序、查找、最大最小值等算法
<cmath>	数学函数：pow, sqrt, sin, 等
<cstdlib>	随机数生成、内存分配等
<ctime>	时间函数如 time, clock 等
<fstream>	文件流：读写文件
```

- 输入输出操作

```c
std::cin >> age;
std::cout << "Age: " << age << std::endl;	/* 表明std命名空间中的cout队形 */

int x = 10;

class A {
public:
    static int x;
};
int A::x = 20;

std::cout << x;      // 全局的x
std::cout << A::x;   // A类中的x
```

1. **::**表示作用域解析运算符，用于指明空间或者类的作用域。

2. **cout**对象表述标准输出流。

3. **cin**对象表示标准输入流。

引用: 引用就是某个变量的**别名**，它**并不独立地占用内存**，而是直接**绑定到另一个已有的变量**。你对引用做的任何操作，实际上就是对原变量的操作。

```cpp
int a = 10;
int &x = a;

void addOne(int& x) {
    x += 1;
}

int& getRef(int& x) {
    return x;
}

// 遍历容器中的每一个元素
// vec 是一个容器，例如 std::vector<int> vec = {1, 2, 3};
// n 是 vec 中的一个元素。
// int& 表示 n 是对该元素的 引用（reference），这样你可以直接修改容器中的元素。
for (int& n : vec) {
    n += 1; // 修改 vec 中的元素
}

```

## 常用关键字，数据类型，运算符

关键字

```cpp
/* 类与面向对象 */
class	定义类
struct	定义结构体（默认 public）
public	公有访问权限
private	私有访问权限（类默认）
protected	受保护访问权限
virtual	虚函数（支持多态）
override	明确重写父类虚函数（C++11）
final	禁止子类重写（C++11）
this	当前对象指针
new	动态分配内存
delete	释放动态内存
friend	友元函数/类
explicit	禁止构造函数隐式转换
inline	请求内联函数
    
/* 模板和泛型编程 */
template	模板定义
typename	表示类型参数
constexpr	编译期常量（C++11）

/* 类型 */
int*	指针类型
int&	引用类型
int[]	数组类型
std::string	字符串（C++类）
```

- new

  核心功能是在堆上分配内存，并返回指向该内存的一个指针。销毁使用delete。主要功能有两个：
  1. 为单个对象分配内存。
  2. 为数组分配内存。
```cpp
// 为单个对象分配内存
pointer = new TypeName;
pointer = new TypeName(initial_value);

// new运算符会首先向操作系统申请一块足够存储`TypeName`类型的内存。如果内存分配成功会自动调用这个对`TypeName`类型的构造函数，在这块新分配的内存中初始化一个对象。

// 基于此，接下来介绍一下什么是构造函数
// 对于一个类class Person，在该类型的对创建时（new）构造函数会被自动调用，为该对象赋初值。
// 构造函数可重载（参数列表不同即可）
// 构造函数名必须与类名一致
/** 
 * pref: 构造函数举例
 */
#include <iostream>
#include <string>

class Person {
public:
    // 默认构造函数（无参数）
    Person() {
        name = "Unknown";
        age = 0;
        std::cout << "Default constructor called." << std::endl;
    }

    // 带参数的构造函数
    Person(std::string n, int a) {
        name = n;
        age = a;
        std::cout << "Parameterized constructor called." << std::endl;
    }

    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

private:
    std::string name;
    int age;
};

int main() {
    Person p1;             // 调用默认构造函数
    Person p2("Alice", 30); // 调用带参数的构造函数

    p1.display();
    p2.display();

    return 0;
}
// 分配数组
int* arr = new int[10]; // 分配并默认初始化10个int
delete[] arr;           // 正确释放数组

// 自动计算大小
int* p = new int;
```

- new和mellocde区别

1. new可以自动计算内存大小
2. new可以自动调用构造函数，delete可以自动调用析构函数
3. new返回正确类型的指针，无需强制类型转换。

## 分支结构

同C语言

## 数组，字符串，指针，函数，结构体

数组

```cpp
/* 首先兼容C语言的数组操作 */
#include <array>
#include <vector>

// std::array：固定长度
std::array<int, 5> arr = {1,2,3,4,5};

// std::vector：动态数组
std::vector<int> vec = {1,2,3};
vec.push_back(4);
```

字符串相关操作

```c
// 构造方式
std::string s1;                    // 空字符串
std::string s2("hello");          // C 字符串构造
std::string s3(s2);               // 拷贝构造
std::string s4(s2, 1, 2);         // 从 s2[1] 开始取 2 个字符
std::string s5(5, 'x');           // “xxxxx”
// 赋值
s1 = "world";
s1.assign("abc", 3);
s1 += "!";
s1.append(s2);
//

std::string s = "Hi"; 	 创建字符串	
s.length() or s.size()	 获取长度	
s[0], s.at(1)			 访问某个字符	
s += " world";		     拼接字符串	
s.substr(0, 3)			 子串		
s.find("ice")			 查找子串	
s1 == s2, s1 < s2		 比较字符串	
s.begin() s.end()
    
.clear()：空字符串，但不改变 capacity。
.insert(...)：在指定位置插入字符或子串。
.erase(pos, len) 或 .erase(it1, it2)：删除字符或范围。
.replace(...)：替换指定范围为其他内容。
.push_back(c) 与 .append(...)：末尾添加字符或子串
```

指针

```cpp
int* p = nullptr;  // 空指针，避免野指针
int arr[3] = {1, 2, 3};
int* p = arr;      // 等价于 int* p = &arr[0];
```

函数

```cpp
// 内联函数 inline
// 建议编译器把函数展开，适合小函数，减少函数调用的损耗

// 函数重载
就是作用域内允许多个重名函数出现，但参数列表不同。
```

结构体

```cpp
std::vector<Student> v;
v.push_back({"Mike", 18, 75.0});
v.push_back(stu1);
```

# 面向对象

## 封装

- 封装是将数据和操作数据的方法捆绑到一个单元中。对外部隐藏对象的内部实现细节，仅通过有限受控的接口与外部进行交互。

- 通过访问限定符实现封装

  - public、private、protected

  ```cpp
  // public: 任何地方都可以访问。类的内部、子类、类的外部（通过对象）都可以直接访问public成员。
  // private: 只能在类的内部访问。子类和类的外部都无法直接访问private成员。
  // protected: 只能在类的内部和其派生类（子类）中访问。类的外部无法访问。为继承设计的“半私有”成员。
  
  #include <iostream>
  #include <string>
  
  class BankAccount {
  // --- 私有部分：数据和内部实现 ---
  private:
      // 数据成员（属性）被设为private，以保护它们
      std::string ownerName;
      double balance;
      int accountNumber;
  
      // 一个私有辅助函数，用于内部记录日志，外部不需要知道
      void logTransaction(const std::string& action, double amount) {
          std::cout << "[LOG] Account " << accountNumber << ": " << action << " of " << amount << std::endl;
      }
  
  
  // --- 公共部分：对外接口 ---
  public:
      // 构造函数：用于创建和初始化对象
      BankAccount(std::string name, int accNum, double initialDeposit) {
          ownerName = name;
          accountNumber = accNum;
          // 即使是初始存款，也通过deposit方法，以保证逻辑统一
          balance = 0; // 先设为0
          deposit(initialDeposit); // 再调用存款方法
          std::cout << "Account for " << ownerName << " created successfully." << std::endl;
      }
  
      // 公共接口：存款
      void deposit(double amount) {
          if (amount > 0) {
              balance += amount;
              logTransaction("Deposit", amount);
          } else {
              std::cout << "Error: Deposit amount must be positive." << std::endl;
          }
      }
  
      // 公共接口：取款
      void withdraw(double amount) {
          if (amount <= 0) {
              std::cout << "Error: Withdrawal amount must be positive." << std::endl;
              return;
          }
          if (amount > balance) {
              std::cout << "Error: Insufficient funds. Withdrawal failed." << std::endl;
          } else {
              balance -= amount;
              logTransaction("Withdrawal", amount);
          }
      }
  
      // 公共接口：查询余额
      // 注意：它返回一个副本，而不是balance的引用，防止外部通过引用修改
      double getBalance() const {
          return balance;
      }
      
      // 公共接口：显示账户信息
      void displayInfo() const {
          std::cout << "------------------------" << std::endl;
          std::cout << "Account Holder: " << ownerName << std::endl;
          std::cout << "Account Number: " << accountNumber << std::endl;
          std::cout << "Current Balance: " << balance << std::endl;
          std::cout << "------------------------" << std::endl;
      }
  }; // 类定义结束
  
  int main() {
      // 创建一个BankAccount对象
      BankAccount myAccount("Alice", 12345678, 1000.0);
      myAccount.displayInfo();
  
      // 通过公共接口进行操作
      std::cout << "\n--- Attempting to deposit 500 ---" << std::endl;
      myAccount.deposit(500.0);
      myAccount.displayInfo();
  
      std::cout << "\n--- Attempting to withdraw 200 ---" << std::endl;
      myAccount.withdraw(200.0);
      myAccount.displayInfo();
  
      std::cout << "\n--- Attempting to withdraw 2000 (insufficient funds) ---" << std::endl;
      myAccount.withdraw(2000.0);
      myAccount.displayInfo();
  
      // --- 以下代码是错误的，无法通过编译，体现了封装的安全性 ---
      // myAccount.balance = 1000000; // 错误！'double BankAccount::balance' is private
      // myAccount.accountNumber = 999; // 错误！'int BankAccount::accountNumber' is private
      // myAccount.logTransaction("Hacking", 0); // 错误！'void BankAccount::logTransaction(...)' is private
  
      return 0;
  }
  ```

  - const关键字

    void displayInfo() const; 表示这个函数是只读的，不会修改对象的内容。

  - 构造函数的一种写法

  ```cpp
  class MyClass {
  private:
      int secret;
  public:
      MyClass(int s) : secret(s) {}
      // 声明友元函数
      friend void showSecret(const MyClass& obj);
  };
  // secret(s)表示将成员secret属性赋值为s
  ```


### 友元

```cpp
// 友元函数：非成员函数可以访问类的私有成员
class MyClass {
private:
    int secret;
public:
    MyClass(int s) : secret(s) {}
    // 声明友元函数
    friend void showSecret(const MyClass& obj);
};
 
// 友元函数定义（可以访问 MyClass 的私有成员）
void showSecret(const MyClass& obj) {
    std::cout << "Secret: " << obj.secret << std::endl;
}
 
int main() {
    MyClass obj(42);
    showSecret(obj); // 输出: Secret: 42
    return 0;
}

// 友元类：一个类的所有成员函数能够访问另一个类的所有私有成员
class SecretHolder {
private:
    int data;
public:
    SecretHolder(int d) : data(d) {}
    // 声明友元类
    friend class FriendClass;
};
 
class FriendClass {
public:
    void accessSecret(const SecretHolder& holder) {
        std::cout << "Data: " << holder.data << std::endl; // 合法访问
    }
};
 
int main() {
    SecretHolder holder(100);
    FriendClass friendObj;
    friendObj.accessSecret(holder); // 输出: Data: 100
    return 0;
}
// 友元成员函数：某个类的成员函数可以访问另一个类的私有成员
class A {
private:
    int x;
public:
    A(int val) : x(val) {}
    // 声明类 B 的成员函数为友元
    friend void B::printX(const A& obj);
};
 
class B {
public:
    void printX(const A& obj) {
        std::cout << "A::x = " << obj.x << std::endl; // 合法访问
    }
};
 
int main() {
    A a(10);
    B b;
    b.printX(a); // 输出: A::x = 10
    return 0;
}
```

## 构造函数和析构函数

### 拷贝构造函数

默认构造函数，带参数的构造函数，初始化列表

- 更推荐初始化列表的方式，对于类类型成员，初始化列表是直接调用其构造函数进行初始化；而在构造函数体内赋值，则是先调用默认构造函数创建一个临时对象，然后再用赋值操作符覆盖。前者效率更高。

- 拷贝构造函数

**用于创建一个与现有对象完全相同的新对象**，它的参数是对同类对象的**常量引用const ClassName&**。如果没有定义拷贝构造函数，编译器会生成一个默认的拷贝构造函数，它会进行**浅拷贝**。

### 浅拷贝

危险性：默认的浅拷贝在拷贝默认的指针成员的时候，只是拷贝一个指针，指针的内容不会被拷贝，这会导致调用析构函数的时候可能会重复释放同一块内存。

```cpp
#include <cstring>
class ShallowCopy {
private:
    char* data;
public:
    ShallowCopy(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }
    // ~ShallowCopy() { delete[] data; } // 析构函数，后面会讲

    // 默认拷贝构造函数是浅拷贝，会导致问题
};

void problem_demo() {
    ShallowCopy s1("Hello");
    ShallowCopy s2 = s1; // 调用默认拷贝构造函数，s1.data 和 s2.data 指向同一块内存
    // 当 s1 和 s2 析构时，会尝试 delete[] 同一块内存两次，导致程序崩溃！
}
```

### 深拷贝

当类中包含指针成员或动态分配的资源时，你必须**显式地定义拷贝构造函数**，自己为新对象分配独立的内存并复制内容，这就是**深拷贝**（Deep Copy）。

```cpp
class DeepCopy {
private:
    char* data;
public:
    DeepCopy(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // 显式定义的拷贝构造函数，实现深拷贝
    DeepCopy(const DeepCopy& other) {
        data = new char[strlen(other.data) + 1];  // 1. 为新对象分配新内存
        strcpy(data, other.data);                 // 2. 复制内容
        std::cout << "深拷贝构造函数被调用" << std::endl;
    }

    ~DeepCopy() {
        delete[] data;
    }
};
```

### 析构函数

释放资源、自动调用、不能重载、先构造的对象后析构，后构造的对象先析构。

如果在构造函数中使用了**new**，那么就需要在析构函数中显式定义一个析构函数来释放这些资源。如果不定义，那么默认的析构函数只会消除指针本身，而不会释放指针指向的内存。

`delete[]`操作符专门用于释放`new[]`创建的动态数组。

| 操作     | 创建单个对象 | 创建对象数组     |
| -------- | ------------ | ---------------- |
| 分配内存 | `new int`    | `new int[10]`    |
| 释放内存 | `delete p`   | `delete[] p_arr` |

```cpp
#include <iostream>
#include <cstring>

class ResourceHolder {
private:
    char* buffer;
    int size;

public:
    // 构造函数：获取资源
    ResourceHolder(int s) : size(s) {
        buffer = new char[size]; // 动态分配内存
        std::cout << "构造函数: 分配了 " << size << " 字节的内存" << std::endl;
    }

    // 析构函数：释放资源
    ~ResourceHolder() {
        delete[] buffer; // 释放动态分配的内存
        std::cout << "析构函数: 释放了内存" << std::endl;
        buffer = nullptr; // 好习惯，避免悬垂指针
    }

    void doSomething() {
        std::cout << "正在使用资源..." << std::endl;
    }
};

void createAndDestroy() {
    std::cout << "进入 createAndDestroy 函数" << std::endl;
    ResourceHolder holder(1024); // 创建对象，调用构造函数
    holder.doSomething();
    std::cout << "即将离开 createAndDestroy 函数" << std::endl;
} // 离开作用域，holder 对象被销毁，自动调用析构函数

int main() {
    createAndDestroy();
    std::cout << "已回到 main 函数" << std::endl;
    return 0;
}
```



### 类对象作为类成员和静态成员

关键点是类对象的成员初始化列表。成员对象的构造顺序由它们**在类中的声明顺序决定**

```cpp
#include <iostream>
#include <string>

// 部件类：引擎
class Engine {
public:
    Engine(const std::string& type) : m_type(type) {
        std::cout << "Engine " << m_type << " constructed." << std::endl;
    }
    void start() {
        std::cout << "Engine " << m_type << " is starting... Vroom!" << std::endl;
    }
    ~Engine() {
        std::cout << "Engine " << m_type << " destructed." << std::endl;
    }
private:
    std::string m_type;
};

// 部件类：轮子
class Wheel {
public:
    Wheel(int id) : m_id(id) {
        std::cout << "Wheel " << m_id << " constructed." << std::endl;
    }
    void rotate() {
        std::cout << "Wheel " << m_id << " is rotating." << std::endl;
    }
    ~Wheel() {
        std::cout << "Wheel " << m_id << " destructed." << std::endl;
    }
private:
    int m_id;
};

// 组合类：汽车
class Car {
public:
    Car(const std::string& engineType)
        // 关键点：成员初始化列表
        : m_engine(engineType), // 调用 Engine 的构造函数
          m_wheel1(1),          // 调用 Wheel 的构造函数
          m_wheel2(2),
          m_wheel3(3),
          m_wheel4(4) {
        std::cout << "Car constructed." << std::endl;
    }

    void drive() {
        std::cout << "Car is about to drive." << std::endl;
        m_engine.start();
        m_wheel1.rotate();
        m_wheel2.rotate();
        m_wheel3.rotate();
        m_wheel4.rotate();
    }

    ~Car() {
        std::cout << "Car destructed." << std::endl;
    }

private:
    // Car 对象“拥有”这些对象
    Engine m_engine;
    Wheel m_wheel1;
    Wheel m_wheel2;
    Wheel m_wheel3;
    Wheel m_wheel4;
};

int main() {
    std::cout << "--- Creating a Car ---" << std::endl;
    Car myCar("V8");
    std::cout << "\n--- Driving the Car ---" << std::endl;
    myCar.drive();
    std::cout << "\n--- Destroying the Car ---" << std::endl;
    // myCar 离开作用域，析构函数被自动调用
    return 0;
}
```

- 静态成员

所有创建的对象都会自动拥有类定义中的静态成员变量

```cpp
// 构造函数
BankAccount(const std::string& name, double initialBalance)
    : m_ownerName(name), m_balance(initialBalance) {
    // 每次创建新账户，总账户数和总存款额都增加
    s_totalAccounts++;
    s_totalBalance += initialBalance;
    std::cout << "Account for " << m_ownerName << " created. Balance: " << m_balance << std::endl;
}
private:
    // 普通成员变量：每个对象都有一份自己的拷贝
    std::string m_ownerName;
    double m_balance;

    // 静态成员变量：所有对象共享同一份
    static int s_totalAccounts;
    static double s_totalBalance;
};
```

## 成员变量与成员函数分开存储

核心思想是数据与行为的分离。

以一段代码为例，图解面向对象的内存模型。类成员函数存放在.text区域，非静态成员变量放在栈区，静态成员变量放在静态数据区。

```cpp
#include <iostream>

class MyClass {
public:
    // 1. 非静态成员变量
    int mA;
    int mB;

    // 2. 静态成员变量
    static int mC; // 声明，不占用对象内存

    // 3. 非静态成员函数
    void show() {
        std::cout << "mA: " << mA << ", mB: " << mB << std::endl;
    }

    // 4. 静态成员函数
    static void staticShow() {
        std::cout << "Static member mC: " << mC << std::endl;
    }
};

// 静态成员变量的定义（分配内存）
int MyClass::mC = 100;

int main() {
    std::cout << "Size of MyClass: " << sizeof(MyClass) << " bytes" << std::endl; // 输出多少？
    MyClass obj1;
    MyClass obj2;

    obj1.mA = 10;
    obj1.mB = 20;
    obj2.mA = 30;
    obj2.mB = 40;

    obj1.show(); // 输出 mA: 10, mB: 20
    obj2.show(); // 输出 mA: 30, mB: 40

    MyClass::staticShow(); // 输出 Static member mC: 100

    return 0;
}
/*****************************************************************************
+---------------------------+
|         代码区            |
| +-----------------------+ |
| | void MyClass::show()  | |  <-- 所有对象共享
| +-----------------------+ |
| | void MyClass::stati.. | |  <-- 所有对象共享
| +-----------------------+ |
+---------------------------+
+---------------------------+
|        静态数据区         |
| +-----------------------+ |
| | MyClass::mC (100)     | |  <-- 全局唯一
| +-----------------------+ |
+---------------------------+
+---------------------------+
|          栈区             |
| +-----------------------+ |
| | obj1                  | |
| |   mA: 10              | |
| |   mB: 20              | |
| +-----------------------+ |
| | obj2                  | |
| |   mA: 30              | |
| |   mB: 40              | |
| +-----------------------+ |
+---------------------------+
*************************************************************************************/
```

| 特性                   | 成员变量                                                     | 成员函数                                                     |
| :--------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| **存储位置**           | **非静态**: 存储在对象内部 (栈/堆) **静态**: 存储在静态数据区 | **所有函数**: 存储在代码区                                   |
| **拷贝数量**           | **非静态**: 每个对象一份 **静态**: 整个类一份                | **所有函数**: 整个类一份，所有对象共享                       |
| **与对象关系**         | **非静态**: 定义了对象的“状态” **静态**: 定义了类的“全局状态” | 定义了对象的“行为”或“操作逻辑”                               |
| **访问机制**           | 直接通过对象地址访问                                         | **非静态**: 通过 `this` 指针隐式访问对象成员 **静态**: 无 `this` 指针，不能访问非静态成员 |
| **对 `sizeof` 的影响** | **非静态**: 直接决定对象大小 **静态**: 无影响                | **所有函数**: 无影响                                         |

### this指针

既然成员函数在内存中只有一份，那调用不同对象的成员函数时，函数内部是如何区分要操作哪个对象呢。

当调用一个非静态成员函数时，编译器会隐式地把调用该函数的对象的地址指针作为第一个参数传递进去，这就是`this`指针，类型是`className* const`。obj1.show()在编译器看来更像是show(&obj1)。

```cpp
// 对于 obj1.show()，this 指向 obj1，所以 this->mA 就是 obj1.mA（值为10）。
// 对于 obj2.show()，this 指向 obj2，所以 this->mA 就是 obj2.mA（值为30）。
```

### 静态成员函数

在 C++ 中，**静态成员函数（Static Member Function）** 是类的成员函数，但它不属于类的某个具体对象，而是属于类本身。静态成员函数可以直接通过类名调用，无需创建类的实例（对象），并且它只能访问类的**静态成员（静态变量或其他静态函数）**，不能直接访问非静态成员（普通变量或普通函数）。

静态成员函数没有 `this` 指针，因此无法访问类的非静态成员（变量或函数），因为非静态成员属于对象实例。

声明周期与类相同，静态成员函数在程序加载时就被初始化，直到程序结束才销毁。

调用：

```cpp
MyClass::StaticFunction();  // 直接通过类名调用
```

### 空指针访问成员函数

核心思想是函数调用并不依赖与对象地址。成员函数是存放在代码区的，使用nullptr调用成员函数是可以调用的，只是传入的this指针是nullptr。

1. 如果成员函数没有涉及到成员变量，可以正常执行。

2. 涉及成员变量时会因为this->mA => nullptr->mA而导致程序崩溃。

3. 类中存在虚函数

   1. 当一个类有虚函数时，编译器会为这个类创建一个隐藏的表，叫做虚函数表`vptr`。这个表存放了所有虚函数的地址。
   2. 对于对象opj，obj->vptr->doSomething()

   ```tex
   a. 通过对象指针 `p` 找到对象本身。
   b. 从对象的内存中读取 `vptr`（虚函数表指针）。
   c. 通过 `vptr` 找到虚函数表。
   d. 在虚函数表中查找 `doSomething` 的地址。
   e. 跳转到该地址执行函数。
   ```

### 虚函数

虚函数是在基类中使用 `virtual` 关键字声明的成员函数。它允许你在派生类中对该函数进行**重写（Override）**，并且当你通过基类的指针或引用来调用该函数时，程序会**动态地**根据指针或引用实际所指向的对象类型，来调用相应派生类中的版本，而不是基类的版本。

核心目的是实现运行时多态，也成为动态绑定，就是用一个统一的接口，去处理多种不同类型的对象。

```cpp
#include <iostream>

// 基类：动物
class Animal {
public:
    // 使用 virtual 关键字声明为虚函数
    virtual void speak() {
        std::cout << "Some generic animal sound!" << std::endl;
    }
};

// 派生类：狗
class Dog : public Animal {
public:
    // 重写 speak 函数 (override关键字是C++11引入的，推荐使用，让意图更清晰)
    void speak() override {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

// 派生类：猫
class Cat : public Animal {
public:
    void speak() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Dog myDog;
    Cat myCat;

    Animal* animalPtr1 = &myDog;
    Animal* animalPtr2 = &myCat;

    std::cout << "Calling speak() via pointers (with virtual):" << std::endl;
    animalPtr1->speak(); // 现在它会正确地叫 "Woof! Woof!"
    animalPtr2->speak(); // 现在它会正确地叫 "Meow!"

    return 0;
}
```

## C++运算符重载

什么是运算符重载：相对于某个class来说，重新定义已有的运算符，使得其工作在我们期待的情况下。例如
```cpp
Vector v1(1, 2), v2(3, 4);
Vector v3 = v1 + v2; // 希望实现向量相加
```
#### 运算符重载的语法：

1. 成员函数的形式
```cpp
// Vector: 返回值
// Vector:: : 表示这是一个成员函数，属于Vector类。
// const Vector& other: 表示一个常量引用，避免拷贝开销，保证只读
Vector Vector::operator+(const Vector& other) const;

class Vector {
public:
    double x, y;
 
    // 构造函数
    Vector(double x = 0, double y = 0) : x(x), y(y) {}
 
    // 重载 + 运算符
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y); // 返回新对象
    }
};

int main() {
    Vector v1(1.0, 2.0);
    Vector v2(3.0, 4.0);
 
    Vector v3 = v1 + v2; // 调用 operator+，结果为 (4.0, 6.0)
 
    std::cout << "v3: (" << v3.x << ", " << v3.y << ")" << std::endl;
    return 0;
}
```
2. 非成员函数的形式
通常使用friend关键字，友元函数。
```cpp
class Vector {
    // ... 其他成员 ...
    friend Vector operator+(const Vector& a, const Vector& b);
};
 
Vector operator+(const Vector& a, const Vector& b) {
    return Vector(a.x + b.x, a.y + b.y);
}
```

#### 常见运算符重载

只要**某个表达式里出现了你自定义的类型，并且用到了某个运算符**，而**这个运算符对该类型没有现成的、可用的实现**，编译器就会去查找**是否存在针对该类型、该运算符的重载函数**。找到了就用，找不到就报错。

```cpp
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) { // 防止自赋值
        x = other.x;
        y = other.y;
    }
    return *this;
}

int& Vector::operator[](int index) {
    if (index == 0) return x;
    else if (index == 1) return y;
    else throw std::out_of_range("Index out of range");
}

// std::ostream& os是输出流对象，如std::cout
std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector& v) {
    is >> v.x >> v.y;
    return is;
}

// 前置 ++
Vector& Vector::operator++() {
    ++x;
    ++y;
    return *this;
}

// 后置 ++（用 int 参数区分）
Vector Vector::operator++(int) {
    Vector temp = *this;
    ++(*this);
    return temp;
}

```

```cpp
// 输入输出流重载
#include <iostream>
struct Vector {
    double x, y;
};

// 输出流重载
std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

// 输入流重载
std::istream& operator>>(std::istream& is, Vector& v) {
    is >> v.x >> v.y;
    return is;
}

int main() {
    Vector v1, v2;

    // 输入
    std::cout << "Enter Vector 1 (x y): ";
    std::cin >> v1; // 例如输入: 1.0 2.0

    std::cout << "Enter Vector 2 (x y): ";
    std::cin >> v2; // 例如输入: 3.0 4.0

    // 输出
    std::cout << "Vector 1: " << v1 << std::endl; // 输出: Vector 1: (1.0, 2.0)
    std::cout << "Vector 2: " << v2 << std::endl; // 输出: Vector 2: (3.0, 4.0)

    return 0;
}
```

