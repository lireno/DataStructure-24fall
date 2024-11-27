# 指定编译器
CXX = g++
# 编译选项
CXXFLAGS = -Wall -Wextra -std=c++11
# 目标可执行文件名
TARGET = main
# 源文件
SRCS = main.cpp

# 默认目标
all: $(TARGET)

# 链接目标可执行文件
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 清理生成的文件
clean:
	rm -f $(TARGET)

# 声明伪目标
.PHONY: all clean
