# テスト計画書

## 1. テスト方針

変更時はローカルでコンパイルと基本動作を確認し、Pull RequestではGitHub Actionsのbuildジョブを通過させる。`main`へのpushでは、ビルド成功後にのみAzure VMへデプロイする。

## 2. テスト項目

| ID | 対象 | 確認内容 | 判定 |
| --- | --- | --- | --- |
| T-01 | `calc.c` | `gcc -Wall -Wextra -Werror` でビルドできる | エラーなし |
| T-02 | `test.c` | ビルド後に実行し、`Hello from C CGI!` を出力する | 文字列一致 |
| T-03 | 入力画面 | `/` が表示され、A/B入力欄が存在する | 目視確認 |
| T-04 | CGI | GETアクセス時にHTMLレスポンスを返す | ブラウザ確認 |
| T-05 | CGI | `REQUEST_METHOD` と `QUERY_STRING` が表示される | 値一致 |
| T-06 | デプロイ | 静的ファイルとCGIが所定の配置先に存在する | SSHで確認 |
| T-07 | CI/CD | `main`へのpushでビルド後にデプロイされる | Actions確認 |

## 3. ローカル確認コマンド

```bash
gcc -Wall -Wextra -Werror src/calc.c -o /tmp/calc.cgi
gcc -Wall -Wextra -Werror src/test.c -o /tmp/test.cgi
/tmp/test.cgi | grep -q "Hello from C CGI!"
```

## 4. 未実装機能のテスト追加方針

計算処理を実装した時点で、正常系だけでなく未入力、数値以外、境界値、ゼロ除算、長いクエリ文字列を追加する。