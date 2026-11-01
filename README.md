# azure\_c\_calc-app

## Directory structure

```
~/Desktop/dev/azure_c_calc-app/           # リポジトリルート
├── .github/
│   └── PULL_REQUEST_TEMPLATE.md      # PRテンプレート
├── .gitignore                         # ビルド生成物（*.cgi, *.o）を除外
├── README.md                          # プロジェクト概要
├── deploy.sh                          # 自動デプロイスクリプト（後述）
│
├── public/                            # 静的コンテンツ（HTML / CSS / JS）
│   └── index.html                    # フォーム画面 (Sprint 2 タスク1)
│
└── src/                               # C言語CGIソースコード
    ├── test.c                         # テスト用CGI (Sprint 1)
    └── calc.c                         # 計算用CGI (Sprint 2 タスク2~)
```

| 開発リポジトリ（\~/Desktop/dev/azure\_c\_calc-app/） |      コンパイル / デプロイ     |    Apache側の配置先（システム領域）    |
| :-----------------------------------------: | :-------------------: | :-----------------------: |
|              public/index.html              |       そのままコピー ➔       |  /var/www/html/index.html |
|                  src/calc.c                 | gcc でビルド (calc.cgi) ➔ | /usr/lib/cgi-bin/calc.cgi |

<br />

## コンパイルスクリプト

```
cd ~/Desktop/dev/azure_c_calc-app/src
gcc calc.c -o calc.cgi
ls -l calc.cgi
```

## デプロイスクリプト

```
# 1. コンパイルしたバイナリを CGI ディレクトリへコピー
sudo cp calc.cgi /usr/lib/cgi-bin/

# 2. 実行権限を付与
sudo chmod +x /usr/lib/cgi-bin/calc.cgi

# 3. QUERY_STRING 環境変数を渡してコマンドラインテストを実行
QUERY_STRING="a=10&b=20" /usr/lib/cgi-bin/calc.cgi
```

### 実行権限の付与と使用方法

```[Bash]
chmod +x deploy.sh
./deploy.sh
```

## ドキュメント

* [外部設計書](docs/external-design.md): 利用者向け機能、画面、システム構成

* [内部設計書](docs/internal-design.md): ソース構成、処理、ビルド、CI/CD

* [CGIインターフェース仕様書](docs/api-spec.md): `calc.cgi` の入出力仕様

* [テスト計画書](docs/test-plan.md): テスト項目と確認コマンド

* [運用・デプロイ手順書](docs/operations.md): Azure VMとGitHub Actionsの運用手順
