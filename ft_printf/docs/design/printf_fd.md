# printf_fd

## prototype

```c
int printf(int fd, const char *format, ...);
```

## return value

成功時: 出力した文字数。
失敗時: 負の値

## description

フォーマットに基づき、引数を`fd`がさすファイルに出力する。
ふぉーまっとの対応内容については、[requirements.txt](./requirements.md)参照
