# vprintf_fd

## prototype

```c
int vprintf_fd(int fd, const char *format, va_list arg_ptr);
```

## return value

成功時: 出力した文字数。
失敗時: 負の値

## description

フォーマットに基づきva_listの内容を`fd`がさすファイルに出力する。
フォーマットの対応内容については、[requirements.txt](./requirements.md)参照
