# azure_c_calc-app

## Directory structure

```
~/c-web-app/                          # リポジトリルート
├── .github/
│   └── PULL_REQUEST_TEMPLATE.md       # PRテンプレート
├── .gitignore                         # ビルド生成物（*.cgi, *.o）を除外
├── README.md                          # プロジェクト概要
├── deploy.sh                          # 自動デプロイスクリプト（後述）
│
├── public/                            # 静的コンテンツ（HTML / CSS / JS）
│   └── index.html                     # フォーム画面 (Sprint 2 タスク1)
│
└── src/                               # C言語CGIソースコード
    ├── test.c                         # テスト用CGI (Sprint 1)
    └── calc.c                         # 計算用CGI (Sprint 2 タスク2~)
```


|開発リポジトリ（~/c-web-app）|コンパイル / デプロイ|Apache側の配置先（システム領域）|
|:----:|:----:|:----:|
|public/index.html|そのままコピー ➔|/var/www/html/index.html|
|src/calc.c|gcc でビルド (calc.cgi) ➔|/usr/lib/cgi-bin/calc.cgi|
