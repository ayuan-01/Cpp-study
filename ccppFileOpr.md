# C语言文件操作

## 通用文件读写

```c
#include <stdio>

#defile FILENAME "./fileTest"

int main() 
{
    FILE* f;
    f = fopen(FILENAME， a+);
    
    // 读写字符
    fgetc(f);
    fputc('a', f);
    
    // 按行读写
    char s[] = "Hello world!"
    fgets(s, sizeof(s), f);
    fputs(s, f);
    
    // 按块读写
    fread(s, sizeof(s[0]), sizeof(s), s);
    fwrite(s, sizeof(s[0]), sizeof(s), s);
    
    // 文件指针位置控制
    /**
     * whence: 
     * SEEK_SET：文件开头
	 * SEEK_CUR：当前位置
	 * SEEK_END：文件末尾
     */
    int offset = 0;
    int whence = SEEK_CUR；
    fseek(f, offset, whence); 		// 移动文件指针
    ftell(f); 						// 获取当前指针位置
    rewind(f); 						// 回到文件开头
    
    fclose(FILENAME);
    return 0;
}
```

## 标准输入输出

```c
#include <stdio.h>

/**
 * stdin  : FILE *
 * stdout : FILE *
 * stderr : FILE *
 */
int main() 
{
    // 按字符读取
    getchar();
    fgetc(stdin);           
    
    // 按行读取
    char buf[50];
	fgets(buf, sizeof(buf), stdin);
    
    // 格式化读取
    int num;
    int scanf("d%", &num);	//会自动跳过空格、换行等分隔符（除%c外）。
    
    
    // 按字符输出
    putchar('A');
    fputc(c, stdout);
    
    // 按行/字符串输出
    puts("Hello World");
    
	// 格式化输出
    printf("结果是: %d\n", 123);
    fprintf(stderr, "错误: 无法打开文件\n");
    
    return 0;
}
```

# C++文件操作

1. C++ 提供了三种文件流类：

   - `ifstream`- 用于文件输入（读取）
   - `ofstream`- 用于文件输出（写入）
   - `fstream`- 可用于输入和输出

2. 文件打开模式

|   模式标志    |                描述                |
| :-----------: | :--------------------------------: |
|   `ios::in`   |          打开文件用于读取          |
|  `ios::out`   |          打开文件用于写入          |
|  `ios::app`   | 追加模式，所有写入都追加到文件末尾 |
|  `ios::ate`   |      打开文件后定位到文件末尾      |
| `ios::trunc`  |      如果文件已存在则清空内容      |
| `ios::binary` |        以二进制模式打开文件        |

```cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include <filesystem>
#include <locale>
using namespace std;

struct Person {
    char name[50];
    int age;
};

int mian() 
{
    // 打开文件
    ifstream inFile("input.txt");  // 打开文件用于读取
    if (!inFile) {
        cerr << "无法打开文件!" << endl;
        return 1;
    }
	ofstream outFile("output.txt"); // 打开文件用于写入
    
    fstream file;
	file.open("data.txt", ios::in | ios::out); // 可读可写
    
    // 读取文件内容
    string line;
    while (getline(inFile, line)) {
    	cout << line << endl;
    }
	string word;
    while (inFile >> word) {
        cout << word << endl;
    }
    char ch;
    while (inFile.get(ch)) {
        cout << ch;
    }
    
    // 写入文件内容
    if (outFile) {
        outFile << "这是第一行" << endl;
        outFile << "这是第二行" << endl;
        outFile << 123 << " " << 3.14 << endl;
    }
    
    // 文件位置指针
    streampos pos = inFile.tellg();		// 获取当前位置
    inFile.seekg(0, ios::beg);			// 移动到文件开头
    inFile.seekg(0, ios::end);			// 移动到文件末尾
    inFile.seekg(100, ios::beg);		// 移动到第100个字节处
    
    // 二进制文件操作
    Person p = {"张三", 25};
    ofstream outFile("person.dat", ios::binary);
    outFile.write(reinterpret_cast<char*>(&p), sizeof(Person));
    
    ifstream inFile("person.dat", ios::binary);
    Person p2;
    inFile.read(reinterpret_cast<char*>(&p2), sizeof(Person));
    
    // 关闭文件
    inFile.close();
	outFile.close();    
    
	return 0;
}
```

## 临时文件

```cpp
#include <filesystem>
namespace fs = std::filesystem;

fs::path temp_path = fs::temp_directory_path() / "tempfile.txt";
ofstream tempFile(temp_path);
/*************************************************************************************************/
#include <fstream>
#include <iostream>

bool copyFile(const std::string& src, const std::string& dest) {
    std::ifstream in(src, std::ios::binary);
    std::ofstream out(dest, std::ios::binary);
    
    if (!in || !out) {
        return false;
    }
    
    out << in.rdbuf();
    return true;
}

int main() {
    if (copyFile("source.txt", "destination.txt")) {
        std::cout << "文件复制成功" << std::endl;
    } else {
        std::cerr << "文件复制失败" << std::endl;
    }
    return 0;
}
```

`out << in.rdbuf();`这行代码的意思是：将输入文件流 `in`的整个缓冲区内容直接输出到输出文件流 `out`。这是一种非常高效的文件复制方式。
