# 運用・デプロイ手順書

## 1. 通常の開発フロー

1. ローカルでソースを変更する。
2. ローカルのビルド・テストを実行する。
3. Pull Requestを作成し、GitHub Actionsのbuildジョブを確認する。
4. `main`へマージまたはpushする。
5. GitHub ActionsのdeployジョブとAzure VM上の表示を確認する。

## 2. 必要なAzure VM環境

- Linux VM
- Apache HTTP Server
- CGI実行設定
- gcc
- SSH接続
- `/var/www/html/`
- `/usr/lib/cgi-bin/`

## 3. GitHub Actions Secrets

リポジトリの Settings → Secrets and variables → Actions に次を登録する。

```text
AZURE_VM_HOST
AZURE_VM_USER
AZURE_VM_SSH_KEY
```

SSH秘密鍵はファイル内容をSecretへ登録し、ソースコードやログへ出力しない。

## 4. Azure VM上での手動デプロイ

```bash
cd ~/azure_c_calc-app
chmod +x deploy.sh
./deploy.sh
```

このスクリプトはローカル環境ではなく、Apacheのシステム配置先が存在するAzure VM上で実行する。

## 5. デプロイ後確認

1. `http://<VM_HOST>/` を開く。
2. A/Bを入力して送信する。
3. CGI結果画面が表示されることを確認する。
4. GitHub Actionsのジョブログに秘密情報が出ていないことを確認する。

## 6. 障害時確認

- Actionsのbuild失敗: gccのエラーとソース変更を確認する。
- SSH接続失敗: Secret、公開鍵、NSGの22番ポート、VMの起動状態を確認する。
- Apache表示失敗: Apacheの稼働状態、CGI設定、ファイル権限を確認する。
- `cp`失敗: `/var/www/html` の存在を確認する。