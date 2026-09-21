#!/bin/bash
set -e

echo "=== ビルド & デプロイ開始 ==="

# 1. 静的ファイルの配置
sudo cp -r public/* /var/www/html/

# 2. C言語コードのコンパイルと配置
gcc src/calc.c -o calc.cgi
sudo mv calc.cgi /usr/lib/cgi-bin/
sudo chmod +x /usr/lib/cgi-bin/calc.cgi

echo "=== デプロイ完了 ==="