#!/bin/bash
set -e

echo "=== [LOCAL] ビルド & デプロイ開始 ==="

# 1. 静的HTMLの配置
cp -r public/* /var/www/html/

# 2. C言語コードのコンパイルと配置
gcc src/calc.c -o calc.cgi
mv calc.cgi /usr/lib/cgi-bin/
chmod +x /usr/lib/cgi-bin/calc.cgi

echo "=== [LOCAL] デプロイ完了 ==="
