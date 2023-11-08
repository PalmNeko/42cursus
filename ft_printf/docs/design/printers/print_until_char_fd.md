# print_until_char

## prototype

```c
int	print_until_char_fd(int fd, const char *str, char c);
```

## return value

* 成功時: 出力した文字数。
* 失敗時: 負の値。

## description

`chr`が現れるか文字列の最後まで表示する。
