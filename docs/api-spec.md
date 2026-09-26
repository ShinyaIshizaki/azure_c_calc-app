# CGIインターフェース仕様書

## 1. `calc.cgi`

| 項目 | 内容 |
| --- | --- |
| パス | `/cgi-bin/calc.cgi` |
| メソッド | GET |
| リクエスト形式 | Query String |
| 成功レスポンス | HTML出力 |
| Content-Type | `text/html; charset=utf-8` |

## 2. リクエスト例

```text
GET /cgi-bin/calc.cgi?a=10&b=20 HTTP/1.1
```

## 3. 環境変数

| 環境変数 | 用途 | 現行処理 |
| --- | --- | --- |
| `REQUEST_METHOD` | HTTPメソッド | HTMLへ表示 |
| `QUERY_STRING` | `?` 以降の生データ | HTMLへ表示 |

## 4. レスポンス例

```html
<p><strong>リクエストメソッド:</strong> <code>GET</code></p>
<p><strong>受信した生データ (QUERY_STRING):</strong> <code>a=10&amp;b=20</code></p>
```

## 5. 今後の拡張

計算APIへ拡張する際は、次を仕様確定する。

- `a` と `b` の必須・任意
- 整数または小数の許容範囲
- 演算子の指定方法
- 不正値、未入力、オーバーフロー、ゼロ除算のエラー表示
- HTMLエスケープまたは安全な値出力