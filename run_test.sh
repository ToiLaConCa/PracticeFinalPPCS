#!/usr/bin/env bash
# Script tiện ích biên dịch và chạy nhanh bài tập C++ cho môn PPCS
set -e

if [ -z "$1" ]; then
    echo "Sử dụng: ./run_test.sh <duong_dan_file_cpp>"
    echo "Ví dụ:   ./run_test.sh Day01_OOP_Inheritance/Bai1_SmartHome_Device.cpp"
    exit 1
fi

FILE_CPP="$1"

if [ ! -f "$FILE_CPP" ]; then
    echo "❌ Lỗi: Không tìm thấy tệp '$FILE_CPP'"
    exit 1
fi

BIN_OUTPUT="/tmp/ppcs_test_bin"

echo "🔨 Đang biên dịch: $FILE_CPP ..."
g++ -std=c++17 -Wall -Wextra "$FILE_CPP" -o "$BIN_OUTPUT"

echo "🚀 Đang thực thi kết quả kiểm thử:"
echo "---------------------------------------------------------"
"$BIN_OUTPUT"
echo "---------------------------------------------------------"
echo "✅ Thực thi hoàn tất!"
rm -f "$BIN_OUTPUT"
